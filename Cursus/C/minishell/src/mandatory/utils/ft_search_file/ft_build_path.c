/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:35:06 by adriescr          #+#    #+#             */
/*   Updated: 2025/09/22 16:25:25 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * ENGLISH: Builds a full file path by concatenating a directory and
 * 			an entry name.
 *
 * SPANISH: Construye una ruta de archivo completa concatenando un directorio
 * 			y un nombre de entrada.
 *
 * @param dir    The directory path. /
 *               La ruta del directorio.
 *
 * @param entry  The entry name (file or subdirectory). /
 *               El nombre de la entrada (archivo o subdirectorio).
 *
 * @returns The full path as a newly allocated string, or NULL on allocation
 * 			failure. /
 *          La ruta completa como una cadena recién asignada, o NULL
 * 			en caso de fallo de asignación.
 */
char	*ft_build_path(const char *dir, const char *entry)
{
	size_t	dir_len;
	size_t	entry_len;
	size_t	total_len;
	char	*path;

	dir_len = ft_strlen(dir);
	entry_len = ft_strlen(entry);
	total_len = dir_len + 1 + entry_len + 1;
	path = malloc(total_len);
	if (!path)
		return (NULL);
	ft_memcpy(path, dir, dir_len);
	path[dir_len] = '/';
	ft_memcpy(path + dir_len + 1, entry, entry_len);
	path[dir_len + 1 + entry_len] = '\0';
	return (path);
}
