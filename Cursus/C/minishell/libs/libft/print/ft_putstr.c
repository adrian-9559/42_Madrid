/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:41:03 by adriescr          #+#    #+#             */
/*   Updated: 2025/09/22 12:52:36 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * ENGLISH: Outputs a string to the standard output.
 *
 * SPANISH: Envía una cadena a la salida estándar.
 *
 * @param str   The string to output. /
 *              La cadena a enviar.
 *
 * @returns 0 on success, -1 on failure. /
 *          0 en caso de éxito, -1 en caso de error.
 */
int	ft_putstr(const char *str)
{
	if (!str)
	{
		ft_putstr_error("Error: NULL string\n");
		return (0);
	}
	while (*str)
	{
		if (ft_putchar(*str) == -1)
		{
			ft_putchar('\n');
			return (-1);
		}
		str++;
	}
	return (0);
}
