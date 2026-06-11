# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/17 11:32:11 by adriescr          #+#    #+#              #
#    Updated: 2026/06/09 18:23:07 by adriescr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME OF PROGRAM
NAME := Serializer

# COMPILER AND FLAGS
CPP := c++
CPPFLAGS := -Wall -Wextra -Werror -std=c++98

# Dirs
OBJS_DIR := objs
SRCS_DIR := src

# Files
MAIN_FILE := main.cpp

# Source files (main + all .cpp files in src/)
SRC_CPP := $(shell find $(SRCS_DIR) -type f -name "*.cpp")

SRCS := $(MAIN_FILE) $(SRC_CPP)

# Convert source paths like ./dir/file.cpp -> objs/dir/file.o
OBJS := $(patsubst ./%,%,$(SRCS))
OBJS := $(patsubst %.cpp,$(OBJS_DIR)/%.o,$(OBJS))

# Ensure object subdirectories exist before compiling each object
$(OBJS_DIR)/%/.dir:
	@mkdir -p $(dir $@)

# Targets
all: $(NAME)

# Create object directory
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

# Compile source files into object files (handles sources in subdirs)
$(OBJS_DIR)/%.o: ./%.cpp | $(OBJS_DIR)/%/.dir
	@$(CPP) $(CPPFLAGS) -c $< -o $@

# Create per-object directory marker so 'dir' exists
$(OBJS_DIR)/%/.dir:
	@mkdir -p $(dir $@)
	@touch $@

# Link object files to create the final executable
$(NAME): $(OBJS)
	@$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@printf 'Compilación finalizada: ejecutable creado: \033[0;32m%s\033[0m\n' "$(NAME)"

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

# Prevent make from deleting intermediate marker files (.dir)
.SECONDARY:
