/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:38:31 by adriescr          #+#    #+#             */
/*   Updated: 2025/03/08 12:38:33 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library_functions.h"

int	ft_count_digits(char *arr)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (arr[i] != '\0')
	{
		if (arr[i] >= '0' && arr[i] <= '9')
			count++;
		else
			return (0);
		i++;
	}
	return (count);
}
