/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_types.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 01:25:08 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/24 16:57:55 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_TYPES_H
# define MINISHELL_TYPES_H

/**
 * ENGLISH: Represents the global data structure for the minishell.
 *
 * SPANISH: Representa la estructura de datos global para el minishell.
 *
 * @member envp      The environment variables. /
 *                   Las variables de entorno.
 * @member argv      The argument vector. /
 *                   El vector de argumentos.
 * @member argc      The argument count. /
 * 					El conteo de argumentos.
 * @member cmd_count The number of commands. /
 * 					El número de comandos.
 * @member isatty    Indicates if the shell is running in a terminal. /
 * 					Indica si el shell se está ejecutando en un terminal.
 * @member last_exit_status The exit status of the last executed command. /
 * 						El estado de salida del último comando ejecutado.
 */
typedef struct s_data
{
	char			**envp;
	char			**argv;
	int				argc;
	int				cmd_count;
	int				isatty;
	int				last_exit_status;
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
	t_data			*data;
	struct s_cmd	*next;
}					t_cmd;

#endif /* MINISHELL_TYPES_H */
