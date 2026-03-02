/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input_token_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 19:55:03 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/09 14:12:04 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell_bonus.h"

/**
 * ENGLISH: Processes a single token from the input arguments,
 *          updating the current command structure accordingly.
 *          Handles pipes, logical operators, redirections, and arguments.
 *
 * SPANISH: Procesa un solo token de los argumentos de entrada,
 *          actualizando la estructura del comando actual en consecuencia.
 *          Maneja tuberías, operadores lógicos, redirecciones y argumentos.
 *
 * @param current_cmd Pointer to the current command pointer. /
 *                    Puntero al puntero del comando actual.
 *
 * @param argv        The array of input argument tokens. /
 *                    El arreglo de tokens de argumentos de entrada.
 *
 * @param i           The current index in the argv array. /
 *                    El índice actual en el arreglo argv.
 *
 * @param cmd_index   Pointer to the current command index. /
 *                    Puntero al índice del comando actual.
 *
 * @returns The next index to process in the argv array. /
 *          El siguiente índice a procesar en el arreglo argv.
 */

int	ft_process_token(t_cmd **current_cmd, char **argv, int i, int *cmd_index)
{
	char	*clean_arg;

	if (!ft_strcmp(argv[i], "|") || !ft_strcmp(argv[i], "||")
		|| !ft_strcmp(argv[i], "&&") || !ft_strcmp(argv[i], "&"))
	{
		ft_process_op(current_cmd, argv[i], cmd_index, (*current_cmd)->data);
		return (i);
	}
	else if (!ft_strcmp(argv[i], "<") || !ft_strcmp(argv[i], ">")
		|| !ft_strcmp(argv[i], ">>") || !ft_strcmp(argv[i], "<<"))
		return (ft_redir(*current_cmd, argv, i));
	else
	{
		clean_arg = ft_remove_quotes(argv[i]);
		if (!clean_arg)
			return (i);
		ft_add_arg_to_cmd(*current_cmd, clean_arg);
		return (i);
	}
	return (i + 1);
}
