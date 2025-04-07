/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 13:13:17 by adriescr          #+#    #+#             */
/*   Updated: 2025/03/02 23:18:10 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

void	ft_recor(int arr_p[6][6]);
int		ft_num_arr(int *arr);
int		ft_num_max_col_row(int *arr);
int		ft_check_data_true(int *arr);
int		ft_check_data_same(int *arr);
void	insert_restrictions(int arr_p[6][6], int *arr);
void	ft_put_error(char *arr);
int		rush(int *arr);
int		*ft_converter(char *arr);
void	compare_columns_rows_p(int arr_p[6][6]);
void	compare_columns_rows_1_2(int arr_s[6][6]);
void	compare_columns_rows_2_3(int arr_s[6][6]);
void	ft_compares_4(int arr_p[6][6]);
void	ft_compares_4_row(int arr_p[6][6]);
int		contar_coincidencias(int fila[], int condiciones[]);
void	completar_fila(int fila[], int condiciones[]);

#endif

/*

    Fichero que define las funciones que se utilizan en el programa.

*/
