/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_env_var.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:42:56 by adriescr          #+#    #+#             */
/*   Updated: 2025/09/22 16:34:15 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * ENGLISH: Creates a new environment variable string in the format "NAME=VALUE".
 *
 * SPANISH: Crea una nueva cadena de variable de entorno en el formato
 * 			"NOMBRE=VALOR".
 *
 * @param name   The name of the environment variable. /
 *               El nombre de la variable de entorno.
 *
 * @param value  The value of the environment variable. Can be NULL. /
 *               El valor de la variable de entorno. Puede ser NULL.
 *
 * @returns A newly allocated string in the format "NAME=VALUE" or "NAME"
 * 			if value is NULL, or NULL if allocation fails. /
 *          Una cadena recién asignada en el formato "NOMBRE=VALOR" o
 * 			"NOMBRE" si el valor es NULL, o NULL si la asignación falla.
 */
char	*ft_create_env_var(char *name, char *value)
{
	char	*temp;
	char	*new_var;

	if (value)
	{
		temp = ft_strjoin(name, "=");
		if (!temp)
			return (NULL);
		new_var = ft_strjoin(temp, value);
		free(temp);
		if (!new_var)
			return (NULL);
	}
	else
	{
		new_var = ft_strdup(name);
		if (!new_var)
			return (NULL);
	}
	return (new_var);
}
