/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file_read.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:22:22 by adriescr          #+#    #+#             */
/*   Updated: 2025/09/22 12:48:44 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * ENGLISH: Opens a file for reading.
 *
 * SPANISH: Abre un archivo para lectura.
 *
 * @param filename   The name of the file to open. /
 *                   El nombre del archivo a abrir.
 *
 * @returns The file descriptor for the opened file, or -1 on failure. /
 *          El descriptor de archivo para el archivo abierto, o -1
 *          en caso de error.
 */
int	ft_open_file_read(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}
