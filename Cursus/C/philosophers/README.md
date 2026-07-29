# philosophers

## Overview
Dining philosophers problem solved with threads and mutexes. Each philosopher is a thread; forks are mutexes. A monitor thread detects death and stops the simulation.

## Project structure
```
philo/
├── main.c                          # argument validation and setup
├── philosophers.h                  # main header
├── str_error.h                     # error string definitions
├── Makefile
├── README.md                       # detailed project documentation
└── src/
    ├── ft_philosophers.c           # spawns philosopher threads and the monitor
    ├── philosophers/               # philospher lifecycle, fork logic, monitor
    ├── forks/                      # fork take/put helpers
    ├── time/                       # time utilities (gettimeofday, ms sleep)
    ├── data/                       # simulation config construction and cleanup
    ├── thread/, mutex/, utils/, print/  # supporting utilities
    └── ...                         # additional source files
```

## Build and run
```bash
cd philo && make
./philo <n_philos> <time_to_die> <time_to_eat> <time_to_sleep> [n_must_eat]
```

## Example
```bash
./philo 5 800 200 200
```

## Notes
- See `philo/README.md` for full implementation details.
- Uses `pthread` for threading and `pthread_mutex_t` for fork protection.
- A monitor thread polls philosopher states and stops on death or all-fed.
- Even-numbered philosophers have a staggered start to avoid fork contention.
