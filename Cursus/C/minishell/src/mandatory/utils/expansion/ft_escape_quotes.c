/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_escape_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:30:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/12/02 17:31:23 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * ENGLISH: Escapes quotes in a string by adding a special marker before them.
 *
 * SPANISH: Escapa las comillas en una cadena añadiendo un marcador especial
 *          antes de ellas.
 *
 * @param str The string to escape. / La cadena a escapar.
 *
 * @returns A new string with escaped quotes, or NULL on memory allocation
 *          failure. /
 *          Una nueva cadena con comillas escapadas, o NULL en caso de fallo.
 */
char	*ft_escape_quotes(char *str)
{
	char	*result;
	int		i;
	int		j;

	result = malloc(ft_strlen(str) * 2 + 1);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
		{
			result[j++] = 1;
			result[j++] = str[i];
		}
		else
			result[j++] = str[i];
		i++;
	}
	result[j] = '\0';
	return (result);
}
