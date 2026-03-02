/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dupenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 18:00:26 by adriescr          #+#    #+#             */
/*   Updated: 2025/11/19 18:43:55 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * ENGLISH: Duplicates the environment variable array.
 *
 * SPANISH: Duplica el array de variables de entorno.
 *
 * @param envp   The original environment variable array. /
 *               El array original de variables de entorno.
 *
 * @returns A newly allocated copy of the environment variable array,
 *          or NULL if allocation fails. /
 *          Una copia recién asignada del array de variables de entorno,
 *          o NULL si la asignación falla.
 */
char	**ft_dupenv(char **envp)
{
	char	**envp_cpy;
	int		i;

	if (!envp || !envp[0])
		return (NULL);
	i = 0;
	while (envp[i])
		i++;
	envp_cpy = malloc((i + 1) * sizeof(char *));
	if (!envp_cpy)
		return (NULL);
	i = -1;
	while (envp[++i])
	{
		envp_cpy[i] = ft_strdup(envp[i]);
		if (!envp_cpy[i])
		{
			while (i > 0)
				free(envp_cpy[--i]);
			free(envp_cpy);
			return (NULL);
		}
	}
	envp_cpy[i] = NULL;
	return (envp_cpy);
}
