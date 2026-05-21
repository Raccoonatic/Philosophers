# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-san- <lde-san-@student.42porto.co      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/03 19:37:56 by lde-san-          #+#    #+#              #
#    Updated: 2026/05/20 21:37:51 by lde-san-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
PHILO_LIB = libphilo.a

ARGS ?= 1

NEOR	= \033[3m\033[38;2;255;153;51m
MINT    = \033[1;38;2;55;250;133m
ORNG    = \033[1;38;2;255;153;51m
PURP	= \033[1;38;2;174;5;252m
PINK    = \033[1;38;2;255;0;251m
BABY    = \033[1;38;2;0;255;247m
BLOD	= \033[1;38;2;255;0;0m
LIME    = \033[1;38;2;0;255;0m
BLAK	= \033[1;38;2;0;0;0m
B_WI    = \033[1;37m
RSET	= \033[0m

OBJ_DIR = obj/
OBJ = $(FILE:%.c=$(OBJ_DIR)%.o)

MAIN_FILE = philo_main.c

FILE = philo_simulation.c
FILE += philo_simulation_utils.c
FILE += philo_utils_alpha.c
FILE += philo_utils_bravo.c
FILE += philo_utils_charlie.c
FILE += philo_utils_delta.c

.PRECIOUS: $(FILE)

COMPILE = cc -g -O0 -Wall -Werror -Wextra -pthread -I.
LEAK_FLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes
THREAD_FLAGS = --tool=helgrind

all: $(NAME)

$(NAME): $(PHILO_LIB) $(MAIN_FILE) philo.h
	@printf "$(BABY)"
	$(COMPILE) $(MAIN_FILE) $(PHILO_LIB) -o $(NAME)
	@printf "$(RSET)\n"

$(OBJ_DIR)%.o: %.c philo.h | $(OBJ_DIR)
	@printf "$(PURP)"
	$(COMPILE) -c $< -o $@
	@printf "$(RSET)\n"

$(OBJ_DIR):
	@printf "$(LIME)"
	mkdir -p $(OBJ_DIR)
	@printf "$(RSET)\n"

$(PHILO_LIB): $(OBJ)
	@printf "$(PINK)"
	ar -rcs $@ $^
	@printf "$(RSET)\n"

clean:
	@printf "$(ORNG)"
	rm -rf $(OBJ_DIR)
	@printf "$(BLOD)"
	rm -rf $(PHILO_LIB)
	@printf "$(RSET)\n"

fclean: clean
	@printf "$(PURP)"
	rm -f $(NAME)
	@rm -rf normloop.sh
	@rm -rf philo_test.sh
	@printf "$(MINT)\n"
	@ls -la
	@printf "$(RSET)\n"

re: fclean all

# /////////////////////// -- * Functionality * -- ////////////////////// #

open:
	@printf "$(MINT)"
	open $(MAIN_FILE)
	for f in $(FILE); do xdg-open $$f; done
	@printf "$(ORNG)"
	find . -maxdepth 2 -name "*.h" -exec xdg-open {} \;
	@printf "$(RSET)"

leaks: $(NAME)
	@printf "\n$(PINK)valgrind $(ORNG)$(LEAK_FLAGS) $(MINT)./$(NAME) $(BABY)$(ARGS)"
	@printf "$(RSET)\n"
	@valgrind $(LEAK_FLAGS) ./$(NAME) $(ARGS)
	@sleep 0.3

races: $(NAME)
	@printf "\n$(PINK)valgrind $(ORNG)$(THREAD_FLAGS) $(MINT)./$(NAME) $(BABY)$(ARGS)"
	@printf "$(RSET)\n"
	@valgrind $(THREAD_FLAGS) ./$(NAME) $(ARGS)
	@sleep 0.3

tests: all philo_test.sh
	@./philo_test.sh
	@rm -rf philo_test.sh

normloop:
	@printf "$(NEOR) Building normloop.sh... $(RESET)"
	@sleep 0.5
	@printf "$(MINT)🦝\n\n"
	@printf "$(BABY)'# ************************************************************************ #'\n"
	@printf "$(BABY)'#                                                                          #'\n"
	@printf "$(BABY)'#                                                       :::      ::::::::  #'\n"
	@printf "$(BABY)'#  normloop.sh                                        :+:      :+:    :+:  #'\n"
	@printf "$(BABY)'#                                                   +:+ +:+         +:+    #'\n"
	@printf "$(BABY)'#  By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+       #'\n"
	@printf "$(BABY)'#                                               +#+#+#+#+#+   +#+          #'\n"
	@printf "$(BABY)'#  Created: 2026/03/14 17:57:19 by lde-san-          #+#    #+#            #'\n"
	@printf "$(BABY)'#  Updated: 2026/03/14 17:58:08 by lde-san-         ###   ########.fr      #'\n"
	@printf "$(BABY)'#                                                                          #'\n"
	@printf "$(BABY)'# ************************************************************************ #'\n"
	@> normloop.sh
	@printf "%s\n" '#!/bin/bash'>> normloop.sh
	@printf "%s\n" '# **************************************************************************** #'>> normloop.sh
	@printf "%s\n" '#                                                                              #'>> normloop.sh
	@printf "%s\n" '#                                                         :::      ::::::::    #'>> normloop.sh
	@printf "%s\n" '#    normloop.sh                                        :+:      :+:    :+:    #'>> normloop.sh
	@printf "%s\n" '#                                                     +:+ +:+         +:+      #'>> normloop.sh
	@printf "%s\n" '#    By: lde-san- <lde-san-@student.42porto.com>    +#+  +:+       +#+         #'>> normloop.sh
	@printf "%s\n" '#                                                 +#+#+#+#+#+   +#+            #'>> normloop.sh
	@printf "%s\n" '#    Created: 2026/03/14 17:57:19 by lde-san-          #+#    #+#              #'>> normloop.sh
	@printf "%s\n" '#    Updated: 2026/03/14 17:58:08 by lde-san-         ###   ########.fr        #'>> normloop.sh
	@printf "%s\n" '#                                                                              #'>> normloop.sh
	@printf "%s\n" '# **************************************************************************** #'>> normloop.sh
	@printf "%s\n" ''>> normloop.sh
	@printf "%s\n" 'trap '\''rm -f tody.txt; exit'\'' INT'>> normloop.sh
	@printf "%s\n" ''>> normloop.sh
	@printf "%s\n" 'if [ -n '\"'$$1'\"' ]; then'>> normloop.sh
	@printf "%s\n" '	FILE='\"'$$1'\"''>> normloop.sh
	@printf "%s\n" ''>> normloop.sh
	@printf "%s\n" '	while true'>> normloop.sh
	@printf "%s\n" '	do'>> normloop.sh
	@printf "%s\n" '		norminette -R CheckForbiddenSourceHeader '\"'$$FILE'\"' | grep Error | head -n 40 > tody.txt'>> normloop.sh
	@printf "%s\n" '		clear && cat tody.txt'>> normloop.sh
	@printf "%s\n" '		tput cup 0 0'>> normloop.sh
	@printf "%s\n" '		sleep 1'>> normloop.sh
	@printf "%s\n" '	done'>> normloop.sh
	@printf "%s\n" 'else'>> normloop.sh
	@printf "%s\n" '	while true'>> normloop.sh
	@printf "%s\n" '	do'>> normloop.sh
	@printf "%s\n" '		norminette -R CheckForbiddenSourceHeader *.c | grep Error | head -n 40 > tody.txt'>> normloop.sh
	@printf "%s\n" '        clear && cat tody.txt'>> normloop.sh
	@printf "%s\n" '		tput cup 0 0'>> normloop.sh
	@printf "%s\n" '		sleep 1'>> normloop.sh
	@printf "%s\n" '	done'>> normloop.sh
	@printf "%s\n" 'fi'>> normloop.sh
	@chmod 777 normloop.sh
	@printf "$(RESET)                                     🦝"

philo_test.sh:
	@printf "                      🦝 \001\033[3m\033[38;2;255;153;51m\002Building philo_test.sh... 🦝\\n"
	@> philo_test.sh
	@printf "%s\n" '#!/bin/bash' >> philo_test.sh
	@printf "%b%s%b\n" '\001\033[1;38;2;0;255;247m\002' '# **************************************************************************** #' '\001\033[0m\002'
	@printf "%s\n" '# **************************************************************************** #' >> philo_test.sh
	@printf "%b%s%b\n" '\001\033[1;38;2;0;255;247m\002' '#                                                                              #' '\001\033[0m\002'
	@printf "%s\n" '#                                                                              #' >> philo_test.sh
	@printf "%b%s%b\n" '\001\033[1;38;2;0;255;247m\002' '#                                                         :::      ::::::::    #' '\001\033[0m\002'
	@printf "%s\n" '#                                                         :::      ::::::::    #' >> philo_test.sh
	@printf "%b%s%b%s%b%s%b\n" '\001\033[1;38;2;0;255;247m\002' '#    ' '\001\033[1;38;2;55;250;133m\002' 'philo_test.sh                                 ' '\001\033[1;38;2;0;255;247m\002' '     :+:      :+:    :+:    #' '\001\033[0m\002'
	@printf "%s\n" '#    philo_test.sh                                      :+:      :+:    :+:    #' >> philo_test.sh
	@printf "%b%s%b\n" '\001\033[1;38;2;0;255;247m\002' '#                                                     +:+ +:+         +:+      #' '\001\033[0m\002'
	@printf "%s\n" '#                                                     +:+ +:+         +:+      #' >> philo_test.sh
	@printf "%b%s%b%s%b%s%b\n" '\001\033[1;38;2;0;255;247m\002' '#    ' '\001\033[1;38;2;55;250;133m\002' 'By: lde-san- <lde-san-@student.42porto.co     ' '\001\033[1;38;2;0;255;247m\002' ' +#+  +:+       +#+         #' '\001\033[0m\002'
	@printf "%s\n" '#    By: lde-san- <lde-san-@student.42porto.co      +#+  +:+       +#+         #' >> philo_test.sh
	@printf "%b%s%b\n" '\001\033[1;38;2;0;255;247m\002' '#                                                 +#+#+#+#+#+   +#+            #' '\001\033[0m\002'
	@printf "%s\n" '#                                                 +#+#+#+#+#+   +#+            #' >> philo_test.sh
	@printf "%b%s%b%s%b%s%b\n" '\001\033[1;38;2;0;255;247m\002' '#    ' '\001\033[1;38;2;0;255;0m\002' 'Created: 2026/04/07 12:44:59 by lde-san-      ' '\001\033[1;38;2;0;255;247m\002' '    #+#    #+#              #' '\001\033[0m\002'
	@printf "%s\n" '#    Created: 2026/04/07 12:44:59 by lde-san-          #+#    #+#              #' >> philo_test.sh
	@printf "%b%s%b%s%b%s%b\n" '\001\033[1;38;2;0;255;247m\002' '#    ' '\001\033[1;38;2;0;255;0m\002' 'Updated: 2026/05/20 12:02:06 by lde-san-      ' '\001\033[1;38;2;0;255;247m\002' '   ###   ########.fr        #' '\001\033[0m\002'
	@printf "%s\n" '#    Updated: 2026/05/20 12:02:06 by lde-san-         ###   ########.fr        #' >> philo_test.sh
	@printf "%b%s%b\n" '\001\033[1;38;2;0;255;247m\002' '#                                                                              #' '\001\033[0m\002'
	@printf "%s\n" '#                                                                              #' >> philo_test.sh
	@printf "%b%s%b\n" '\001\033[1;38;2;0;255;247m\002' '# **************************************************************************** #' '\001\033[0m\002'
	@printf "%s\n" '# **************************************************************************** #' >> philo_test.sh
	@printf "%s\n" '' >> philo_test.sh
	@printf "%s\n" 'NEOR="\033[3m\033[38;2;255;153;51m"' >> philo_test.sh
	@printf "%s\n" 'GOLD="\033[1;38;2;235;232;52m"' >> philo_test.sh
	@printf "%s\n" 'MINT="\033[1;38;2;55;250;133m"' >> philo_test.sh
	@printf "%s\n" 'ORNG="\033[1;38;2;255;153;51m"' >> philo_test.sh
	@printf "%s\n" 'PURP="\033[1;38;2;174;5;252m"' >> philo_test.sh
	@printf "%s\n" 'PINK="\033[1;38;2;255;0;251m"' >> philo_test.sh
	@printf "%s\n" 'BABY="\033[1;38;2;0;255;247m"' >> philo_test.sh
	@printf "%s\n" 'BLOD="\033[1;38;2;255;0;0m"' >> philo_test.sh
	@printf "%s\n" 'LIME="\033[1;38;2;0;255;0m"' >> philo_test.sh
	@printf "%s\n" 'RSET="\033[0m"' >> philo_test.sh
	@printf "%s\n" '' >> philo_test.sh
	@printf "%s\n" 'PHILO=./philo' >> philo_test.sh
	@printf "%s\n" 'PASS=0' >> philo_test.sh
	@printf "%s\n" 'FAIL=0' >> philo_test.sh
	@printf "%s\n" '' >> philo_test.sh
	@printf "%s\n" '# ============================================' >> philo_test.sh
	@printf "%s\n" '# Helper Functions' >> philo_test.sh
	@printf "%s\n" '# ============================================' >> philo_test.sh
	@printf "%s\n" '' >> philo_test.sh
	@printf "%s\n" 'print_header()' >> philo_test.sh
	@printf "%s\n" '{' >> philo_test.sh
	@printf "%s\n" '    echo -e "\n$${PURP}..*$${LIME}#$${PINK}>$${BABY}--$${LIME}>$${BABY}>$${MINT}===========$${BABY}<$${LIME}<$${BABY}--$${PINK}<$${LIME}#$${PURP}*..$${RSET}"' >> philo_test.sh
	@printf "%s\n" '    echo -e "$${BABY}   $$1$${RSET}"' >> philo_test.sh
	@printf "%s\n" '    echo -e "$${PURP}..*$${LIME}#$${PINK}>$${BABY}--$${LIME}>$${BABY}>$${MINT}===========$${BABY}<$${LIME}<$${BABY}--$${PINK}<$${LIME}#$${PURP}*..$${RSET}\n"' >> philo_test.sh
	@printf "%s\n" '}' >> philo_test.sh
	@printf "%s\n" '' >> philo_test.sh
	@printf "%s\n" 'test_error()' >> philo_test.sh
	@printf "%s\n" '{' >> philo_test.sh
	@printf "%s\n" '    local desc="$$1"' >> philo_test.sh
	@printf "%s\n" '    shift' >> philo_test.sh
	@printf "%s\n" '    local output' >> philo_test.sh
	@printf "%s\n" '    output=$$($$PHILO "$$@" 2>&1)' >> philo_test.sh
	@printf "%s\n" '    local exit_code=$$?' >> philo_test.sh
	@printf "%s\n" '    if [ $$exit_code -ne 0 ] || echo "$$output" | grep -iq "error"; then' >> philo_test.sh
	@printf "%s\n" '        echo -e "$${MINT}✅ PASS$${RSET} — $$desc"' >> philo_test.sh
	@printf "%s\n" '        ((PASS++))' >> philo_test.sh
	@printf "%s\n" '    else' >> philo_test.sh
	@printf "%s\n" '        echo -e "$${BLOD}❌ FAIL$${RSET} — $$desc (should have thrown an error)"' >> philo_test.sh
	@printf "%s\n" '        ((FAIL++))' >> philo_test.sh
	@printf "%s\n" '    fi' >> philo_test.sh
	@printf "%s\n" '}' >> philo_test.sh
	@printf "%s\n" '' >> philo_test.sh
	@printf "%s\n" 'test_must_die()' >> philo_test.sh
	@printf "%s\n" '{' >> philo_test.sh
	@printf "%s\n" '    local desc="$$1"' >> philo_test.sh
	@printf "%s\n" '    shift' >> philo_test.sh
	@printf "%s\n" '    local output' >> philo_test.sh
	@printf "%s\n" '    output=$$(timeout 10 $$PHILO "$$@" 2>&1)' >> philo_test.sh
	@printf "%s\n" '    if echo "$$output" | grep -q "died"; then' >> philo_test.sh
	@printf "%s\n" '        echo -e "$${MINT}✅ PASS$${RSET} — $$desc"' >> philo_test.sh
	@printf "%s\n" '        ((PASS++))' >> philo_test.sh
	@printf "%s\n" '    else' >> philo_test.sh
	@printf "%s\n" '        echo -e "$${BLOD}❌ FAIL$${RSET} — $$desc (nobody died)"' >> philo_test.sh
	@printf "%s\n" '        ((FAIL++))' >> philo_test.sh
	@printf "%s\n" '    fi' >> philo_test.sh
	@printf "%s\n" '}' >> philo_test.sh
	@printf "%s\n" '' >> philo_test.sh
	@printf "%s\n" 'test_no_die()' >> philo_test.sh
	@printf "%s\n" '{' >> philo_test.sh
	@printf "%s\n" '    local desc="$$1"' >> philo_test.sh
	@printf "%s\n" '    local duration="$$2"' >> philo_test.sh
	@printf "%s\n" '    shift 2' >> philo_test.sh
	@printf "%s\n" '    local output' >> philo_test.sh
	@printf "%s\n" '    output=$$(timeout "$$duration" $$PHILO "$$@" 2>&1)' >> philo_test.sh
	@printf "%s\n" '    if echo "$$output" | grep -q "died"; then' >> philo_test.sh
	@printf "%s\n" '        echo -e "$${BLOD}❌ FAIL$${RSET} — $$desc (someone died!)"' >> philo_test.sh
	@printf "%s\n" '        ((FAIL++))' >> philo_test.sh
	@printf "%s\n" '    else' >> philo_test.sh
	@printf "%s\n" '        echo -e "$${MINT}✅ PASS$${RSET} — $$desc"' >> philo_test.sh
	@printf "%s\n" '        ((PASS++))' >> philo_test.sh
	@printf "%s\n" '    fi' >> philo_test.sh
	@printf "%s\n" '}' >> philo_test.sh
	@printf "%s\n" '' >> philo_test.sh
	@printf "%s\n" 'test_meals()' >> philo_test.sh
	@printf "%s\n" '{' >> philo_test.sh
	@printf "%s\n" '    local desc="$$1"' >> philo_test.sh
	@printf "%s\n" '    local philos="$$2"' >> philo_test.sh
	@printf "%s\n" '    local meals="$$3"' >> philo_test.sh
	@printf "%s\n" '    shift 3' >> philo_test.sh
	@printf "%s\n" '    local expected=$$((philos * meals))' >> philo_test.sh
	@printf "%s\n" '    local output' >> philo_test.sh
	@printf "%s\n" '    output=$$(timeout 30 $$PHILO "$$@" 2>&1)' >> philo_test.sh
	@printf "%s\n" '    ' >> philo_test.sh
	@printf "%s\n" '    if echo "$$output" | grep -q "died"; then' >> philo_test.sh
	@printf "%s\n" '        echo -e "$${BLOD}❌ FAIL$${RSET} — $$desc (someone died!)"' >> philo_test.sh
	@printf "%s\n" '        ((FAIL++))' >> philo_test.sh
	@printf "%s\n" '        return' >> philo_test.sh
	@printf "%s\n" '    fi' >> philo_test.sh
	@printf "%s\n" '    ' >> philo_test.sh
	@printf "%s\n" '    local count' >> philo_test.sh
	@printf "%s\n" '    count=$$(echo "$$output" | grep "is eating" | wc -l)' >> philo_test.sh
	@printf "%s\n" '    ' >> philo_test.sh
	@printf "%s\n" '' >> philo_test.sh
	@printf "%s\n" '    if [ "$$count" -ge "$$expected" ]; then' >> philo_test.sh
	@printf "%s\n" '        echo -e "$${MINT}✅ PASS$${RSET} — $$desc ($$count/$$expected meals)"' >> philo_test.sh
	@printf "%s\n" '        ((PASS++))' >> philo_test.sh
	@printf "%s\n" '    else' >> philo_test.sh
	@printf "%s\n" '        echo -e "$${BLOD}❌ FAIL$${RSET} — $$desc ($$count/$$expected meals)"' >> philo_test.sh
	@printf "%s\n" '        ((FAIL++))' >> philo_test.sh
	@printf "%s\n" '    fi' >> philo_test.sh
	@printf "%s\n" '}' >> philo_test.sh
	@printf "%s\n" '' >> philo_test.sh
	@printf "%s\n" 'test_no_output_after_death()' >> philo_test.sh
	@printf "%s\n" '{' >> philo_test.sh
	@printf "%s\n" '    local desc="$$1"' >> philo_test.sh
	@printf "%s\n" '    shift' >> philo_test.sh
	@printf "%s\n" '    local output' >> philo_test.sh
	@printf "%s\n" '    output=$$(timeout 10 $$PHILO "$$@" 2>&1)' >> philo_test.sh
	@printf "%s\n" '    ' >> philo_test.sh
	@printf "%s\n" '    local after_death' >> philo_test.sh
	@printf "%s\n" '    after_death=$$(echo "$$output" | sed -n '\''/died/,$$p'\'' | tail -n +2 | grep -v "^[[:space:]]*$$")' >> philo_test.sh
	@printf "%s\n" '    ' >> philo_test.sh
	@printf "%s\n" '    if [ -z "$$after_death" ]; then' >> philo_test.sh
	@printf "%s\n" '        echo -e "$${MINT}✅ PASS$${RSET} — $$desc"' >> philo_test.sh
	@printf "%s\n" '        ((PASS++))' >> philo_test.sh
	@printf "%s\n" '    else' >> philo_test.sh
	@printf "%s\n" '        local first_offense' >> philo_test.sh
	@printf "%s\n" '        first_offense=$$(echo "$$after_death" | head -n 1)' >> philo_test.sh
	@printf "%s\n" '        echo -e "$${BLOD}❌ FAIL$${RSET} — $$desc (Output after death: $$first_offense)"' >> philo_test.sh
	@printf "%s\n" '        ((FAIL++))' >> philo_test.sh
	@printf "%s\n" '    fi' >> philo_test.sh
	@printf "%s\n" '}' >> philo_test.sh
	@printf "%s\n" '' >> philo_test.sh
	@printf "%s\n" 'test_death_timing()' >> philo_test.sh
	@printf "%s\n" '{' >> philo_test.sh
	@printf "%s\n" '    local desc="$$1"' >> philo_test.sh
	@printf "%s\n" '    local time_to_die="$$2"' >> philo_test.sh
	@printf "%s\n" '    shift 2' >> philo_test.sh
	@printf "%s\n" '    local output' >> philo_test.sh
	@printf "%s\n" '    output=$$(timeout 10 $$PHILO "$$@" 2>&1)' >> philo_test.sh
	@printf "%s\n" '    local death_time' >> philo_test.sh
	@printf "%s\n" '    death_time=$$(echo "$$output" | grep "died" | awk '\''{print $$1}'\'')' >> philo_test.sh
	@printf "%s\n" '    if [ -z "$$death_time" ]; then' >> philo_test.sh
	@printf "%s\n" '        echo -e "$${BLOD}❌ FAIL$${RSET} — $$desc (nobody died)"' >> philo_test.sh
	@printf "%s\n" '        ((FAIL++))' >> philo_test.sh
	@printf "%s\n" '        return' >> philo_test.sh
	@printf "%s\n" '    fi' >> philo_test.sh
	@printf "%s\n" '    local max_time=$$((time_to_die + 10))' >> philo_test.sh
	@printf "%s\n" '    if [ "$$death_time" -le "$$max_time" ]; then' >> philo_test.sh
	@printf "%s\n" '        echo -e "$${MINT}✅ PASS$${RSET} — $$desc (died at $${death_time}ms, max $${max_time}ms)"' >> philo_test.sh
	@printf "%s\n" '        ((PASS++))' >> philo_test.sh
	@printf "%s\n" '    else' >> philo_test.sh
	@printf "%s\n" '        echo -e "$${BLOD}❌ FAIL$${RSET} — $$desc (died at $${death_time}ms, max was $${max_time}ms)"' >> philo_test.sh
	@printf "%s\n" '        ((FAIL++))' >> philo_test.sh
	@printf "%s\n" '    fi' >> philo_test.sh
	@printf "%s\n" '}' >> philo_test.sh
	@printf "%s\n" '' >> philo_test.sh
	@printf "%s\n" '# ============================================' >> philo_test.sh
	@printf "%s\n" '# TESTS' >> philo_test.sh
	@printf "%s\n" '# ============================================' >> philo_test.sh
	@printf "%s\n" '' >> philo_test.sh
	@printf "%s\n" 'print_header "1. INVALID ARGUMENTS"' >> philo_test.sh
	@printf "%s\n" 'test_error "0 philosophers"          0 800 200 200' >> philo_test.sh
	@printf "%s\n" 'test_error "Negative number"         -5 800 200 200' >> philo_test.sh
	@printf "%s\n" 'test_error "Negative time_to_die"    5 -800 200 200' >> philo_test.sh
	@printf "%s\n" 'test_error "Negative time_to_eat"    5 800 -200 200' >> philo_test.sh
	@printf "%s\n" 'test_error "Negative time_to_sleep"  5 800 200 -200' >> philo_test.sh
	@printf "%s\n" 'test_error "Negative meals"          5 800 200 200 -7' >> philo_test.sh
	@printf "%s\n" 'test_error "Non-numeric"             a 800 200 200' >> philo_test.sh
	@printf "%s\n" 'test_error "Integer overflow"        2147483648 800 200 200' >> philo_test.sh
	@printf "%s\n" '' >> philo_test.sh
	@printf "%s\n" 'print_header "2. ONE PHILOSOPHER"' >> philo_test.sh
	@printf "%s\n" 'test_must_die "1 philosopher must die" 1 800 200 200' >> philo_test.sh
	@printf "%s\n" 'test_death_timing "Death at ~800ms" 800 1 800 200 200' >> philo_test.sh
	@printf "%s\n" '' >> philo_test.sh
	@printf "%s\n" 'print_header "3. NOBODY SHOULD DIE"' >> philo_test.sh
	@printf "%s\n" 'test_no_die "5 800 200 200"   10 5 800 200 200' >> philo_test.sh
	@printf "%s\n" 'test_no_die "4 410 200 200"   10 4 410 200 200' >> philo_test.sh
	@printf "%s\n" 'test_no_die "5 610 200 200"   10 5 610 200 200' >> philo_test.sh
	@printf "%s\n" 'test_no_die "2 410 200 200"   10 2 410 200 200' >> philo_test.sh
	@printf "%s\n" '' >> philo_test.sh
	@printf "%s\n" 'print_header "4. SOMEONE MUST DIE"' >> philo_test.sh
	@printf "%s\n" 'test_must_die "4 310 200 100" 4 310 200 100' >> philo_test.sh
	@printf "%s\n" 'test_must_die "3 310 200 100" 3 310 200 100' >> philo_test.sh
	@printf "%s\n" 'test_must_die "5 300 200 200" 5 300 200 200' >> philo_test.sh
	@printf "%s\n" '' >> philo_test.sh
	@printf "%s\n" 'print_header "5. NO OUTPUT AFTER DEATH"' >> philo_test.sh
	@printf "%s\n" 'test_no_output_after_death "No msg after death (4 310 200 100)" 4 310 200 100' >> philo_test.sh
	@printf "%s\n" 'test_no_output_after_death "No msg after death (3 310 200 100)" 3 310 200 100' >> philo_test.sh
	@printf "%s\n" '' >> philo_test.sh
	@printf "%s\n" 'print_header "6. MEAL COUNT"' >> philo_test.sh
	@printf "%s\n" 'test_meals "5 800 200 200 7"   5 7  5 800 200 200 7' >> philo_test.sh
	@printf "%s\n" 'test_meals "4 410 200 200 10"  4 10 4 410 200 200 10' >> philo_test.sh
	@printf "%s\n" 'test_meals "2 800 200 200 5"   2 5  2 800 200 200 5' >> philo_test.sh
	@printf "%s\n" '' >> philo_test.sh
	@printf "%s\n" 'print_header "7. STRESS TEST"' >> philo_test.sh
	@printf "%s\n" 'test_no_die "100 philosophers"  10 100 800 200 200' >> philo_test.sh
	@printf "%s\n" 'test_no_die "200 philosophers"  10 200 800 200 200' >> philo_test.sh
	@printf "%s\n" '' >> philo_test.sh
	@printf "%s\n" 'print_header "8. LONG DURATION"' >> philo_test.sh
	@printf "%s\n" 'echo -e "$${GOLD}⏳ Running ODD for 30 seconds...$${RSET}"' >> philo_test.sh
	@printf "%s\n" 'test_no_die "5 800 200 200 (30s)"  30 5 800 200 200' >> philo_test.sh
	@printf "%s\n" 'echo -e "$${GOLD}⏳ Running EVN for 30 seconds...$${RSET}"' >> philo_test.sh
	@printf "%s\n" 'test_no_die "4 410 200 200 (30s)"  30 4 410 200 200' >> philo_test.sh
	@printf "%s\n" '' >> philo_test.sh
	@printf "%s\n" '# ============================================' >> philo_test.sh
	@printf "%s\n" '# FINAL RESULT' >> philo_test.sh
	@printf "%s\n" '# ============================================' >> philo_test.sh
	@printf "%s\n" '' >> philo_test.sh
	@printf "%s\n" 'echo -e "\n$${PURP}..*$${LIME}#$${PINK}>$${BABY}--$${LIME}>$${BABY}>$${MINT}===========$${BABY}<$${LIME}<$${BABY}--$${PINK}<$${LIME}#$${PURP}*..$${RSET}"' >> philo_test.sh
	@printf "%s\n" 'echo -e "$${BABY}        FINAL  RESULT$${RSET}"' >> philo_test.sh
	@printf "%s\n" 'echo -e "$${PURP}..*$${LIME}#$${PINK}>$${BABY}--$${LIME}>$${BABY}>$${MINT}===========$${BABY}<$${LIME}<$${BABY}--$${PINK}<$${LIME}#$${PURP}*..$${RSET}"' >> philo_test.sh
	@printf "%s\n" 'echo -e "$${MINT}           PASS: $$PASS$${RSET}"' >> philo_test.sh
	@printf "%s\n" 'echo -e "$${BLOD}           FAIL: $$FAIL$${RSET}"' >> philo_test.sh
	@printf "%s\n" 'TOTAL=$$((PASS + FAIL))' >> philo_test.sh
	@printf "%s\n" 'echo -e "          TOTAL: $$TOTAL"' >> philo_test.sh
	@printf "%s\n" '' >> philo_test.sh
	@printf "%s\n" 'if [ $$FAIL -eq 0 ]; then' >> philo_test.sh
	@printf "%s\n" '    echo -e "\n\n$${MINT}🎉 ALL TESTS PASSED! 🦝$${RSET}\n"' >> philo_test.sh
	@printf "%s\n" 'else' >> philo_test.sh
	@printf "%s\n" '    echo -e "\n\n$${BLOD}⚠️  THERE ARE FAILURES TO FIX 🦝$${RSET}\n"' >> philo_test.sh
	@printf "%s\n" 'fi' >> philo_test.sh
	@chmod +x philo_test.sh
	@printf "\033[0m                                     🦝\n"

.PHONY: all clean fclean re open normloop leaks
