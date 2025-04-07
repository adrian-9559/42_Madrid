/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compares_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 19:17:02 by adriescr          #+#    #+#             */
/*   Updated: 2025/03/02 22:00:58 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	contar_coincidencias(int fila[], int condiciones[])
{
	int	coincidencias;
	int	i;

	coincidencias = 0;
	i = 0;
	while (i < 6)
	{
		if (fila[i] == condiciones[i])
		{
			coincidencias++;
		}
		i++;
	}
	return (coincidencias);
}

void	completar_fila(int fila[], int condiciones[])
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (fila[i] == 0)
		{
			fila[i] = condiciones[i];
		}
		i++;
	}
}

void	ft_compares_4(int arr_p[6][6])
{
	int	haszero;
	int	i;
	int	j;

	while (1)
	{
		haszero = 0;
		i = 0;
		while (i < 6 && !haszero)
		{
			j = 0;
			while (j < 6 && !haszero)
			{
				if (arr_p[i][j] == 0)
					haszero = 1;
				j++;
			}
			i++;
		}
		if (!haszero)
			break ;
		ft_compares_4_row(arr_p);
	}
}
