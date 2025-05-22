NAME = pipex

CC = cc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror

MY_SOURCES = \
	ft_pipex.c \
	ft_pipex_utils.c \
	ft_pipex_utils_2.c \
	ft_pipex_utils_3.c \
	ft_pipex_utils_4.c \
	ft_print.c \
	ft_strncmp.c \
	ft_split.c \
	ft_isspace.c \
	ft_strlen.c \
	ft_strdup.c \
	ft_strchr.c \
	ft_strncpy.c \
	ft_memmove.c \
	ft_strcpy.c \
	ft_strcat.c \

MY_OBJECTS = $(MY_SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	$(CC) $(CFLAGS) $(MY_OBJECTS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
