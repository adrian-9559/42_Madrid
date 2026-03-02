/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msg_start_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 20:58:40 by adriescr          #+#    #+#             */
/*   Updated: 2025/11/24 19:02:08 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"

/**
 * ENGLISH: Prints the welcome message at the start of the shell.
 *
 * SPANISH: Imprime el mensaje de bienvenida al iniciar el shell.
 *
 * @param envp The environment variables array. /
 * 			El arreglo de variables de entorno.
 *
 * @returns Always returns 0. /
 *          Siempre retorna 0.
 */
int	ft_msg_start(char **envp)
{
	char	*welcome_msg;

	welcome_msg = ft_search_file(NULL, "welcome_bonus.txt", envp);
	ft_putstr("\x1B"
		"c");
	if (welcome_msg)
	{
		ft_print_file(welcome_msg, COLOR_MAGENTA);
		free(welcome_msg);
	}
	else
		ft_print_file(WELCOME_MSG_TXT, COLOR_MAGENTA);
	ft_putstr("\n");
	ft_putstr(WELCOME_TEXT);
	ft_putstr("\n\n");
	return (0);
}
