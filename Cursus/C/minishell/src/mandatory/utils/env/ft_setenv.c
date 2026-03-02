/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:00:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/16 22:36:25 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * ENGLISH: Sets or updates an environment variable in the environment array.
 *          If the variable exists, its value is updated. If it does not exist,
 *          a new variable is added to the array.
 *
 * SPANISH: Establece o actualiza una variable de entorno en el
 *          array de entorno.
 *          Si la variable existe, su valor se actualiza. Si no existe,
 *          se añade una nueva variable al array.
 *
 * @param name   The name of the environment variable to set or update. /
 *               El nombre de la variable de entorno a establecer o actualizar.
 *
 * @param value  The value to set for the environment variable. Can be NULL. /
 *               El valor a establecer para la variable de entorno.
 * 				Puede ser NULL.
 *
 * @param envp   Pointer to the environment variable array. /
 *               Puntero al array de variables de entorno.
 *
 * @returns 0 on success, -1 on failure (e.g., memory allocation failure). /
 *          0 en caso de éxito, -1 en caso de fallo (p.ej., fallo en
 * 			la asignación de memoria).
 */
int	ft_setenv(char *name, char *value, char ***envp)
{
	char	*new_var;
	char	**new_envp;
	int		envp_size;
	int		ret;

	if (!name || !envp || !*envp)
		return (-1);
	ret = ft_update_existing_env(name, value, *envp);
	if (ret == 0)
		return (0);
	else if (ret == -1)
		return (-1);
	envp_size = ft_count_arg(*envp);
	new_envp = ft_realloc_envp(*envp, envp_size + 1);
	if (!new_envp)
		return (-1);
	new_var = ft_create_env_var(name, value);
	if (!new_var)
		return (ft_free_matrix(new_envp), -1);
	new_envp[envp_size] = new_var;
	new_envp[envp_size + 1] = NULL;
	ft_free_matrix(*envp);
	*envp = new_envp;
	return (0);
}
