/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_envp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 13:59:44 by adriescr          #+#    #+#             */
/*   Updated: 2025/11/08 02:10:11 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

/**
 * ENGLISH: Reallocates the environment variable array to a new size,
 *          duplicating the existing entries up to the new size.
 *
 * SPANISH: Realoca el array de variables de entorno a un nuevo tamaño,
 *          duplicando las entradas existentes hasta el nuevo tamaño.
 *
 * @param envp      The original environment variable array. /
 *                  El array original de variables de entorno.
 *
 * @param new_size  The new size for the environment array. /
 *                  El nuevo tamaño para el array de entorno.
 *
 * @returns A newly allocated environment array of the specified size,
 *          or NULL if allocation fails. /
 *          Un nuevo array de entorno del tamaño especificado,
 *          o NULL si falla la asignación.
 */
char	**ft_realloc_envp(char **envp, int new_size)
{
	char	**new_envp;
	int		i;

	new_envp = malloc(sizeof(char *) * (new_size + 1));
	if (!new_envp)
		return (NULL);
	i = 0;
	while (envp && envp[i] && i < new_size)
	{
		new_envp[i] = ft_strdup(envp[i]);
		if (!new_envp[i])
		{
			while (--i >= 0)
				free(new_envp[i]);
			free(new_envp);
			return (NULL);
		}
		i++;
	}
	new_envp[i] = NULL;
	return (new_envp);
}
