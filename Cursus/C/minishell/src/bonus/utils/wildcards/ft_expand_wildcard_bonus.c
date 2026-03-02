/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_wildcard_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 01:42:17 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/24 18:52:29 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

/**
 * ENGLISH: Finds the last slash in the given pattern.
 *
 * SPANISH: Encuentra la última barra diagonal en el patrón dado.
 *
 * @param pattern The wildcard pattern. /
 *                El patrón comodín.
 *
 * @returns Pointer to the last slash in the pattern, or NULL if none found. /
 *          Puntero a la última barra diagonal en el patrón, o NULL si no se
 *          encuentra ninguna.
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
 * ENGLISH: Loops through the directory entries and collects matching filenames
 * 		based on the base pattern.
 *
 * SPANISH: Recorre las entradas del directorio y recopila los nombres de
 *          archivo que coinciden según el patrón base.
 *
 * @param dir          The opened directory stream. /
 *                     El flujo de directorio abierto.
 * @param matches      Array to store the matching filenames. /
 *                     Matriz para almacenar los nombres de archivo que
 *                     coinciden.
 * @param max_matches  Maximum number of matches to collect. /
 *                     Número máximo de coincidencias a recopilar.
 * @param base_pattern The base pattern to match filenames against. /
 *                     El patrón base para coincidir con los nombres de archivo.
 *
 * @returns The number of matches found. /
 *          El número de coincidencias encontradas.
 */
static int	expand_loop(DIR *dir, char **matches, int max_matches,
		char *base_pattern)
{
	struct dirent	*entry;
	int				count;

	count = 0;
	entry = readdir(dir);
	while (entry && count < max_matches)
	{
		if ((entry->d_name[0] != '.' || (base_pattern
					&& base_pattern[0] == '.'))
			&& ft_match_pattern(base_pattern, entry->d_name))
		{
			matches[count] = ft_strdup((char *)entry->d_name);
			if (!matches[count])
				return (count);
			count++;
		}
		entry = readdir(dir);
	}
	return (count);
}

/**
 * ENGLISH: Builds full file paths by prepending the directory path to each
 *          matched filename.
 *
 * SPANISH: Construye rutas de archivo completas anteponiendo la ruta del
 *          directorio a cada nombre de archivo que coincide.
 *
 * @param matches  Array of matched filenames. /
 *                 Matriz de nombres de archivo que coinciden.
 * @param count    Number of matched filenames. /
 *                 Número de nombres de archivo que coinciden.
 * @param dirpath  The directory path to prepend. /
 *                 La ruta del directorio a anteponer.
 *
 * @returns 0 on success, -1 on memory allocation failure. /
 *          0 en éxito, -1 en fallo de asignación de memoria.
 */
static int	build_full_paths(char **matches, int count, const char *dirpath)
{
	int		i;
	char	*tmp;
	char	*full_path;

	i = 0;
	while (i < count)
	{
		if (ft_strcmp(dirpath, ".") == 0)
			full_path = ft_strdup((char *)matches[i]);
		else
		{
			tmp = ft_strjoin((char *)dirpath, "/");
			if (!tmp)
				return (-1);
			full_path = ft_strjoin(tmp, (char *)matches[i]);
			free(tmp);
		}
		if (!full_path)
			return (-1);
		free(matches[i]);
		matches[i] = full_path;
		i++;
	}
	return (0);
}

/**
 * ENGLISH: Expands the wildcard pattern into matching file paths.
 *
 * SPANISH: Expande el patrón comodín en rutas de archivo que coinciden.
 *
 * @param pattern     The wildcard pattern specifying the directory and file
 *                    pattern. /
 *                    El patrón comodín que especifica el directorio y el
 *                    patrón de archivo.
 * @param matches     Array to store the matching file paths. /
 *                    Matriz para almacenar las rutas de archivo que coinciden.
 * @param max_matches Maximum number of matches to collect. /
 *                    Número máximo de coincidencias a recopilar.
 *
 * @returns The number of matches found. /
 *          El número de coincidencias encontradas.
 */
int	ft_expand_wildcard(const char *pattern, char **matches, int max_matches)
{
	DIR			*dir;
	int			count;
	char		*dirpath;
	const char	*base_pattern;

	count = 0;
	if (!pattern)
		return (0);
	get_dir_and_pattern(pattern, &dirpath, &base_pattern);
	dir = opendir(dirpath);
	if (!dir)
	{
		free(dirpath);
		return (0);
	}
	count = expand_loop(dir, matches, max_matches, (char *)base_pattern);
	closedir(dir);
	if (count > 0)
		build_full_paths(matches, count, dirpath);
	free(dirpath);
	return (count);
}
