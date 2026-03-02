/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:09:15 by adriescr          #+#    #+#             */
/*   Updated: 2025/11/24 17:04:32 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ENGLISH: Converts a string to an integer.
 * 			It handles optional leading whitespace, an optional '+' or '-' sign,
 * 			and numeric digits. The conversion stops at the first non-digit
 * 			character.
 * SPANISH: Convierte una cadena a un entero.
 * 			Procesa espacios en blanco iniciales opcionales, un signo '+' o '-'
 * 			opcional, y dígitos numéricos. La conversión se detiene en el primer
 * 			caracter que no sea un dígito.
 *
 * @param str The string to convert. / La cadena a convertir.
 *
 * @return The converted integer value. / El valor entero convertido.
 */
int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
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
