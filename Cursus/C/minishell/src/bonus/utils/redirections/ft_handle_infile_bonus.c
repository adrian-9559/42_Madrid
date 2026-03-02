/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_infile_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 19:30:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/09/27 22:27:16 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

/**
 * ENGLISH: Opens the given file for reading and returns its file descriptor.
 *           Handles errors if the file cannot be opened.
 *
 * SPANISH: Abre el archivo dado para lectura y devuelve su descriptor de
 * 			archivo. Maneja errores si el archivo no puede ser abierto.
 *
 * @param filename  The name of the file to open. /
 *                  El nombre del archivo a abrir.
 *
 * @returns The file descriptor if successful, -1 otherwise. /
 *          El descriptor de archivo si tiene éxito, -1 en caso contrario.
 */
int	ft_handle_infile(char *filename)
{
	int	fd;

	if (!filename)
		return (-1);
	fd = ft_open_file_read(filename);
	if (fd == -1)
		return (ft_handle_error(4, -1, filename, NULL));
	return (fd);
}
