/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:31:10 by adriescr          #+#    #+#             */
/*   Updated: 2025/09/22 12:53:40 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ENGLISH: Calculates the number of digits in an integer,
 *          including the sign for negative numbers.
 *
 * SPANISH: Calcula el número de dígitos en un entero,
 *          incluyendo el signo para números negativos.
 *
 * @param n   The integer to evaluate. /
 *            El entero a evaluar.
 *
 * @returns The number of digits in the integer. /
 *          El número de dígitos en el entero.
 */
int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
