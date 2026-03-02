/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:00:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/24 15:24:21 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ENGLISH: Checks if a character is alphanumeric (letter or digit).
 *
 * SPANISH: Verifica si un carácter es alfanumérico (letra o dígito).
 *
 * @param c The character to check. / El carácter a verificar.
 *
 * @returns 1 if the character is alphanumeric, 0 otherwise. /
 *          1 si el carácter es alfanumérico, 0 en caso contrario.
 */
int	ft_isalnum(int c)
{
	return ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a'
			&& c <= 'z'));
}
