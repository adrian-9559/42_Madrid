/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_arg_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 10:00:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/12/02 17:35:28 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

static void	update_quote_state(char c, int *in_dquote, int *in_squote)
{
	if (c == '"' && !(*in_squote))
		*in_dquote = !(*in_dquote);
	else if (c == '\'' && !(*in_dquote))
		*in_squote = !(*in_squote);
}

static int	process_loop(char *arg, char **dst, t_data *data)
{
	int	j;
	int	start;
	int	in_dquote;
	int	in_squote;

	j = 0;
	in_dquote = 0;
	in_squote = 0;
	while (arg[j])
	{
		start = j;
		while (arg[j] && arg[j] != '$')
		{
			update_quote_state(arg[j], &in_dquote, &in_squote);
			j++;
		}
		if ((ft_copy_literal(dst, arg, start, j) == ERROR) || (arg[j] == '$'
				&& !in_squote && (ft_expand_var(dst, arg, &j, data) == ERROR)))
			return (ERROR);
		if (arg[j] == '$' && in_squote && ft_append(dst, "$") == ERROR)
			return (ERROR);
		if (arg[j] == '$' && in_squote)
			j++;
	}
	return (SUCCESS);
}

/**
 * ENGLISH: Processes an argument string, handling variable expansions and
 * 		literal copying. It returns a new string with all expansions applied.
 *
 * SPANISH: Procesa una cadena de argumento, manejando expansiones de
 * 		variables y copiado literal.
 * 		Devuelve una nueva cadena con todas las expansiones aplicadas.
 *
 * @param arg  The argument string to process. /
 * 			La cadena de argumento a procesar.
 * @param data Pointer to the shell data structure containing environment
 * 			information. /
 * 			Puntero a la estructura de datos del shell que contiene
 * 			información del entorno.
 *
 * @returns A new string with all expansions applied, or NULL on memory
 *          allocation failure. /
 *          Una nueva cadena con todas las expansiones aplicadas, o NULL en
 *          caso de fallo de asignación de memoria.
 */
char	*ft_process_arg(char *arg, t_data *data)
{
	char	*dst;
	char	*tmp;
	int		len;

	if (!arg)
		return (NULL);
	len = ft_strlen(arg);
	if (arg[0] == '\'' && arg[len - 1] == '\'')
		return (ft_substr(arg, 0, len));
	if (len > 3 && arg[0] == '$' && arg[1] == '\'' && arg[len - 1] == '\'')
	{
		tmp = ft_substr(arg, 2, len - 3);
		if (!tmp)
			return (NULL);
		dst = ft_escape_quotes(tmp);
		free(tmp);
		return (dst);
	}
	dst = ft_strdup("");
	if (!dst)
		return (NULL);
	if (process_loop(arg, &dst, data) == ERROR)
		return (free(dst), NULL);
	return (dst);
}
