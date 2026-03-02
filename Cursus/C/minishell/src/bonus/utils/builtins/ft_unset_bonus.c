/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 10:00:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/24 18:30:17 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

/**
 * ENGLISH: Checks if the given string is a valid identifier
 * 			for environment variables.
 *
 * SPANISH: Verifica si la cadena dada es un identificador
 * 			válido para variables de entorno.
 *
 * @param arg   The string to check as an identifier. /
 *              La cadena a comprobar como identificador.
 *
 * @returns 1 if valid, 0 otherwise. /
 *          1 si es válido, 0 en caso contrario.
 */
static int	ft_is_valid_identifier(const char *arg)
{
	size_t	len;

	len = ft_strlen(arg);
	if (len == 0)
		return (0);
	if (arg[len - 1] == '=' || arg[len - 1] == '-')
		return (0);
	return (1);
}

/**
 * ENGLISH: Removes an environment variable from the environment array.
 *
 * SPANISH: Elimina una variable de entorno del array de entorno.
 *
 * @param var   The name of the variable to remove. /
 *              El nombre de la variable a eliminar.
 * @param envp  Pointer to the environment array. /
 *              Puntero al array de entorno.
 */
static void	ft_remove_env_var(char *var, char ***envp)
{
	int		j;
	int		k;
	size_t	len;

	len = ft_strlen(var);
	j = 0;
	while ((*envp)[j])
	{
		if (!ft_strncmp((*envp)[j], var, len) && (*envp)[j][len] == '=')
		{
			free((*envp)[j]);
			k = j;
			while ((*envp)[k])
			{
				(*envp)[k] = (*envp)[k + 1];
				k++;
			}
			j--;
		}
		j++;
	}
}

/**
 * ENGLISH: Implements the unset builtin command to remove environment
 * 			variables.
 *
 * SPANISH: Implementa el comando builtin unset para eliminar variables
 * 			de entorno.
 *
 * @param args  The arguments passed to the unset command. /
 *              Los argumentos pasados al comando unset.
 * @param envp  Pointer to the environment array. /
 *              Puntero al array de entorno.
 *
 * @returns 0 on success, 1 on error. /
 *          0 en caso de éxito, 1 en caso de error.
 */
int	ft_unset(char **args, char ***envp)
{
	int	i;

	if (!args || !envp || !*envp)
		return (1);
	i = 1;
	while (args[i])
	{
		if (!ft_is_valid_identifier(args[i]))
		{
			ft_fprintf(2, "minishell: unset: `%s': not a valid identifier\n",
				args[i]);
			return (1);
		}
		ft_remove_env_var(args[i], envp);
		i++;
	}
	return (0);
}
