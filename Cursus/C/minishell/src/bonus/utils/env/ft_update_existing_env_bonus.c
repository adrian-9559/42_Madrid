/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_existing_env.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:02:26 by adriescr          #+#    #+#             */
/*   Updated: 2025/11/08 02:10:18 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

/**
 * ENGLISH: Updates the value of an existing environment variable in
 * 			the envp array.
 *
 * SPANISH: Actualiza el valor de una variable de entorno existente
 * 			en el array envp.
 *
 * @param name   The name of the environment variable to update. /
 *               El nombre de la variable de entorno a actualizar.
 *
 * @param value  The new value for the environment variable. Can be NULL. /
 *               El nuevo valor para la variable de entorno. Puede ser NULL.
 *
 * @param envp   The environment variable array. /
 *               El array de variables de entorno.
 *
 * @returns 0 if the variable was updated, 1 if not found, -1 on error. /
 *          0 si la variable fue actualizada, 1 si no se encontró, -1
 * 			en caso de error.
 */
int	ft_update_existing_env(char *name, char *value, char **envp)
{
	int		i;
	int		name_len;
	char	*new_var;

	name_len = ft_strlen(name);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], name, name_len) == 0
			&& (envp[i][name_len] == '=' || envp[i][name_len] == '\0'))
		{
			free(envp[i]);
			new_var = ft_create_env_var(name, value);
			if (!new_var)
				return (-1);
			envp[i] = new_var;
			return (0);
		}
		i++;
	}
	return (1);
}
