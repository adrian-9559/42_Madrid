NAME = libftprintf.a

CC = cc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror

MY_SOURCES = \
	ft_printf.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putnbr.c \
	ft_putnbr_base.c \
	ft_putptr.c \
	ft_strlen.c \
	ft_ptrlen.c \
	ft_numlen.c \

MY_BONUS_SOURCES = \
	ft_init_flags.c \
	ft_parse_flags.c \
	ft_parse_width_precision.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)
MY_BONUS_OBJECTS = $(MY_BONUS_SOURCES:.c=.o)

all: bonus

bonus: $(MY_OBJECTS) $(MY_BONUS_OBJECTS)
	$(AR) $(NAME) $(MY_OBJECTS) $(MY_BONUS_OBJECTS)
	chmod 755 $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MY_OBJECTS) $(MY_BONUS_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
