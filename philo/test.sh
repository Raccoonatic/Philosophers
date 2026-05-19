#!/bin/bash

# Custom Signature Colors
MINT="\033[1;38;2;55;250;133m"
BLOD="\033[1;38;2;255;0;0m"
GOLD="\033[1;38;2;235;232;52m"
BABY="\033[1;38;2;0;255;247m"
RSET="\033[0m"

PHILO=./philo
PASS=0
FAIL=0

# ============================================
# Helper Functions
# ============================================

print_header()
{
    echo -e "\n${BABY}========================================${RSET}"
    echo -e "${BABY}  $1${RSET}"
    echo -e "${BABY}========================================${RSET}\n"
}

test_error()
{
    local desc="$1"
    shift
    local output
    output=$($PHILO "$@" 2>&1)
    local exit_code=$?
    if [ $exit_code -ne 0 ] || echo "$output" | grep -iq "error"; then
        echo -e "${MINT}✅ PASS${RSET} — $desc"
        ((PASS++))
    else
        echo -e "${BLOD}❌ FAIL${RSET} — $desc (should have thrown an error)"
        ((FAIL++))
    fi
}

test_must_die()
{
    local desc="$1"
    shift
    local output
    output=$(timeout 10 $PHILO "$@" 2>&1)
    if echo "$output" | grep -q "died"; then
        echo -e "${MINT}✅ PASS${RSET} — $desc"
        ((PASS++))
    else
        echo -e "${BLOD}❌ FAIL${RSET} — $desc (nobody died)"
        ((FAIL++))
    fi
}

test_no_die()
{
    local desc="$1"
    local duration="$2"
    shift 2
    local output
    output=$(timeout "$duration" $PHILO "$@" 2>&1)
    if echo "$output" | grep -q "died"; then
        echo -e "${BLOD}❌ FAIL${RSET} — $desc (someone died!)"
        ((FAIL++))
    else
        echo -e "${MINT}✅ PASS${RSET} — $desc"
        ((PASS++))
    fi
}

test_meals()
{
    local desc="$1"
    local philos="$2"
    local meals="$3"
    shift 3
    local expected=$((philos * meals))
    local output
    output=$(timeout 30 $PHILO "$@" 2>&1)
    
    if echo "$output" | grep -q "died"; then
        echo -e "${BLOD}❌ FAIL${RSET} — $desc (someone died!)"
        ((FAIL++))
        return
    fi
    
    local count
    count=$(echo "$output" | grep "is eating" | wc -l)
    
    # Allows the simulation to pass if philosophers eat MORE than the minimum required.
    if [ "$count" -ge "$expected" ]; then
        echo -e "${MINT}✅ PASS${RSET} — $desc ($count/$expected meals)"
        ((PASS++))
    else
        echo -e "${BLOD}❌ FAIL${RSET} — $desc ($count/$expected meals)"
        ((FAIL++))
    fi
}

test_no_output_after_death()
{
    local desc="$1"
    shift
    local output
    output=$(timeout 10 $PHILO "$@" 2>&1)
    
    # STRICT CHECK: Capture any text printed after the 'died' line (ignoring empty lines)
    local after_death
    after_death=$(echo "$output" | sed -n '/died/,$p' | tail -n +2 | grep -v "^[[:space:]]*$")
    
    if [ -z "$after_death" ]; then
        echo -e "${MINT}✅ PASS${RSET} — $desc"
        ((PASS++))
    else
        # Grab just the first offending line to keep the console clean
        local first_offense
        first_offense=$(echo "$after_death" | head -n 1)
        echo -e "${BLOD}❌ FAIL${RSET} — $desc (Output after death: $first_offense)"
        ((FAIL++))
    fi
}

test_death_timing()
{
    local desc="$1"
    local time_to_die="$2"
    shift 2
    local output
    output=$(timeout 10 $PHILO "$@" 2>&1)
    local death_time
    death_time=$(echo "$output" | grep "died" | awk '{print $1}')
    if [ -z "$death_time" ]; then
        echo -e "${BLOD}❌ FAIL${RSET} — $desc (nobody died)"
        ((FAIL++))
        return
    fi
    local max_time=$((time_to_die + 10))
    if [ "$death_time" -le "$max_time" ]; then
        echo -e "${MINT}✅ PASS${RSET} — $desc (died at ${death_time}ms, max ${max_time}ms)"
        ((PASS++))
    else
        echo -e "${BLOD}❌ FAIL${RSET} — $desc (died at ${death_time}ms, max was ${max_time}ms)"
        ((FAIL++))
    fi
}

# ============================================
# TESTS
# ============================================

print_header "1. INVALID ARGUMENTS"
test_error "0 philosophers"          0 800 200 200
test_error "Negative number"         -5 800 200 200
test_error "Negative time_to_die"    5 -800 200 200
test_error "Negative time_to_eat"    5 800 -200 200
test_error "Negative time_to_sleep"  5 800 200 -200
test_error "Negative meals"          5 800 200 200 -7
test_error "Non-numeric"             a 800 200 200
test_error "Integer overflow"        2147483648 800 200 200

print_header "2. ONE PHILOSOPHER"
test_must_die "1 philosopher must die" 1 800 200 200
test_death_timing "Death at ~800ms" 800 1 800 200 200

print_header "3. NOBODY SHOULD DIE"
test_no_die "5 800 200 200"   10 5 800 200 200
test_no_die "4 410 200 200"   10 4 410 200 200
test_no_die "5 610 200 200"   10 5 610 200 200
test_no_die "2 410 200 200"   10 2 410 200 200

print_header "4. SOMEONE MUST DIE"
test_must_die "4 310 200 100" 4 310 200 100
test_must_die "3 310 200 100" 3 310 200 100
test_must_die "5 300 200 200" 5 300 200 200

print_header "5. NO OUTPUT AFTER DEATH"
test_no_output_after_death "No msg after death (4 310 200 100)" 4 310 200 100
test_no_output_after_death "No msg after death (3 310 200 100)" 3 310 200 100

print_header "6. MEAL COUNT"
test_meals "5 800 200 200 7"   5 7  5 800 200 200 7
test_meals "4 410 200 200 10"  4 10 4 410 200 200 10
test_meals "2 800 200 200 5"   2 5  2 800 200 200 5

print_header "7. STRESS TEST"
test_no_die "100 philosophers"  10 100 800 200 200
test_no_die "200 philosophers"  10 200 800 200 200

print_header "8. LONG DURATION"
echo -e "${GOLD}⏳ Running for 30 seconds...${RSET}"
test_no_die "5 800 200 200 (30s)"  30 5 800 200 200
echo -e "${GOLD}⏳ Running for 30 seconds...${RSET}"
test_no_die "4 410 200 200 (30s)"  30 4 410 200 200

# ============================================
# FINAL RESULT
# ============================================

echo -e "\n${BABY}========================================${RSET}"
echo -e "${BABY}  FINAL RESULT${RSET}"
echo -e "${BABY}========================================${RSET}"
echo -e "${MINT}  PASS: $PASS${RSET}"
echo -e "${BLOD}  FAIL: $FAIL${RSET}"
TOTAL=$((PASS + FAIL))
echo -e "  TOTAL: $TOTAL"
echo -e "${BABY}========================================${RSET}\n"

if [ $FAIL -eq 0 ]; then
    echo -e "${MINT}🎉 ALL TESTS PASSED!${RSET}\n"
else
    echo -e "${BLOD}⚠️  THERE ARE FAILURES TO FIX${RSET}\n"
fi
