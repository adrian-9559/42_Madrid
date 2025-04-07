/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compares.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:29:01 by adriescr          #+#    #+#             */
/*   Updated: 2025/03/02 19:16:20 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	if_j(int arr_p[6][6], int j, int c, int i)
{
	if (j == 0)
	{
		arr_p[j + 1][c] = 1;
		i = j + 1;
		while (i < 4)
		{
			arr_p[i + 1][c] = arr_p[i][c] + 1;
			i++;
		}
	}
	else if (j == 5)
	{
		arr_p[j - 1][c] = 1;
		i = j - 1;
		while (i > 1)
		{
			arr_p[i - 1][c] = arr_p[i][c] + 1;
			i--;
		}
	}
}

void	if_c(int arr_p[6][6], int j, int c, int i)
{
	if (c == 0)
	{
		arr_p[j][c + 1] = 1;
		i = c + 1;
		while (i < 4)
		{
			arr_p[j][i + 1] = arr_p[j][i] + 1;
			i++;
		}
	}
	else if (c == 5)
	{
		arr_p[j][c - 1] = 1;
		i = c - 1;
		while (i > 1)
		{
			arr_p[j][i - 1] = arr_p[j][i] + 1;
			i--;
		}
	}
}

void	compare_4(int arr_p[6][6], int j, int c, int i)
{
	if (arr_p[j][c] == 4)
	{
		if_j(arr_p, j, c, i);
		if_c(arr_p, j, c, i);
	}
}

void	compare_1(int arr_p[6][6], int j, int c)
{
	if (arr_p[j][c] == 1)
	{
		if (j == 0)
		{
			arr_p[j + 1][c] = 4;
		}
		else if (j == 5)
		{
			arr_p[j - 1][c] = 4;
		}
		else if (c == 0)
		{
			arr_p[j][c + 1] = 4;
		}
		else if (c == 5)
		{
			arr_p[j][c - 1] = 4;
		}
	}
}

void	compare_columns_rows_p(int arr_p[6][6])
{
	int	j;
	int	c;
	int	i;

	j = 0;
	c = 0;
	i = 0;
	while (j < 6)
	{
		c = 0;
		while (c < 6)
		{
			compare_4(arr_p, j, c, i);
			compare_1(arr_p, j, c);
			c++;
		}
		j++;
	}
}
