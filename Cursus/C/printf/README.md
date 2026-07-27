# ft_printf

## Overview
Custom implementation of libc's printf. Handles conversions: cspdiuxX% with flags (-0#+ ), width, and precision.

## Files
- `ft_printf.c`: main format parser and dispatcher
- `ft_putchar.c`: write single char
- `ft_putstr.c`: write string
- `ft_putnbr.c`: write signed/unsigned int
- `ft_putnbr_base.c`: write hex (upper/lower) with flag handling
- `ft_putptr.c`: write pointer address
- `ft_putnchar_bonus.c`: write char n times (padding)
- `ft_strlen_bonus.c`, `ft_substr_bonus.c`, `ft_strdup_bonus.c`: string utilities for bonus
- `ft_printf.h`: header with t_flags struct and prototypes

## Build and run
```bash
make          # produces libftprintf.a
make bonus    # includes bonus flag parsing
```

## Usage
```c
#include "ft_printf.h"
ft_printf("Hello %s, value = %d\n", "world", 42);
```

## Notes
- Compiled as a static library (`libftprintf.a`)
- Bonus: supports `-0.#+ ` flags and width/precision for all conversions
- Uses `t_flags` struct to track format state across parse, render, and padding
