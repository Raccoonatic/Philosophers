<p align="center"><i>This project has been created as part of the 42 curriculum by lde-san-.</i></p>

<h1 align="center">🦝🗿 Philosophers 🗿🦝</h1>
<p align="center"><b><em>Hopefully distinct from the last supper</em></b></p>

---

## 🎯 Description

**Philosophers** is a custom C implementation of the classic _Dining Philosophers_ 
problem, built for the 42 School curriculum. The primary objective of this 
project is to understand the fundamentals of multithreading, concurrent 
programming, and resource sharing. By managing threads representing philosophers
and mutexes representing forks, the project helps create a deeper understanding of 
system synchronization and the Linux kernel's CPU scheduler.

Developed entirely in C, the simulation features precise timekeeping down to the
millisecond, strict thread state management, and the absolute prevention of data
races and deadlocks.

### 🧠 *Core Architecture & Concepts:*
- Multithreading:
> Creating, managing, and joining concurrent execution threads using the pthread library.
- Synchronization:
> Utilizing mutex locks to safely manage shared resources (forks, meal timestamps, and death flags) across multiple of parallel threads.
- Time Management: 
> Bridging millisecond arithmetic and microsecond system calls using gettimeofday and highly optimized, proportional usleep wrappers to prevent Philosopher (thread) starvation and deadlocks.
- Concurrency Control:
> Architecting asynchronous monitor threads and state machines to seamlessly detect deaths, avoid self-deadlocks.

---

## 🤖 AI Usage

AI was used as a **supporting tool**, mainly for:

 - 📘 General documentation lookup *(e.g. POSIX thread behavior, Function's definitions and usage, Assigning meaning to previously unknown terminology)*
 - 🔍 Code reviewing / catching subtle mistakes, critisizing, and insanity prevention.
 - 💣 Preventing unnecessary compile attempts *(a.k.a. “yes, you forgot a semicolon again”)*

## 🛠️ Instructions

### How to compile<br>

Make sure you have `cc` and GNU Make installed.<br>
<br>
Inside the **philo** directory:<br>

• Compile the project with its provided Makefile
```
make
```
• Run the **philo** binary with the following parameters:<br>

> **_number_of_philosophers_**: The number of philosophers and also the number
of forks.
> 
> **_time_to_die_**: If a philosopher has not started eating within
time_to_die milliseconds since the start of their last meal or the start of the
simulation, they die.
> 
> **_time_to_eat_**: The time in milliseconds it takes for a philosopher to eat.
During that time, they will need to hold two forks.
> 
> **_time_to_sleep_**: The time in milliseconds a philosopher will spend sleeping.
> 
> **_number_of_meals_**: If all philosophers have eaten at least number_of_meals
times, the simulation stops. If not specified, the simulation stops when a philosopher dies. _(optional argument)_
> 
<br>

```
./philo number_of_philos time_to_die time_to_eat time_to_sleep [number_of_meals]
./philo 5 800 200 200 9
./philo 4 410 200 200
```
<br>

## 🦝 Other Makefile Utilities

• The **leaks** rule in the provided Makefile, will run the program using _valgrind_ to check for memory leaks.<br>
```
make leaks ARGS="number_of_philos time_to_die time_to_eat time_to_sleep [number_of_meals]"
```

• The **races** rule in the provided Makefile, will run the program using _valgrind --tool=helgrind_ to check for data races.<br>
```
make races ARGS="number_of_philos time_to_die time_to_eat time_to_sleep [number_of_meals]"
```
• The **tests** rule in the provided Makefile, creates a shell script that will run the program through a series of tests. <br>
```
make tests
```
• The **open** rule in the provided Makefile, opens all the source files that were created for this project.<br>
```
make open
```
• The **clean** rule in the provided Makefile, removes the object files, created during compilation.<br>
```
make clean
```
• The **fclean** rule in the provided Makefile, runs the **clean** rule and removes the **philo** executable.<br>
```
make fclean
```
• The **re** rule in the provided Makefile, runs the **fclean** rule and re-compiles the **philo** executable.<br>
```
make re
```
<br>

## 📚 Resources

<br>Understanding the Project:<br>
* [Information on threads and how to use them [CodeVault]](https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)
* [Example implementation [SuspectedOceano]](https://www.youtube.com/watch?v=zOpzGHwJ3MU)
* [Tips and general project concept [Jamshidbek Ergashev]](https://www.youtube.com/watch?v=UGQsvVKwe90)<br>

<br>Testing:<br>
* [Simulation Visualizer](https://nafuka11.github.io/philosophers-visualizer/)<br>

<br>Focus Boost:<br>
* [Background Noise](https://www.youtube.com/watch?v=kN-iEJ3Sbsc&list=PLcL9r1K3TSwpOVyQKP1MruSuY-NS99iQY)
* [Foreground Noise](https://open.spotify.com/playlist/5O5q1xG6hNt7NDA8tmT2KJ?si=c9f448d17bba40dc)<br>

---

## 🧾 Final Notes 🦝💜

If you made it this far…

Merry Christmas. Take a break. Drink water. Maybe eat an arepa.

Don’t let [Glutto](https://github.com/Raccoonatic/Glutto-The-Fox) eat them all.

💥🧡✨
