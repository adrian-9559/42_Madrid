/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_types_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 23:55:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/12/03 01:06:21 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_TYPES_BONUS_H
# define MINISHELL_TYPES_BONUS_H

/**
 * ENGLISH: Represents the global data structure for the minishell.
 *
 * SPANISH: Representa la estructura de datos global para el minishell.
 *
 * @member argv      The argument vector. /
 *                   El vector de argumentos.
 * @member envp      The environment variables. /
 *                   Las variables de entorno.
 * @member argc      The argument count. /
 *                   El conteo de argumentos.
 * @member cmd_count The number of commands. /
 *                   El número de comandos.
 * @member isatty    Indicates if the shell is running in a terminal. /
 *                   Indica si el shell se está ejecutando en un terminal.
 * @member last_exit_status The exit status of the last executed command. /
 * 						El estado de salida del último comando ejecutado.
 * @member next      Pointer to the next data structure (for linked list). /
 * 					Puntero a la siguiente estructura de datos (para lista
 * 					enlazada).
 */
typedef struct s_data
{
	char			**argv;
	char			**envp;
	int				argc;
	int				cmd_count;
	int				isatty;
	int				last_exit_status;
	struct s_data	*next;
}					t_data;

/**
 * ENGLISH: Represents a command node in the minishell command list.
 *
 * SPANISH: Representa un nodo de comando en la lista de comandos de minishell.
 *
 * @member argv      The argument vector for the command. /
 * 					El vector de argumentos para el comando.
 * @member infd      The input file descriptor. /
 * 					El descriptor de archivo de entrada.
 * @member outfd     The output file descriptor. /
 * 					El descriptor de archivo de salida.
 * @member has_error Indicates if there was an error with the command. /
 * 					Indica si hubo un error con el comando.
 * @member index     The index of the command in the command list. /
 * 					El índice del comando en la lista de comandos.
 * @member op        The operator associated with the command (e.g., pipe,
 * 					redirection). /
 * 					El operador asociado con el comando (por ejemplo, tubería,
 * 					redirección).
 * @member subshell  Pointer to subshell command list for parentheses. /
 * 					Puntero a la lista de comandos del subshell para paréntesis.
 * @member data      Pointer to the global data structure. /
 * 					Puntero a la estructura de datos global.
 * @member next      Pointer to the next command node (for linked list). /
 * 					Puntero al siguiente nodo de comando (para lista enlazada).
 */
typedef struct s_cmd
{
	char			**argv;
	int				infd;
	int				outfd;
	int				has_error;
	int				index;
	int				op;
	struct s_cmd	*subshell;
	t_data			*data;
	struct s_cmd	*next;
}					t_cmd;

#endif /* MINISHELL_TYPES_BONUS_H */
