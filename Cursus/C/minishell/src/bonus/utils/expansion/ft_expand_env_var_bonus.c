/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_env_var_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 10:00:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/12/02 17:38:10 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

static int	is_invalid_var_char(char c)
{
	if (!c || c == '\'' || c == '"' || c == ' ' || c == '\t')
		return (1);
	return (0);
}

/**
 * ENGLISH: Expands an environment variable in the given argument string.
 *
 * SPANISH: Expande una variable de entorno en la cadena de argumento dada.
 *
 * @param dst   The destination string where the expanded value will be
 *              appended. /
 *              La cadena de destino donde se añadirá el valor expandido.
 *
 * @param arg   The argument string containing the environment variable to
 *              expand.
 *              La cadena de argumento que contiene la variable de entorno a
 *              expandir.
 *
 * @param j     Pointer to the current index in the argument string. /
 *              Puntero al índice actual en la cadena de argumento.
 *
 * @param data  The shell data structure containing environment variables. /
 *              La estructura de datos del shell que contiene las variables
 *              de entorno.
 *
 * @returns SUCCESS on successful expansion, or an error code on failure. /
 *          SUCCESS en caso de expansión exitosa,
 *          o un código de error en caso de fallo.
 */
int	ft_expand_env_var(char **dst, char *arg, int *j, t_data *data)
{
	int		start;
	char	*env_name;
	char	*env_value;

	if (is_invalid_var_char(arg[*j + 1]))
	{
		(*j)++;
		return (ft_append(dst, "$"));
	}
	(*j)++;
	if (ft_is_digit(arg[*j]))
		return ((*j)++, SUCCESS);
	start = *j;
	while (arg[*j] && (ft_isalnum(arg[*j]) || arg[*j] == '_'))
		(*j)++;
	if (*j == start)
		return (ft_append(dst, "$"));
	env_name = ft_substr(arg, start, *j - start);
	env_value = ft_getenv(env_name, data->envp);
	free(env_name);
	if (!env_value || env_value[0] == '\0')
		return (SUCCESS);
	return (ft_append(dst, env_value));
}
