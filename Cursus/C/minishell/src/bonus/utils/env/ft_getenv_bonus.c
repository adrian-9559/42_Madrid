/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 10:26:32 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/09 14:10:44 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

/**
 * ENGLISH: Retrieves the value of an environment variable from the
 * 			environment array.
 *
 * SPANISH: Recupera el valor de una variable de entorno del array de entorno.
 *
 * @param name   The name of the environment variable to retrieve. /
 *               El nombre de la variable de entorno a recuperar.
 *
 * @param envp   The environment variable array. /
 *               El array de variables de entorno.
 *
 * @returns The value of the environment variable, or NULL if not found. /
 *          El valor de la variable de entorno, o NULL si no se encuentra.
 */
char	*ft_getenv(const char *name, char **envp)
{
	size_t	i;
	size_t	len;

	if (!name || !envp)
		return (NULL);
	len = ft_strlen(name);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], name, len) == 0 && envp[i][len] == '=')
			return (&envp[i][len + 1]);
		i++;
	}
	return (NULL);
}
