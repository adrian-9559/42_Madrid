# Libft

## Overview
Custom C standard library implementation for 42 Network. Provides reimplementations of common libc functions plus additional utilities and a linked list API.

## Functions

### Character classification (`ft_is*.c`)
`ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`

### String manipulation (`ft_str*.c`)
`ft_strlen`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strlcpy`, `ft_strlcat`, `ft_strdup`, `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_strmapi`, `ft_striteri`

### Memory operations (`ft_mem*.c`, `ft_*.c`)
`ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`

### Conversion and I/O
`ft_atoi`, `ft_itoa`, `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

### Linked list (bonus)
`ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

## Build
```bash
make          # produces libft.a (mandatory functions)
make bonus    # includes bonus linked-list functions
make clean    # removes object files
make fclean   # removes object files and libft.a
make re       # recompiles from scratch
```

## Usage
```c
#include "libft.h"

int main(void)
{
    char *s = ft_strdup("Hello 42");
    ft_putendl_fd(s, 1);
    free(s);
    return (0);
}
```

## Notes
- Compiled as a static library (`libft.a`).
- All functions follow the 42 Norm and use `-Wall -Wextra -Werror`.
- Bonus functions are in files suffixed with `_bonus.c` and compiled separately via `make bonus`.
