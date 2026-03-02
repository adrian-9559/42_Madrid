/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg_content.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 13:30:38 by adriescr          #+#    #+#             */
/*   Updated: 2025/09/28 16:58:49 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * ENGLISH: Prints the content of an argument, handling escaped
 * 			newlines and quoted sections.
 *
 * SPANISH: Imprime el contenido de un argumento, manejando nuevas líneas
 * 			escapadas y secciones entre comillas.
 *
 * @param arg   The argument string to print. /
 * 			La cadena de argumentos a imprimir.
 * @param start The starting index for printing. /
 * 			El índice de inicio para la impresión.
 * @param end   The ending index for printing. /
 * 			El índice de fin para la impresión.
 * @param outfd The file descriptor to write the output to. /
 * 			El descriptor de archivo donde escribir la salida.
 *
 * @returns 0 on success, -1 on error. /
 * 			0 en caso de éxito, -1 en caso de error.
 */
int	ft_print_arg_content(char *arg, int start, int end, int outfd)
{
	int	i;
	int	res;

	i = start;
	while (i < end)
	{
		res = ft_print_escaped_newline(arg, &i, outfd);
		if (res == -1)
			return (-1);
		if (res == 1)
			continue ;
		if (ft_putchar_fd(arg[i], outfd) == -1)
			return (-1);
		i++;
	}
	return (0);
}
