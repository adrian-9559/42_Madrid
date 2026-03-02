/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_quoted_after_dollar_bonus.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:30:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/12/02 17:35:25 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

/**
 * ENGLISH: Handles expansion when a dollar sign is followed by a quote.
 *          It extracts the content within the quotes and appends it to the
 *          destination string.
 *
 * SPANISH: Maneja la expansión cuando un signo de dólar es seguido por una
 *          comilla. Extrae el contenido dentro de las comillas y lo añade
 *          a la cadena de destino.
 *
 * @param dst Pointer to the destination string. /
 *            Puntero a la cadena de destino.
 * @param arg The argument string containing the dollar sign and quotes. /
 *            La cadena de argumento que contiene el signo de dólar y comillas.
 * @param j   Pointer to the current index in the argument string. /
 *            Puntero al índice actual en la cadena de argumento.
 *
 * @returns SUCCESS on successful expansion, or ERROR on memory allocation
 *          failure. /
 *          SUCCESS en caso de expansión exitosa, o ERROR en caso de fallo.
 */
int	ft_handle_quoted_after_dollar(char **dst, char *arg, int *j)
{
	int		start;
	int		end;
	char	*content;
	char	*escaped;
	int		ret;

	if (!arg[*j + 1] || !arg[*j + 2])
		return ((*j)++, ft_append(dst, "$"));
	start = *j + 2;
	end = start;
	while (arg[end] && arg[end] != arg[*j + 1])
		end++;
	if (arg[end] != arg[*j + 1])
		return ((*j)++, ft_append(dst, "$"));
	content = ft_substr(arg, start, end - start);
	if (!content)
		return (ERROR);
	escaped = ft_escape_quotes(content);
	free(content);
	if (!escaped)
		return (ERROR);
	ret = ft_append(dst, escaped);
	free(escaped);
	*j = end + 1;
	return (ret);
}
