/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 13:28:37 by adriescr          #+#    #+#             */
/*   Updated: 2025/03/02 13:28:39 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	ft_num_max_col_row(int *arr)
{
	int	n_1;
	int	n_2;

	n_1 = 0;
	n_2 = 4;
	while (n_2 == 16)
	{
		if ((arr[n_1] + arr[n_2]) > 5)
		{
			return (0);
		}
		else if ((arr[n_1] + arr[n_2]) < 3)
		{
			return (0);
		}
		n_1++;
		n_2++;
	}
	return (1);
}

int	ft_num_arr(int *arr)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (i < 16)
	{
		if (arr[i] >= 1 && arr[i] <= 4)
			count++;
		i++;
	}
	return (count);
}

int	ft_check_data_same(int *arr)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < 16)
	{
		count = 0;
		j = 0;
		while (j < 16)
		{
			if (arr[i] == arr[j])
			{
				count++;
			}
			j++;
		}
		if (count > 8)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*

	ft_num_arr = Devuelve el número de elementos en el array
		que son números entre 1 y 4 para luego comprobar que hay minimo 16.

	ft_num_max_col_row = Comprueba que no haya números repetidos
		en las columnas y filas y que la suma de los números de las columnas y
		filas sea correcta.

	ft_check_data_same = Comprueba que no haya más de 8 números
		iguales en el array.

*/
