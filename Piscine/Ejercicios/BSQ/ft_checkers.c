/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:09:26 by adriescr          #+#    #+#             */
/*   Updated: 2025/03/12 16:14:14 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library_functions.h"

int	**initialize_map_aux(int *arr_cols_rows, char **map, char obstacle)
{
	int	**map_aux;
	int	i;
	int	j;

	map_aux = (int **)malloc(arr_cols_rows[0] * sizeof(int *));
	i = 0;
	while (i < arr_cols_rows[0])
	{
		map_aux[i] = (int *)malloc(arr_cols_rows[1] * sizeof(int));
		j = 0;
		while (j < arr_cols_rows[1])
		{
			if (map[i][j] == obstacle)
				map_aux[i][j] = 0;
			else if (i == 0 || j == 0)
				map_aux[i][j] = 1;
			else
				map_aux[i][j] = 0;
			j++;
		}
		i++;
	}
	return (map_aux);
}

void	fill_map_aux(int **map_aux, int *num_caracters, char **map, char empty,
		int *max_size, int *max_i, int *max_j)
{
	int	i;
	int	j;
	int	min_val;

	*max_size = 0;
	i = 1;
	while (i < num_caracters[0])
	{
		j = 1;
		while (j < num_caracters[1])
		{
			if (map[i][j] == empty)
			{
				min_val = map_aux[i - 1][j];
				if (map_aux[i][j - 1] < min_val)
					min_val = map_aux[i][j - 1];
				if (map_aux[i - 1][j - 1] < min_val)
					min_val = map_aux[i - 1][j - 1];
				map_aux[i][j] = 1 + min_val;
				if (map_aux[i][j] > *max_size)
				{
					*max_size = map_aux[i][j];
					*max_i = i;
					*max_j = j;
				}
			}
			j++;
		}
		i++;
	}
}

void	fill_largest_square(char **map, int max_size, int max_i, int max_j,
		char full)
{
	int	i;
	int	j;

	i = max_i;
	while (i > max_i - max_size)
	{
		j = max_j;
		while (j > max_j - max_size)
		{
			map[i][j] = full;
			j--;
		}
		i--;
	}
}

void	free_map_aux(int **map_aux, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(map_aux[i]);
		i++;
	}
	free(map_aux);
}

char	**ft_check_map(char **map, char *fill, int *num_caracters)
{
	int	**map_aux;
	int	max_size;
	int	max_i;
	int	max_j;

	map_aux = initialize_map_aux(num_caracters, map, fill[1]);
	fill_map_aux(map_aux, num_caracters, map, fill[0], &max_size, &max_i,
		&max_j);
	fill_largest_square(map, max_size, max_i, max_j, fill[2]);
	free_map_aux(map_aux, num_caracters[0]);
	return (map);
}
