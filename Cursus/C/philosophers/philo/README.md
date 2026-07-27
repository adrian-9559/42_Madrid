# philosophers

## Overview
Dining philosophers problem solved with threads and mutexes. Each philosopher is a thread; forks are mutexes. A monitor thread detects death.

## Files
- `main.c`: argument validation and setup
- `src/ft_philosophers.c`: spawns philosopher threads and the monitor
- `src/philosophers/ft_philo_routine.c`: philosopher lifecycle (eat, sleep, think)
- `src/philosophers/ft_take_forks_and_eat.c`: fork acquisition and eating logic
- `src/philosophers/ft_monitor.c`: death detection and simulation stop
- `src/philosophers/ft_create_philosophers.c` / `ft_destroy_philosophers.c`: linked list management
- `src/philosophers/ft_spawn_philosophers.c`: thread creation
- `src/philosophers/ft_print_status.c`: timestamped status output
- `src/forks/`: fork take/put helpers
- `src/time/`: time utilities (gettimeofday, ms sleep)
- `src/data/`: simulation config construction and cleanup
- `src/thread/`, `src/mutex/`, `src/utils/`, `src/print/`: supporting utilities

## Build and run
```bash
make
./philo <n_philos> <time_to_die> <time_to_eat> <time_to_sleep> [n_must_eat]
```

## Example
```bash
./philo 5 800 200 200
```

## Notes
- Uses `pthread` for threading and `pthread_mutex_t` for fork protection
- A separate monitor thread polls philosopher states and stops on death or all-fed
- Even-numbered philosophers have a staggered start to avoid fork contention
- Odd philosopher count adds extra think time to avoid deadlock
