/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:46:58 by adriescr          #+#    #+#             */
/*   Updated: 2025/11/24 18:05:44 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * ENGLISH: Cleans up the shell data structure and frees allocated resources.
 *          It also clears the command history.
 *
 * SPANISH: Limpia la estructura de datos del shell y libera los recursos
 *          asignados.
 *          También limpia el historial de comandos.
 *
 * @param data Pointer to the shell data structure. /
 *             Puntero a la estructura de datos del shell.
 */
void	ft_cleanup(t_data *data)
{
	if (data)
	{
		if (data->envp)
			ft_free_matrix(data->envp);
		free(data);
	}
	clear_history();
	rl_clear_history();
}
