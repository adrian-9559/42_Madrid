/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_pwd_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:04:05 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/24 17:30:30 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * ENGLISH: Resolves an absolute target directory by normalizing it.
 *
 * SPANISH: Resuelve un directorio objetivo absoluto normalizándolo.
 *
 * @param target_dir  The target directory string. /
 *                    La cadena del directorio objetivo.
 *
 * @returns The normalized absolute path, or NULL if not absolute. /
 *          La ruta absoluta normalizada, o NULL si no es absoluta.
 */
static char	*resolve_abs_target(const char *target_dir)
{
	if (target_dir && target_dir[0] == '/')
		return (ft_normalize_path((char *)target_dir));
	return (NULL);
}

/**
 * ENGLISH: Resolves a relative target directory based on the old PWD.
 *
 * SPANISH: Resuelve un directorio objetivo relativo basado en el
 * 			antiguo PWD.
 *
 * @param oldpwd      The old PWD directory. /
 *                    El directorio PWD antiguo.
 * @param target_dir  The target directory string. /
 *                    La cadena del directorio objetivo.
 * @param normalize   Whether to normalize the resulting path. /
 *                    Si se debe normalizar la ruta resultante.
 *
 * @returns The resolved path, or NULL on failure. /
 *          La ruta resuelta, o NULL en caso de error.
 */
static char	*resolve_relative_from_old(const char *oldpwd,
		const char *target_dir, int normalize)
{
	char	*joined;
	char	*tmp;
	char	*normalized;

	if (!oldpwd || oldpwd[0] != '/')
		return (NULL);
	joined = ft_strjoin((char *)oldpwd, "/");
	if (!joined)
		return (NULL);
	if (target_dir)
		tmp = ft_strjoin(joined, (char *)target_dir);
	else
		tmp = ft_strdup(joined);
	free(joined);
	if (!tmp)
		return (NULL);
	if (normalize)
	{
		normalized = ft_normalize_path(tmp);
		free(tmp);
		return (normalized);
	}
	return (tmp);
}

/**
 * ENGLISH: Fallback method to get new PWD if other methods fail.
 *
 * SPANISH: Método de reserva para obtener el nuevo PWD si otros métodos
 * 			fallan.
 *
 * @param target_dir  The target directory string. /
 *                    La cadena del directorio objetivo.
 *
 * @returns The current working directory or target_dir, or "/" as last
 * 			resort. / El directorio de trabajo actual o target_dir, o "/"
 * 			como último recurso.
 */
static char	*fallback_newpwd(const char *target_dir)
{
	char	buf[4096];

	if (getcwd(buf, sizeof(buf)))
		return (ft_strdup(buf));
	if (target_dir)
		return (ft_strdup(target_dir));
	return (ft_strdup("/"));
}

/**
 * ENGLISH: Updates the PWD and OLDPWD environment variables based on the
 * 			target directory.
 *
 * SPANISH: Actualiza las variables de entorno PWD y OLDPWD basándose en el
 * 			directorio objetivo.
 *
 * @param oldpwd      The old PWD directory. /
 *                    El directorio PWD antiguo.
 * @param target_dir  The target directory string. /
 *                    La cadena del directorio objetivo.
 * @param envp        A pointer to the environment variables array. /
 *                    Un puntero al array de variables de entorno.
 * @param normalize   Whether to normalize the resulting path. /
 *                    Si se debe normalizar la ruta resultante.
 */
void	ft_update_pwd_env(char *oldpwd, char *target_dir, char ***envp,
		int normalize)
{
	char	*newpwd;

	newpwd = NULL;
	newpwd = resolve_abs_target(target_dir);
	if (!newpwd)
		newpwd = resolve_relative_from_old(oldpwd, target_dir, normalize);
	if (!newpwd)
		newpwd = fallback_newpwd(target_dir);
	if (oldpwd)
		ft_setenv("OLDPWD", oldpwd, envp);
	ft_setenv("PWD", newpwd, envp);
	free(newpwd);
}
