/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:45:04 by adriescr          #+#    #+#             */
/*   Updated: 2025/03/02 21:44:13 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <unistd.h>

void	ft_putchar(int num)
{
	char	c;

	c = num + '0';
	if (c == '0')
		c = ' ';
	if (c == '8')
		c = ' ';
	write(1, &c, 1);
}

void	ft_recor(int arr_p[6][6])
{
	int	i_p;
	int	i_s;

	i_p = 1;
	while (i_p < 5)
	{
		i_s = 1;
		while (i_s < 5)
		{
			ft_putchar(arr_p[i_p][i_s]);
			if (i_s == 4)
			{
				write(1, "\n", 1);
			}
			else
			{
				write(1, " ", 1);
			}
			i_s++;
		}
		i_p++;
	}
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

/*
	ft_putchar = Muestra por salida estandar un caracter.

	ft_recor = Muestra por salida estandar una matriz de 4x4.

	ft_put_error = Muestra por salida de error estandar un mensaje de error.

*/
