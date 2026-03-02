/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:01:01 by adriescr          #+#    #+#             */
/*   Updated: 2025/11/24 15:21:10 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ENGLISH: Counts the number of arguments in a NULL-terminated array of
 * 			strings.
 * SPANISH: Cuenta el número de argumentos en un array de cadenas terminado
 *			en NULL.
 *
 * @param args The NULL-terminated array of strings.
 *			/ El array de cadenas terminado en NULL.
 *
 * @return The number of arguments. / El número de argumentos.
 */
int	ft_count_arg(char **args)
{
	int	count;

	count = 0;
	while (args && args[count])
		count++;
	return (count);
}
