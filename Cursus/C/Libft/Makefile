NAME = libft.a

MY_SOURCES = \
	isalpha.c \
	isdigit.c \
	isalnum.c \
	isascii.c \
	isprint.c \
	strlen.c \
	memset.c \
	bzero.c \
	memcpy.c \
	memmove.c \
	strlcpy.c \
	strlcat.c \
	toupper.c \
	tolower.c \
	strchr.c \
	strrchr.c \
	strncmp.c \
	memchr.c \
	memcmp.c \
	strnstr.c \
	atoi.c \

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
