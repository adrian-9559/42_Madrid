/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:49:52 by adriescr          #+#    #+#             */
/*   Updated: 2025/03/12 16:45:13 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library_functions.h"

void	ft_free_space(char **map, char *arr_fills, int *num_caracters)
{
	free(map);
	free(arr_fills);
	free(num_caracters);
}

int	*ft_num_caracters(char **argv, int i)
{
	int	*num_caracters;

	num_caracters = (int *)malloc(sizeof(int) * 2);
	num_caracters[0] = ft_get_num_header_rows(argv[i]);
	num_caracters[1] = ft_get_document_cols(argv[i]);
	if (num_caracters[0] == -1 || num_caracters[1] == -1)
	{
		ft_put_error("Error 2: Error reading file.\n");
		return (0);
	}
	return (num_caracters);
}

int	main(int argc, char **argv)
{
	char	**map;
	char	*arr_fills;
	int		i;
	int		*num_caracters;

	map = NULL;
	if (argc == 1)
		return (0);
	i = 1;
	while (i < argc)
	{
		num_caracters = ft_num_caracters(argv, i);
		map = ft_map_reader(argv[i], map, num_caracters[0]);
		arr_fills = ft_get_fills(argv[i]);
		if (!num_caracters[0] || num_caracters[0] <= 0 || !map || !arr_fills)
			return (0);
		map = ft_check_map(map, arr_fills, num_caracters);
		ft_put_map(map, num_caracters[0]);
		ft_free_space(map, arr_fills, num_caracters);
		if (i + 1 < argc)
			ft_putchar('\n');
		i++;
	}
	return (1);
}
