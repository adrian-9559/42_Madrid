/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_quoted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 13:10:21 by adriescr          #+#    #+#             */
/*   Updated: 2025/09/28 16:57:56 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ENGLISH: Checks if a string is enclosed in matching single or double quotes.
 *
 * SPANISH: Comprueba si una cadena está encerrada entre comillas simples o
 * 			dobles coincidentes.
 *
 * @param arg   The string to check.
 *              La cadena a comprobar.
 *
 * @returns 1 if the string is quoted, 0 otherwise.
 *          1 si la cadena está entre comillas, 0 en caso contrario.
 */
int	ft_is_quoted(const char *arg)
{
	int	len;

	if (!arg)
		return (0);
	len = ft_strlen(arg);
	if (len < 2)
		return (0);
	if ((arg[0] == '"' && arg[len - 1] == '"')
		|| (arg[0] == '\'' && arg[len - 1] == '\''))
		return (1);
	return (0);
}
