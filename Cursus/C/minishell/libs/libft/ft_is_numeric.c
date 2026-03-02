/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_numeric.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 13:38:46 by adriescr          #+#    #+#             */
/*   Updated: 2025/11/24 15:23:48 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ENGLISH: Helper function to check for a valid sign at the start of the
 * 		string. It sets the sign and starting index for further checks.
 *
 * SPANISH: Función auxiliar para verificar un signo válido al inicio de la
 * 		cadena. Establece el signo y el índice de inicio para verificaciones
 * 		adicionales.
 *
 * @param str   The string to check. /
 * 			La cadena a verificar.
 * @param sign  Pointer to store the sign of the number (1 for positive,
 * 			-1 for negative). / Puntero para almacenar el signo del número
 * 			(1 para positivo, -1 para negativo).
 * @param i     Pointer to store the starting index for further checks. /
 * 			Puntero para almacenar el índice de inicio para verificaciones
 * 			adicionales.
 *
 * @returns 1 if a valid sign is found or no sign is present, 0 if the string
 * 			is empty after the sign.
 * 			/ 1 si se encuentra un signo válido o no hay signo presente,
 * 			0 si la cadena está vacía después del signo.
 */
static int	ft_is_valid_sign(const char *str, int *sign, int *i)
{
	*sign = 1;
	*i = 0;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
	if (str[*i] == '\0')
		return (0);
	return (1);
}

/**
 * ENGLISH: Helper function to check if the string represents a valid numeric
 * 		value, ensuring it fits within the range of a long long integer.
 *
 * SPANISH: Función auxiliar para verificar si la cadena representa un valor
 * 		numérico válido, asegurando que se ajuste al rango de un entero largo
 * 		largo.
 *
 * @param str   The string to check. /
 * 			La cadena a verificar.
 * @param i     The starting index for checking numeric characters. /
 * 			El índice de inicio para verificar los caracteres numéricos.
 * @param sign  The sign of the number (1 for positive, -1 for negative). /
 * 			El signo del número (1 para positivo, -1 para negativo).
 *
 * @returns 1 if the string is a valid numeric value within range, 0 otherwise.
 * 			/ 1 si la cadena es un valor numérico válido dentro del rango,
 * 			0 en caso contrario.
 */
static int	ft_is_numeric_body(const char *str, int i, int sign)
{
	long long			result;
	unsigned long long	limit;

	result = 0;
	if (sign == 1)
		limit = LLONG_MAX;
	else
		limit = (unsigned long long)LLONG_MAX + 1ULL;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		if ((unsigned long long)result > (limit - (str[i] - '0')) / 10)
			return (0);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (1);
}

/**
 * ENGLISH: Checks if a string represents a valid numeric value,
 * 		including optional leading '+' or '-' sign, and ensures it fits
 * 		within the range of a long long integer.
 *
 * SPANISH: Verifica si una cadena representa un valor numérico válido,
 * 		incluyendo un signo '+' o '-' opcional al principio, y asegura que
 * 		se ajuste al rango de un entero largo largo.
 *
 * @param str   The string to check. /
 * 			La cadena a verificar.
 *
 * @returns 1 if the string is a valid numeric value within range, 0 otherwise.
 * 			/ 1 si la cadena es un valor numérico válido dentro del rango,
 * 			0 en caso contrario.
 */
int	ft_is_numeric(const char *str)
{
	int	i;
	int	sign;

	if (!str || *str == '\0')
		return (0);
	if (!ft_is_valid_sign(str, &sign, &i))
		return (0);
	return (ft_is_numeric_body(str, i, sign));
}
