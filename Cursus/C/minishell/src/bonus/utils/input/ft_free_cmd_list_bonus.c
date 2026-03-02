/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_cmd_list_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 00:00:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/12/03 01:06:21 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

/**
 * ENGLISH: Frees the memory allocated for a command list recursively.
 *
 * SPANISH: Libera la memoria asignada para una lista de comandos
 *          recursivamente.
 *
 * @param cmd_list The command list to free. /
 *                 La lista de comandos a liberar.
 */
void	ft_free_cmd_list(t_cmd *cmd_list)
{
	t_cmd	*tmp;

	while (cmd_list)
	{
		tmp = cmd_list->next;
		if (cmd_list->subshell)
			ft_free_cmd_list(cmd_list->subshell);
		ft_free_matrix(cmd_list->argv);
		free(cmd_list);
		cmd_list = tmp;
	}
}
