# pipex

## Overview
Simulates shell piping. Equivalent to `< infile cmd1 | cmd2 > outfile`. Teaches processes, file descriptors, and inter-process communication with pipes.

## Files
- `main.c`: entry point, calls ft_pipex
- `src/ft_pipex.c`: main logic — fork, pipe, waitpid, error handling
- `src/utils/ft_exec_cmd.c`: resolves PATH and executes command via execve
- `src/utils/ft_pipex_init.c`: open infile/outfile, init context
- `src/utils/ft_pipex_cleanup.c`: close fds, free resources
- `src/utils/ft_open_infile.c` / `ft_open_outfile.c`: file opening helpers
- `src/utils/ft_pipex_utils.c`: utility functions
- `lib/`: custom lib functions (ft_split, ft_strncmp, shell-like argument parser, etc.)

## Build and run
```bash
make
./pipex infile cmd1 cmd2 outfile
```

## Example
```bash
./pipex Makefile "grep pipex" "wc -l" out.txt
# same as: < Makefile grep pipex | wc -l > out.txt
```

## Notes
- Creates two child processes connected by a pipe
- Includes a shell-like argument parser (`ft_split_shell`) that handles quotes
- Returns the exit status of the last command
