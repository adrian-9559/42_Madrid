/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_wildcards_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 01:42:14 by agarcia           #+#    #+#             */
/*   Updated: 2025/10/29 17:05:29 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

/**
 * ENGLISH: Checks if the given string contains unquoted wildcard characters
 *          ('*' or '?').
 *
 * SPANISH: Comprueba si la cadena dada contiene caracteres comodín
 *          ('*' o '?') no entre comillas.
 *
 * @param str   The string to check.
 *              La cadena a comprobar.
 *
 * @returns 1 if the string contains unquoted wildcards, 0 otherwise.
 *          1 si la cadena contiene comodines no entre comillas, 0 en
 *          caso contrario.
 */
int	ft_has_wildcards(const char *str)
{
	int		i;
	int		in_quotes;
	char	quote_char;

	i = 0;
	in_quotes = 0;
	quote_char = 0;
	if (!str)
		return (0);
	if (ft_strlen(str) == 1 && str[0] == '*')
		return (1);
	while (str[i])
	{
		if (!in_quotes && (str[i] == '\'' || str[i] == '"'))
		{
			in_quotes = 1;
			quote_char = str[i];
		}
		else if (in_quotes && str[i] == quote_char)
			in_quotes = 0;
		else if (!in_quotes && (str[i] == '*' || str[i] == '?'))
			return (1);
		i++;
	}
	return (0);
}
