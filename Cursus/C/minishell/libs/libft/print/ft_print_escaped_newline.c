/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_escaped_newline.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 13:27:12 by adriescr          #+#    #+#             */
/*   Updated: 2025/09/28 16:58:26 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * ENGLISH: Prints an escaped newline sequence ("\n") if found in the argument
 * 			string.
 *
 * SPANISH: Imprime una secuencia de nueva línea escapada ("\n") si se
 * 			encuentra en la cadena de argumentos.
 *
 * @param arg   The argument string to check for escaped newlines. /
 *              La cadena de argumentos en la que buscar nuevas líneas escapadas.
 *
 * @param i     Pointer to the current index in the argument string. /
 *              Puntero al índice actual en la cadena de argumentos.
 *
 * @param outfd The file descriptor to write the output to. /
 *              El descriptor de archivo donde escribir la salida.
 *
 * @returns 1 if an escaped newline was printed, 0 otherwise, -1 on error. /
 *          1 si se imprimió una nueva línea escapada, 0 en caso contrario,
 * 			-1 en error.
 */
int	ft_print_escaped_newline(const char *arg, int *i, int outfd)
{
	if (arg[*i] == '\\' && arg[*i + 1] == 'n')
	{
		if (ft_putchar_fd('\\', outfd) == -1 || ft_putchar_fd('n', outfd) == -1)
			return (-1);
		*i += 2;
		return (1);
	}
	return (0);
}
