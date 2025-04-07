/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:51:02 by adriescr          #+#    #+#             */
/*   Updated: 2025/03/12 17:15:53 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library_functions.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_error(char *arr)
{
	int	i;

	i = 0;
	while (arr[i] != '\0')
	{
		write(2, "\033[31m", 5);
		write(2, &arr[i], 1);
		write(2, "\033[0m", 4);
		i++;
	}
}

void	ft_put_map(char **map, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		write(1, map[i], ft_strlen(map[i]));
		write(1, "\n", 1);
		i++;
	}
}
