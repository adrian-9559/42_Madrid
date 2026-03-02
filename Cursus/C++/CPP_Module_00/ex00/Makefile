# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/29 13:05:01 by adriescr          #+#    #+#              #
#    Updated: 2025/12/29 13:16:36 by adriescr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME OF PROGRAM
NAME := megaphone

# COMPILER AND FLAGS
CPP := c++
CPPFLAGS := -Wall -Wextra -Werror -std=c++98

# Dirs
OBJS_DIR := objs

# Files
SRCS := megaphone.cpp
OBJS := $(patsubst %.cpp,$(OBJS_DIR)/%.o,$(SRCS))

# Targets
all: $(NAME)

# Create object directory
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

# Compile source files into object files
$(OBJS_DIR)/%.o: %.cpp | $(OBJS_DIR)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

# Link object files to create the final executable
$(NAME): $(OBJS)
	@$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@printf 'Compilación finalizada: ejecutable creado:\033[0;32m %s\033[0m\n' '$(NAME)'

# Clean object files
clean:
	@printf 'Eliminando directorio de objetos: \033[38;5;208m%s\033[0m\n' "$(OBJS_DIR)"
	@rm -rf $(OBJS_DIR)

# Clean executable
fclean: clean
	@printf 'Eliminando ejecutable:\033[0;32m %s\033[0m\n' "$(NAME)"
	@rm -f $(NAME)

# Rebuild the project
re: fclean all

# Other targets
.PHONY: all clean fclean re
