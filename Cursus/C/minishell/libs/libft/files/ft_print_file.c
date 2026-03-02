/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 20:44:56 by adriescr          #+#    #+#             */
/*   Updated: 2025/09/22 13:05:58 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * ENGLISH: Prints the contents of a file to the standard output,
 * 			optionally in a specified color.
 *
 * SPANISH: Imprime el contenido de un archivo en la salida estándar,
 * 			opcionalmente en un color especificado.
 *
 * @param filename   The name of the file to read and print. /
 *                   El nombre del archivo a leer e imprimir.
 *
 * @param color      Optional ANSI color code string to print the file content
 *                   in color. /
 *                   Cadena de código de color ANSI opcional para imprimir el
 *                   contenido del archivo en color.
 *                   If NULL, no color is applied. / Si es NULL,
 *                   no se aplica color.
 *
 * @returns          0 on success, -1 if the file could not be opened. /
 *                   0 en caso de éxito, -1 si no se pudo abrir el archivo.
 */
int	ft_print_file(char *filename, char *color)
{
	int		fd;
	char	*line;

	fd = ft_open_file_read(filename);
	if (fd == -1)
		return (-1);
	while (1)
	{
		line = ft_get_next_line(fd);
		if (!line)
			break ;
		if (color)
			ft_putstr(color);
		ft_putstr(line);
		if (color)
			ft_putstr(RESET_COLOR);
		free(line);
	}
	ft_close_file(fd);
	return (0);
}
