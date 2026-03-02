/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_outfile.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 19:30:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/09/22 16:44:25 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * ENGLISH: Opens the given filename for output redirection,
 * 			either in append or truncate mode.
 *
 * SPANISH: Abre el archivo dado para redirección de salida,
 * 			en modo append o truncate.
 *
 * @param filename  The name of the file to open. /
 *                  El nombre del archivo a abrir.
 *
 * @param append    If non-zero, open in append mode; otherwise, truncate. /
 *                  Si es distinto de cero, abre en modo append; si no, trunca.
 *
 * @returns The file descriptor on success, -1 on error. /
 *          El descriptor de archivo en éxito, -1 en error.
 */
int	ft_handle_outfile(char *filename, int append)
{
	int	fd;

	if (append)
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror(filename);
		return (-1);
	}
	return (fd);
}
