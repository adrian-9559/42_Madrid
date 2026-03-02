/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:00:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/09/22 12:53:29 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ENGLISH: Converts an integer to a null-terminated string.
 *
 * SPANISH: Convierte un entero en una cadena terminada en nulo.
 *
 * @param n   The integer to convert. /
 *            El entero a convertir.
 *
 * @returns A pointer to the newly allocated string representing the integer.
 *          / Un puntero a la nueva cadena asignada que representa el entero.
 * @returns	Returns NULL if memory allocation fails. /
 *          Devuelve NULL si la asignación de memoria falla.
 */
char	*ft_itoa(int n)
{
	char	*str;
	int		arr[2];

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	arr[0] = ft_numlen(n);
	str = malloc(sizeof(char) * (arr[0] + 1));
	if (!str)
		return (NULL);
	str[arr[0]] = '\0';
	arr[1] = n < 0;
	if (arr[1])
		n = -n;
	while (--arr[0] >= 0)
	{
		str[arr[0]] = (n % 10) + '0';
		n /= 10;
	}
	if (arr[1])
		str[0] = '-';
	return (str);
}
