/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file_write.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:23:10 by adriescr          #+#    #+#             */
/*   Updated: 2025/11/24 15:43:53 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * ENGLISH: Opens a file for writing.
 *          If append is true, it opens the file in append mode;
 *          otherwise, it truncates the file.
 * 		If the file does not exist, it is created with permissions 0644.
 * SPANISH: Abre un archivo para escritura.
 * 		Si append es verdadero, abre el archivo en modo de
 * 		adición; de lo contrario, trunca el archivo.
 * 		Si el archivo no existe, se crea con permisos 0644.
 *
 * @param filename The name of the file to open. /
 * 				El nombre del archivo a abrir.
 * @param append   If true, open in append mode; otherwise, truncate. /
 * 				Si es verdadero, abre en modo de adición; de lo contrario,
 * 				trunca.
 */
int	ft_open_file_write(const char *filename, int append)
{
	int	fd;
	int	flags;

	if (append)
		flags = O_WRONLY | O_CREAT | O_APPEND;
	else
		flags = O_WRONLY | O_CREAT | O_TRUNC;
	fd = open(filename, flags, 0644);
	if (fd < 0)
		return (-1);
	return (fd);
}
