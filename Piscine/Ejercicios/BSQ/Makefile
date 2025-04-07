NAME = bsq

MY_SOURCES = \
    main.c \
    ft_put.c \
    ft_map_reader.c \
    ft_checkers.c \
	ft_checkers_2.c \
	ft_counts.c \
	ft_file.c \

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(MY_OBJECTS)
	cc $(CFLAGS) $(MY_OBJECTS) -o $(NAME)

$(NAME).o: $(MY_SOURCES)
	cc $(CFLAGS) $(MY_SOURCES) -o $(NAME).o

clean:
	rm -Rf $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)

.PHONY: clean fclean
