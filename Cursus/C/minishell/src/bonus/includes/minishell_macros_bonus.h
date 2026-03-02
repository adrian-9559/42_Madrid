/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_macros_bonus.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 23:55:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/12/03 01:06:21 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_MACROS_BONUS_H
# define MINISHELL_MACROS_BONUS_H

# define SUCCESS 0
# define ERROR 1

// Exit codes
# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1
# define EXIT_MISUSE 2
# define EXIT_COMMAND_NOT_FOUND 127
# define EXIT_PERMISSION_DENIED 126

// File descriptors
# define STDIN_FD 0
# define STDOUT_FD 1
# define STDERR_FD 2

// Prompt and messages
# define SHELL_NAME "minishell"
# define PROMPT_PREFIX "\033[90mminishell:("
# define PROMPT_SUFFIX ")\033[0m> "
# define WELCOME_MSG_TXT "./src/assets/welcome.txt"
# define WELCOME_TEXT "\033[0;34mWelcome to Minishell!\033[0m\n"

// Colors
# define COLOR_RESET "\033[0m"
# define COLOR_RED "\033[0;31m"
# define COLOR_GREEN "\033[0;32m"
# define COLOR_BLUE "\033[0;34m"
# define COLOR_GRAY "\033[90m"
# define COLOR_YELLOW "\033[0;33m"
# define COLOR_CYAN "\033[0;36m"
# define COLOR_MAGENTA "\033[0;35m"

// Error messages
# define ERROR_COMMAND_NOT_FOUND "minishell: %s: command not found\n"
# define ERROR_PERMISSION_DENIED "minishell: Permission denied\n"
# define ERROR_IS_A_DIRECTORY "minishell: %s: Is a directory\n"
# define ERROR_NO_SUCH_FILE "minishell: %s: No such file or directory\n"
# define ERROR_SYNTAX \
	"minishell: \
syntax error near unexpected token `newline'\n"
# define ERROR_SYNTAX_PIPE \
	"minishell: \
syntax error near unexpected token `|'\n"
# define ERROR_SYNTAX_REDIRECT \
	"minishell: \
syntax error near unexpected token `>'\n"
# define ERROR_SYNTAX_TOKEN \
	"minishell: \
syntax error near unexpected token `%s'\n"
# define ERROR_TOO_MANY_ARGS "minishell: too many arguments\n"
# define ERROR_HOME_NOT_SET "minishell: cd: HOME not set\n"
# define ERROR_HEREDOC_DELIMITER "Error: missing delimiter for heredoc\n"
# define ERROR_HEREDOC_PROCESS "Error processing heredoc\n"
# define ERROR_CD_FAIL "minishell: cd: %s: %s\n"
# define ERROR_CD_GETCWD \
	"cd: error retrieving current directory: getcwd: \
cannot access parent directories: %s\n"
# define ERROR_AMBIGUOUS_REDIRECT "minishell: %s: ambiguous redirect\n"
# define ERROR_INVALID_IDENTIFIER \
	"minishell: export: `%s': \
not a valid identifier\n"
# define ERROR_NUM_ARG_REQ "minishell: exit: %s: numeric argument required\n"

// Heredoc
# define HEREDOC_PROMPT "heredoc> "

// OPS
# define OP_NONE 0
# define OP_PIPE 1
# define OP_OR 2
# define OP_AND 3
# define OP_SUBSHELL 4

#endif /* MINISHELL_MACROS_BONUS_H */
