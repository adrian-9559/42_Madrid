/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:36:19 by adriescr          #+#    #+#             */
/*   Updated: 2025/03/08 12:36:22 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library_functions.h"
#include <stdio.h>
#include <unistd.h>

int	ft_rush02(char *dict, char *arr)
{
	t_dict	*arr_dict;
	int		count;

	arr_dict = NULL;
	arr_dict = ft_read_document(dict, arr_dict);
	count = ft_count_digits(arr);
	return (0);
}

/*
	*ft_rush02:
		Recibe el puntero del array enteros.
*/
