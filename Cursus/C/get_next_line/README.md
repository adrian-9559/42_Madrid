# get_next_line

## Overview
Reads a line from a file descriptor, one line per call. A fundamental 42 project introducing static variables and file I/O buffering.

## Files
- `get_next_line.c`: main function with static buffer (reminder)
- `get_next_line_utils.c`: helper functions (ft_strlen, ft_strdup, ft_substr, ft_strjoin, ft_strchr)
- `get_next_line.h`: header with BUFFER_SIZE config (default 1024)
- `get_next_line_bonus.c`: same logic but handles multiple FDs via `reminder[2048]`
- `get_next_line_bonus.h`: bonus header

## Build
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 -c get_next_line.c get_next_line_utils.c
```
Then link the .o files into your project.

## Usage
```c
#include "get_next_line.h"

char *line;
int fd = open("file.txt", O_RDONLY);
while ((line = get_next_line(fd)) != NULL)
{
    // use line
    free(line);
}
```

## Notes
- Uses a static `reminder` to persist data between calls (array of pointers in bonus)
- BUFFER_SIZE can be tuned at compile time
- Returns NULL on EOF or error; caller must free each returned line
