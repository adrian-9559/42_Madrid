/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_matches_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 01:42:19 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/24 18:51:43 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

/**
 * ENGLISH: Counts the number of files in the directory that match the given
 *          wildcard pattern.
 *
 * SPANISH: Cuenta el número de archivos en el directorio que coinciden con el
 * 		patrón comodín dado.
 *
 * @param pattern The wildcard pattern to match files against. /
 *                El patrón comodín para coincidir con los archivos.
 *
 * @returns The number of matching files. /
 *          El número de archivos que coinciden.
 */
static const char	*find_last_slash(const char *pattern)
{
	size_t	plen;

	plen = ft_strlen(pattern);
	while (plen > 0)
	{
		if (pattern[plen - 1] == '/')
			return (pattern + (plen - 1));
		plen--;
	}
	return (NULL);
}

/**
 * ENGLISH: Extracts the directory path and base pattern from the full pattern.
 *
 * SPANISH: Extrae la ruta del directorio y el patrón base del patrón completo.
 *
 * @param pattern      The full wildcard pattern. /
 *                     El patrón comodín completo.
 * @param dirpath      Pointer to store the extracted directory path. /
 *                     Puntero para almacenar la ruta del directorio extraída.
 * @param base_pattern Pointer to store the extracted base pattern. /
 *                     Puntero para almacenar el patrón base extraído.
 */
static void	get_dir_and_pattern(const char *pattern, char **dirpath,
		const char **base_pattern)
{
	const char	*slash;

	slash = find_last_slash(pattern);
	if (slash)
	{
		*dirpath = ft_substr((char *)pattern, 0, (size_t)(slash - pattern));
		*base_pattern = slash + 1;
	}
	else
	{
		*dirpath = ft_strdup(".");
		*base_pattern = pattern;
	}
}

/**
 * ENGLISH: Counts the number of directory entries that match the base pattern.
 *
 * SPANISH: Cuenta el número de entradas de directorio que coinciden con el
 * 		patrón base.
 *
 * @param dir          The opened directory stream. /
 *                     El flujo de directorio abierto.
 * @param base_pattern The base pattern to match against. /
 *                     El patrón base para coincidir.
 *
 * @returns The number of matching entries. /
 *          El número de entradas que coinciden.
 */
static int	count_dir_matches(DIR *dir, const char *base_pattern)
{
	struct dirent	*entry;
	int				count;

	count = 0;
	entry = readdir(dir);
	while (entry != NULL)
	{
		if ((entry->d_name[0] != '.' || (base_pattern
					&& base_pattern[0] == '.'))
			&& ft_match_pattern(base_pattern, entry->d_name))
			count++;
		entry = readdir(dir);
	}
	return (count);
}

/**
 * ENGLISH: Counts the number of files in the directory specified by the
 *          wildcard pattern that match the pattern.
 *
 * SPANISH: Cuenta el número de archivos en el directorio especificado por el
 * 		patrón comodín que coinciden con el patrón.
 *
 * @param pattern The wildcard pattern specifying the directory and file
 *                pattern. /
 *                El patrón comodín que especifica el directorio y el patrón de
 *                archivo.
 *
 * @returns The number of matching files. /
 *          El número de archivos que coinciden.
 */
int	ft_count_matches(const char *pattern)
{
	DIR			*dir;
	int			count;
	char		*dirpath;
	const char	*base_pattern;

	if (!pattern)
		return (0);
	get_dir_and_pattern(pattern, &dirpath, &base_pattern);
	dir = opendir(dirpath);
	if (!dir)
	{
		free(dirpath);
		return (0);
	}
	count = count_dir_matches(dir, base_pattern);
	closedir(dir);
	free(dirpath);
	return (count);
}
