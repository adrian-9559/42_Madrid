NAME = rush-02

MY_SOURCES = ft_chekers.c \
	     ft_convert.c \
	     ft_putchar.c \
	     ft_read_document.c \
	     ft_rush02.c \
	     main.c \

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CFLAGS += -Wall -Wextra -Werror

CUR_DIR = $(shell pwd)

$(NAME): $(MY_OBJECTS)
	cc $(CFLAGS) $(MY_OBJECTS) -o $(NAME)

$(NAME).o: $(MY_SOURCES)
	cc $(CFLAGS) $(MY_SOURCES) -o $(NAME).o

clean:
	rm -Rf $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)

.PHONY: clean fclean
