/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:04:43 by adriescr          #+#    #+#             */
/*   Updated: 2025/11/24 17:04:52 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ENGLISH: Converts a string to a size_t integer.
 * 		Handles optional leading '+' or '-' signs.
 * 	SPANISH: Convierte una cadena a un entero de tamaño.
 * 		Maneja signos '+' o '-' opcionales al principio.
 *
 * @param str   The string to convert. /
 * 			La cadena a convertir.
 *
 * @return The converted size integer. /
 * 			El entero de tamaño convertido.
 */
size_t	ft_atoll(const char *str)
{
	int		i;
	int		sign;
	size_t	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
