# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/03 18:48:28 by adriescr          #+#    #+#              #
#    Updated: 2025/12/03 01:06:21 by agarcia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Linker flags (use Homebrew readline/ncurses for macOS ARM64)
READLINE_PREFIX = /opt/homebrew/opt/readline
CPPFLAGS = -I$(READLINE_PREFIX)/include
LDFLAGS = -L$(READLINE_PREFIX)/lib -lreadline -lhistory

# Compilator
CC = cc

# Archiver
AR = ar rcs

# Directories
SRC_DIR = src
MANDATORY_DIR = $(SRC_DIR)/mandatory
BONUS_DIR = $(SRC_DIR)/bonus
UTILS_DIR = utils
LIBS_DIR = libs
LIBFT_DIR = $(LIBS_DIR)/libft
OBJ_DIR = objs
OBJ_MANDATORY_DIR = $(OBJ_DIR)/mandatory
OBJ_BONUS_DIR = $(OBJ_DIR)/bonus

# Library files
LIB_NAME = $(LIBFT_DIR)/libft.a

# Main Source Files
MAIN_SOURCE = $(MANDATORY_DIR)/main.c
MAIN_SOURCE_BONUS = $(BONUS_DIR)/main_bonus.c

# Source files
MINISHELL_SRCS = \
	$(MANDATORY_DIR)/ft_minishell.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/ft_cleanup.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/ft_msg_start.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/ft_search_file/ft_is_dot_or_dotdot.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/ft_search_file/ft_search_file.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/ft_search_file/ft_search_in_dir.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/ft_search_file/ft_search_in_subdirs.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/ft_search_file/ft_build_path.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/ft_free_matrix.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/error/ft_handle_error.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/input/ft_read_input.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/input/ft_process_input.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/input/ft_split_input.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/input/ft_check_input_syntax.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/input/ft_parse_input.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/input/parsing_utils/ft_parse_input_node.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/input/parsing_utils/ft_redir.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/input/parsing_utils/ft_has_closing_quote.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/input/parsing_utils/ft_parse_input_pipe.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/input/parsing_utils/ft_remove_quotes.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/input/ft_count_args.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/input/escape/ft_is_escaped.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/input/escape/ft_is_in_quotes.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/input/ft_token_helpers.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/debug/ft_show_debug.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/prompt/ft_get_directory_path.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/prompt/ft_generate_prompt.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/env/ft_dupenv.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/env/ft_getenv.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/env/ft_setenv.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/env/ft_realloc_envp.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/env/ft_create_env_var.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/env/ft_update_existing_env.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/env/ft_update_pwd_env.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/env/ft_normalize_path.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/redirections/ft_handle_infile.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/redirections/ft_handle_outfile.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/execution/ft_exec_bin.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/execution/ft_get_cmd_path.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/execution/ft_finish_execution.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/execution/ft_execute_cmds.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/heredoc/ft_heredoc.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/execution/ft_is_builtin.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/execution/ft_setup_child_io.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/execution/ft_exec_builtin.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/signals/ft_sigint_handler.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/signals/ft_init_signals.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/builtins/ft_echo.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/builtins/ft_cd.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/builtins/ft_pwd.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/builtins/ft_export.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/builtins/ft_unset.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/builtins/ft_env.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/builtins/ft_exit.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/expansion/ft_expansion_utils.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/expansion/ft_expand_exit_status.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/expansion/ft_expand_env_var.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/expansion/ft_expand_pid.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/expansion/ft_process_arg.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/expansion/ft_escape_quotes.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/expansion/ft_handle_quoted_after_dollar.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/expansion/ft_expand_var.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/expansion/ft_handle_env_expansion.c \
	$(MANDATORY_DIR)/$(UTILS_DIR)/expansion/ft_append.c \

MINISHELL_SRCS_BONUS = \
	$(BONUS_DIR)/ft_minishell_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/ft_cleanup_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/ft_msg_start_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/ft_search_file/ft_is_dot_or_dotdot_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/ft_search_file/ft_search_file_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/ft_search_file/ft_search_in_dir_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/ft_search_file/ft_search_in_subdirs_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/ft_search_file/ft_build_path_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/ft_count_args_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/ft_free_matrix_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/error/ft_handle_error_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/input/ft_read_input_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/input/ft_process_input_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/input/ft_split_input_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/input/ft_check_input_syntax_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/input/ft_parse_input_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/input/ft_free_cmd_list_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/input/parsing_utils/ft_parse_input_node_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/input/parsing_utils/ft_redir_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/input/parsing_utils/ft_redir_error_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/input/parsing_utils/ft_parse_input_op_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/input/parsing_utils/ft_parse_input_token_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/input/parsing_utils/ft_parse_subshell_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/input/parsing_utils/ft_remove_quotes_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/input/parsing_utils/ft_has_closing_quote_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/input/escape/ft_is_escaped_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/input/escape/ft_is_in_quotes_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/input/ft_token_helpers_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/wildcards/ft_handle_wildcards_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/wildcards/ft_wildcard_helpers_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/wildcards/ft_count_matches_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/wildcards/ft_expand_wildcard_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/wildcards/ft_has_wildcards_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/wildcards/ft_match_pattern_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/wildcards/ft_sort_strings_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/debug/ft_show_debug_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/prompt/ft_get_directory_path_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/prompt/ft_generate_prompt_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/env/ft_dupenv_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/env/ft_getenv_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/env/ft_setenv_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/env/ft_realloc_envp_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/env/ft_create_env_var_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/env/ft_update_existing_env_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/env/ft_update_pwd_env_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/env/ft_normalize_path_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/redirections/ft_handle_infile_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/redirections/ft_handle_outfile_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/execution/ft_exec_bin_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/execution/ft_get_cmd_path_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/execution/ft_finish_execution_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/execution/ft_execute_cmds_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/execution/ft_exec_builtin_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/execution/ft_is_builtin_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/execution/ft_setup_child_io_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/execution/ft_should_execute_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/execution/ft_execute_subshell_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/heredoc/ft_heredoc_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/signals/ft_sigint_handler_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/signals/ft_init_signals_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/builtins/ft_echo_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/builtins/ft_cd_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/builtins/ft_pwd_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/builtins/ft_export_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/builtins/ft_unset_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/builtins/ft_env_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/builtins/ft_exit_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/expansion/ft_expansion_utils_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/expansion/ft_expand_exit_status_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/expansion/ft_expand_env_var_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/expansion/ft_expand_pid_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/expansion/ft_process_arg_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/expansion/ft_escape_quotes_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/expansion/ft_handle_quoted_after_dollar_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/expansion/ft_expand_var_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/expansion/ft_handle_env_expansion_bonus.c \
	$(BONUS_DIR)/$(UTILS_DIR)/expansion/ft_append_bonus.c \

# Objetos para mandatory y bonus
MAIN_OBJECT = $(MAIN_SOURCE:$(MANDATORY_DIR)/%.c=$(OBJ_MANDATORY_DIR)/%.o)
MINISHELL_OBJS = $(MINISHELL_SRCS:$(MANDATORY_DIR)/%.c=$(OBJ_MANDATORY_DIR)/%.o)

MAIN_OBJECT_BONUS = $(MAIN_SOURCE_BONUS:$(BONUS_DIR)/%.c=$(OBJ_BONUS_DIR)/%.o)
MINISHELL_OBJS_BONUS = $(MINISHELL_SRCS_BONUS:$(BONUS_DIR)/%.c=$(OBJ_BONUS_DIR)/%.o)

all: $(LIB_NAME) $(NAME)
	@echo "\033[35m$(NAME) executable is ready to use!\033[0m"

# Compile the library
$(LIB_NAME):
	@$(MAKE) -C $(LIBFT_DIR)

# Compile the project
$(NAME): $(MINISHELL_OBJS) $(MAIN_OBJECT)
	@$(CC) $(CFLAGS) $(MINISHELL_OBJS) $(MAIN_OBJECT) $(LIB_NAME) $(LDFLAGS) -o $(NAME)
	@if [ $$? -eq 0 ]; then \
		echo "\033[32m✅ Compilation completed successfully!\033[0m"; \
	else \
		echo "\033[31m❌ Error during compilation!\033[0m"; \
	fi

# Compile object files for mandatory
$(OBJ_MANDATORY_DIR)/%.o: $(MANDATORY_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# Compile object files for bonus
$(OBJ_BONUS_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# Compile the bonus project
$(NAME)_bonus: $(MINISHELL_OBJS_BONUS) $(MAIN_OBJECT_BONUS)
	@$(CC) $(CFLAGS) $(MINISHELL_OBJS_BONUS) $(MAIN_OBJECT_BONUS) $(LIB_NAME) $(LDFLAGS) -o $(NAME)_bonus
	@if [ $$? -eq 0 ]; then \
		echo "\033[32m✅ Bonus compilation completed successfully!\033[0m"; \
	else \
		echo "\033[31m❌ Error during bonus compilation!\033[0m"; \
	fi

bonus: $(LIB_NAME) $(NAME)_bonus
	@echo "\033[35m$(NAME)_bonus executable is ready to use!\033[0m"

# Clean up object files
clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@if [ $$? -eq 0 ]; then \
		echo "\033[32m🧹 Object files cleaned successfully!\033[0m"; \
	else \
		echo "\033[31m❌ Error cleaning object files!\033[0m"; \
	fi

# Clean up object files and the executable
fclean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME) $(NAME)_bonus
	@if [ $$? -eq 0 ]; then \
		echo "\033[32m🗑️  Libraries, objects and executables cleaned successfully!\033[0m"; \
	else \
		echo "\033[31m❌ Error cleaning libraries, objects and executables!\033[0m"; \
	fi

re: fclean
	@echo "\033[34m🔄 Recompiling everything...\033[0m"
	@$(MAKE) --always-make all
	@if [ $$? -eq 0 ]; then \
		echo "\033[38;5;208m🎉 Recompilation completed successfully!\033[0m"; \
	else \
		echo "\033[31m❌ Error during recompilation!\033[0m"; \
	fi

re-bonus: fclean
	@echo "\033[34m🔄 Recompiling bonus everything...\033[0m"
	@$(MAKE) --always-make bonus
	@if [ $$? -eq 0 ]; then \
		echo "\033[38;5;208m🎉 Bonus recompilation completed successfully!\033[0m"; \
	else \
		echo "\033[31m❌ Error during bonus recompilation!\033[0m"; \
	fi

# Phony targets
.PHONY: all clean fclean re bonus re-bonus
