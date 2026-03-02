/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sigint_handler_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 18:00:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/09/28 17:44:55 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

/**
 * ENGLISH: Handles the SIGINT signal (Ctrl+C) for the shell.
 *
 * SPANISH: Maneja la señal SIGINT (Ctrl+C) para el shell.
 *
 * @param sig   The signal number. /
 *              El número de señal.
 *
 * rl_on_new_line(): Informs the readline library that a new line is starting. /
 * 					Informa a la biblioteca readline que comienza una nueva
 * 					línea.
 *
 * rl_replace_line("", 0): Replaces the current line in the readline
 * 				buffer with an empty string. /
 * 				 Reemplaza la línea actual en el búfer de readline con una
 * 				cadena vacía.
 *
 * rl_redisplay(): Refreshes the display to show the updated line. /
 * 			  Actualiza la pantalla para mostrar la línea actualizada.
 */
void	sigint_handler(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}
