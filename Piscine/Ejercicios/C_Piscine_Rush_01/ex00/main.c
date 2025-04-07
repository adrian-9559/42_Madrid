/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:20:47 by adriescr          #+#    #+#             */
/*   Updated: 2025/03/02 19:05:06 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdlib.h>

int	main(int c, char **arr)
{
	int	*arr_p;

	if (c == 2)
	{
		arr_p = ft_converter(arr[1]);
		if (arr_p == NULL)
		{
			ft_put_error("Error 1: Memory allocation failed\n");
			return (1);
		}
		if (ft_check_data_true(arr_p) == 1)
			rush(arr_p);
		else
		{
			ft_put_error("Error 5: Wrong data\n");
			return (0);
		}
		free(arr_p);
	}
	else
	{
		ft_put_error("Error 0: No arguments\n");
	}
	return (0);
}

int	ft_check_data_true(int *arr)
{
	if (ft_num_arr(arr) != 16)
	{
		ft_put_error("Error 2: Wrong number of elements\n");
		return (0);
	}
	if (ft_num_max_col_row(arr) == 0)
	{
		ft_put_error("Error 3: Wrong number in column or row\n");
		return (0);
	}
	if (ft_check_data_same(arr) == 0)
	{
		ft_put_error("Error 4: Exceeds the maximum number "
			"of numbers in the provided restrictions\n");
		return (0);
	}
	return (1);
}

/*

	main = Función principal que recibe un número de argumentos y un array 
		de strings. Si el número de argumentos es 2, llama a ft_converter con el 
			segundo argumento.
		Si ft_converter devuelve NULL, imprime 
			"Error 1: Memory allocation failed" y devuelve 1.
		Si ft_check_data_true devuelve 1, llama a rush con el array de enteros.
		En caso contrario, devuelve 0.

		Si el número de argumentos no es 2, imprime "Error 0: No arguments".

	ft_check_data_true = Comprueba que las restricciones se cumplen.
		Si el número de elementos no es 16, imprime 
		"Error 2: Wrong number of elements" y devuelve 0.

		Si el número máximo en una columna o fila es 0, imprime 
		"Error 3: Wrong number in column or row" y devuelve 0.

		Si hay números repetidos, imprime 
		"Error 4: Exceeds the maximum number of numbers in the 
		provided restrictions" y devuelve 0.

		En caso correcto, devuelve 1.

	Ejecucion: 
		Compilado: 
		"cc main.c rush.c ft_checkers.c ft_putchar.c functions.h ft_converter.c"
		Ejecución: "./a.out "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 " | cat -e"
*/
