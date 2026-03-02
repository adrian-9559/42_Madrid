/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_directory_path.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:44:08 by adriescr          #+#    #+#             */
/*   Updated: 2025/09/22 16:43:59 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * ENGLISH: Replaces the home directory path in the given PWD
 * 			with a tilde (~) if applicable.
 *
 * SPANISH: Reemplaza la ruta del directorio home en el PWD
 * 			dado por una tilde (~) si es aplicable.
 *
 * @param pwd   The present working directory path. /
 *              La ruta del directorio de trabajo actual.
 *
 * @param home  The home directory path. /
 *              La ruta del directorio home.
 *
 * @returns A new string with the home replaced by ~,
 * 			or NULL if not applicable. /
 *          Una nueva cadena con el home reemplazado por ~,
 * 			o NULL si no es aplicable.
 */
static char	*ft_replace_home_with_tilde(const char *pwd, const char *home)
{
	int		home_len;
	int		pwd_len;
	char	*result;

	home_len = ft_strlen(home);
	pwd_len = ft_strlen(pwd);
	if (pwd_len == home_len)
		return (ft_strdup("~"));
	else if (pwd[home_len] == '/')
	{
		result = malloc(pwd_len - home_len + 2);
		if (!result)
			return (ft_strdup(pwd));
		result[0] = '~';
		ft_strcpy(result + 1, pwd + home_len);
		return (result);
	}
	return (NULL);
}

/**
 * ENGLISH: Gets the current directory path, replacing the home
 * 			directory with a tilde (~) if applicable.
 *
 * SPANISH: Obtiene la ruta del directorio actual, reemplazando el
 * 			directorio home por una tilde (~) si es aplicable.
 *
 * @param envp  The environment variables. /
 *              Las variables de entorno.
 *
 * @returns A string with the current directory path, home replaced
 * 			by ~ if applicable. /
 *          Una cadena con la ruta del directorio actual, home reemplazado
 * 			por ~ si aplica.
 */
char	*ft_get_directory_path(char **envp)
{
	char	*pwd;
	char	*home;
	char	*result;

	pwd = ft_getenv("PWD", envp);
	if (!pwd || !*pwd)
		return (ft_strdup("(unknown)"));
	home = ft_getenv("HOME", envp);
	if (!home)
		return (ft_strdup(pwd));
	if (ft_strncmp(pwd, home, ft_strlen(home)) == 0)
	{
		result = ft_replace_home_with_tilde(pwd, home);
		if (result)
			return (result);
	}
	return (ft_strdup(pwd));
}
