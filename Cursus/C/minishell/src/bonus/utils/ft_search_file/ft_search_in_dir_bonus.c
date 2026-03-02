/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_in_dir_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:26:48 by adriescr          #+#    #+#             */
/*   Updated: 2025/11/19 20:04:22 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

/**
 * ENGLISH: Searches for a file with the given name in the
 * 			specified directory stream.
 *
 * SPANISH: Busca un archivo con el nombre dado en el flujo de
 * 			directorio especificado.
 *
 * @param d        Pointer to the opened directory stream. /
 *                 Puntero al flujo de directorio abierto.
 *
 * @param dir      Path to the directory being searched. /
 *                 Ruta al directorio que se está buscando.
 *
 * @param filename Name of the file to search for. /
 *                 Nombre del archivo a buscar.
 *
 * @returns A newly allocated string with the full path if found,
 *          NULL otherwise. /
 *          Una cadena recién asignada con la ruta completa si
 *          se encuentra, NULL en caso contrario.
 */
static char	*search_file_in_entries(DIR *d, const char *dir,
	const char *filename)
{
	struct dirent	*entry;
	char			*result;

	result = NULL;
	entry = readdir(d);
	while (entry)
	{
		if (ft_is_dot_or_dotdot(entry->d_name))
		{
			entry = readdir(d);
			continue ;
		}
		if (ft_strcmp(entry->d_name, filename) == 0)
		{
			result = ft_build_path(dir, entry->d_name);
			break ;
		}
		entry = readdir(d);
	}
	return (result);
}

/**
 * ENGLISH: Searches for a file with the given filename in the specified
 * 			directory.
 *          If not found, recursively searches in subdirectories.
 *
 * SPANISH: Busca un archivo con el nombre dado en el directorio especificado.
 *          Si no se encuentra, busca recursivamente en los subdirectorios.
 *
 * @param dir       The directory to search in. /
 *                  El directorio donde buscar.
 *
 * @param filename  The name of the file to search for. /
 *                  El nombre del archivo a buscar.
 *
 * @returns The full path to the file if found, or NULL if not found. /
 *          La ruta completa al archivo si se encuentra, o NULL si
 *          no se encuentra.
 */
char	*ft_search_in_dir(const char *dir, const char *filename, char **envp)
{
	DIR		*d;
	char	*result;

	d = opendir(dir);
	result = NULL;
	if (!d)
		return (result);
	result = search_file_in_entries(d, dir, filename);
	closedir(d);
	if (!result)
		result = ft_search_in_subdirs(dir, filename, envp);
	return (result);
}
