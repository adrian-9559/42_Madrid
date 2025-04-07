/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compares_4_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 21:49:19 by adriescr          #+#    #+#             */
/*   Updated: 2025/03/02 23:21:54 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

const int	g_arr_y[12][6] = {
{3, 2, 3, 1, 4, 1},
{3, 1, 3, 2, 4, 1},
{3, 2, 1, 3, 4, 1},
{1, 4, 1, 3, 2, 3},
{1, 4, 2, 3, 1, 3},
{1, 4, 3, 1, 2, 3},
{3, 1, 2, 4, 3, 2},
{3, 2, 3, 4, 1, 2},
{3, 1, 3, 4, 2, 1},
{2, 3, 4, 2, 1, 3},
{2, 1, 4, 3, 2, 3},
{2, 2, 4, 3, 1, 3}
};

const int	g_arr_y_2[10][6] = {
{1, 4, 1, 2, 3, 2},
{1, 4, 2, 1, 3, 2},
{2, 3, 2, 1, 4, 1},
{2, 3, 1, 2, 4, 1},
{2, 1, 4, 2, 3, 2},
{2, 2, 4, 1, 3, 2},
{2, 3, 4, 1, 2, 2},
{2, 3, 2, 4, 1, 2},
{2, 3, 1, 4, 2, 2},
{2, 2, 1, 4, 3, 2},
};

void	recorrido_row(int coincidencias, int column[6],
		const int (*select_g_arr)[6], int size)
{
	int	condiciones[6];
	int	m;
	int	n;

	m = 0;
	while (m < size)
	{
		n = 0;
		while (n < 6)
		{
			condiciones[n] = select_g_arr[m][n];
			n++;
		}
		coincidencias = contar_coincidencias(column, condiciones);
		if (coincidencias == 4)
		{
			completar_fila(column, condiciones);
		}
		m++;
	}
}

void	recorrido_col(int coincidencias, int column[6],
		const int (*select_g_arr)[6], int size)
{
	int	condiciones[6];
	int	m;
	int	n;

	m = 0;
	while (m < size)
	{
		n = 0;
		while (n < 6)
		{
			condiciones[n] = select_g_arr[m][n];
			n++;
		}
		coincidencias = contar_coincidencias(column, condiciones);
		if (coincidencias >= 4 && coincidencias <= 5)
		{
			completar_fila(column, condiciones);
		}
		m++;
	}
}

void	ft_compares_4_col(int arr_p[6][6], int coincidencias)
{
	int	k;
	int	i;
	int	j;
	int	column[6];

	k = 0;
	while (k++ < 6)
	{
		i = 0;
		while (i++ < 6)
		{
			j = -1;
			while (++j, j < 6)
				column[j] = arr_p[j][k];
			recorrido_col(coincidencias, column, g_arr_y, 12);
			recorrido_col(coincidencias, column, g_arr_y_2, 10);
			j = 0;
			while (j++ < 6)
				arr_p[j][k] = column[j];
		}
		j = 0;
		while (j++ < 6)
			arr_p[j][k] = arr_p[j][k];
	}
}

void	ft_compares_4_row(int arr_p[6][6])
{
	int	i;
	int	j;
	int	k;
	int	condiciones[6];
	int	coincidencias;

	i = 1;
	while (i < 5)
	{
		j = 0;
		while (j++ < 12)
		{
			k = 0;
			while (k++ < 6)
				condiciones[k] = g_arr_y[j][k];
			coincidencias = contar_coincidencias(arr_p[i], condiciones);
			if (coincidencias == 4)
				completar_fila(arr_p[i], condiciones);
		}
		recorrido_row(coincidencias, arr_p[i], g_arr_y, 12);
		i++;
	}
	ft_compares_4_col(arr_p, coincidencias);
}
