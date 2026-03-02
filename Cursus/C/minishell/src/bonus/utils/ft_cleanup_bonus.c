/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 23:45:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/17 22:30:26 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"

/**
 * ENGLISH: Cleans up the shell data structure and history.
 *
 * SPANISH: Limpia la estructura de datos del shell y el historial.
 *
 * @param data   Pointer to the shell data structure to clean up. /
 *               Puntero a la estructura de datos del shell a limpiar.
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
