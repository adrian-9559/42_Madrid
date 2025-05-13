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

MY_BONUS_SOURCES = \
	ft_putnchar_bonus.c \
	ft_strlen_bonus.c \
	ft_substr_bonus.c \
	ft_strdup_bonus.c \

MY_OBJECTS = $(MY_SOURCES:.c=.o)

all: $(NAME)

bonus: $(MY_OBJECTS) $(MY_BONUS_SOURCES:.c=.o)
	$(AR) $(NAME) $(MY_OBJECTS) $(MY_BONUS_SOURCES:.c=.o)

$(NAME): $(MY_OBJECTS)
	$(AR) $(NAME) $(MY_OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
