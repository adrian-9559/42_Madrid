/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 19:51:29 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/20 19:53:14 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

/**
 * ENGLISH: Creates and initializes a new command node for the command list.
 *           Sets default values for argv, file descriptors, error flag,
 *           index, and next pointer.
 *
 * SPANISH: Crea e inicializa un nuevo nodo de comando para la lista de
 * 			comandos.
 *           Establece valores predeterminados para argv, descriptores de
 *           archivo, bandera de error, índice y puntero siguiente.
 *
 * @param index    The index to assign to the new command node.
 *                 El índice que se asignará al nuevo nodo de comando.
 *
 * @returns A pointer to the newly created t_cmd node, or NULL on failure.
 *          Un puntero al nuevo nodo t_cmd creado, o NULL en caso de error.
 */
t_cmd	*ft_create_cmd_node(int index)
{
	t_cmd	*new_cmd;

	new_cmd = malloc(sizeof(t_cmd));
	if (!new_cmd)
		return (NULL);
	new_cmd->argv = NULL;
	new_cmd->infd = STDIN_FILENO;
	new_cmd->outfd = STDOUT_FILENO;
	new_cmd->has_error = 0;
	new_cmd->index = index;
	new_cmd->next = NULL;
	return (new_cmd);
}

/**
 * ENGLISH: Adds an argument to the command's argv array, reallocating
 * 			memory as needed.
 *
 * SPANISH: Añade un argumento al arreglo argv del comando, realojando
 *  		memoria según sea necesario.
 *
 * @param cmd   Pointer to the command structure to update.
 *               Puntero a la estructura de comando a actualizar.
 *
 * @param arg   The argument string to add to the command's argv.
 *               La cadena de argumentos que se añadirá al argv del
 *               comando.
 *
 * @returns void.
 */
void	ft_add_arg_to_cmd(t_cmd *cmd, char *arg)
{
	int		count;
	char	**new_argv;

	if (!cmd || !arg)
		return ;
	if (!cmd->argv)
	{
		cmd->argv = malloc(2 * sizeof(char *));
		if (!cmd->argv)
			return ;
		cmd->argv[0] = arg;
		cmd->argv[1] = NULL;
		return ;
	}
	count = ft_count_arg(cmd->argv);
	new_argv = malloc((count + 2) * sizeof(char *));
	if (!new_argv)
		return ;
	ft_copy_args(cmd->argv, new_argv);
	new_argv[count] = arg;
	new_argv[count + 1] = NULL;
	free(cmd->argv);
	cmd->argv = new_argv;
}
