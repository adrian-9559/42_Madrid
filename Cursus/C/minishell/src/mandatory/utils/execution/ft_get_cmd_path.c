/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:30:20 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/24 17:38:47 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * ENGLISH: Retrieves the full path of a command by searching through the
 * 		directories listed in the PATH environment variable.
 *
 * SPANISH: Recupera la ruta completa de un comando buscando en los
 * 		directorios listados en la variable de entorno PATH.
 *
 * @param cmd   The command to find. /
 * 			El comando a encontrar.
 * @param envp  The environment variables. /
 * 			Las variables de entorno.
 *
 * @returns
 * 		- If the command contains a '/', it is assumed to be a full or relative
 * 		path and is returned as is. /
 * 		Si el comando contiene un '/', se asume que es una ruta completa o
 * 		relativa y se devuelve tal cual.
 *
 * 		- If the command is found in one of the PATH directories and is
 * 		executable, its full path is returned. /
 * 		Si el comando se encuentra en uno de los directorios de PATH y es
 * 		ejecutable, se devuelve su ruta completa.
 *
 * 		- If the command is not found, NULL is returned. /
 * 		Si el comando no se encuentra, se devuelve NULL.
 */
char	*ft_get_cmd_path(char *cmd, char **envp)
{
	char	*temp;
	char	**paths;
	char	*path;
	int		i;

	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	paths = ft_split(ft_getenv("PATH", envp), ':');
	if (!paths)
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		temp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(path, X_OK) == 0)
		{
			ft_free_matrix(paths);
			return (path);
		}
		free(path);
	}
	ft_free_matrix(paths);
	return (NULL);
}
