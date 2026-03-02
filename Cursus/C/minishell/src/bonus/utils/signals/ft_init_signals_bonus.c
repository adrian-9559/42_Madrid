/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_signals_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 01:30:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/09/28 17:47:25 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

/**
 * ENGLISH: Initializes signal handlers for the shell.
 *
 * SPANISH: Inicializa los manejadores de señales para el shell.
 *
 * SIGINT: Calls sigint_handler to handle Ctrl-C interrupts.
 *         Llama a sigint_handler para manejar interrupciones de
 *         Ctrl-C.
 *
 * SIGQUIT: Ignores Ctrl-\ (quit) signals.
 *          Ignora las señales de Ctrl-\ (salir).
 *
 * SIGPIPE: Ignores broken pipe signals.
 *          Ignora las señales de tubería rota.
 */
void	ft_init_signals(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGPIPE, SIG_IGN);
}
