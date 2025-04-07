/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacarpio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:59:33 by jacarpio          #+#    #+#             */
/*   Updated: 2025/03/02 21:43:27 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	rush(int *arr_r)
{
	int	arr_p[6][6];

	insert_restrictions(arr_p, arr_r);
	arr_p[0][0] = 8;
	arr_p[0][5] = 8;
	arr_p[5][0] = 8;
	arr_p[5][5] = 8;
	compare_columns_rows_p(arr_p);
	compare_columns_rows_1_2(arr_p);
	compare_columns_rows_2_3(arr_p);
	ft_compares_4(arr_p);
	ft_recor(arr_p);
	return (0);
}
