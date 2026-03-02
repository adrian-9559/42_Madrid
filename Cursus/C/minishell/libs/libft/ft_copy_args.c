/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:46:30 by adriescr          #+#    #+#             */
/*   Updated: 2025/09/22 14:47:23 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ENGLISH: Copies an array of strings from src to dst.
 *
 * SPANISH: Copia un array de cadenas de src a dst.
 *
 * @param src   The source array of strings. /
 *              El array de cadenas fuente.
 *
 * @param dst   The destination array of strings. /
 *              El array de cadenas destino.
 *
 * @returns The destination array of strings. /
 *          El array de cadenas destino.
 */
char	**ft_copy_args(char **src, char **dst)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
