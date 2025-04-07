/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:23:26 by adriescr          #+#    #+#             */
/*   Updated: 2025/03/08 12:23:31 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library_functions.h"

int	ft_check_data_true(char *arr)
{
	if (ft_number_arguments(arr) != 1)
	{
		ft_put_error("Error 2: Invalid argument.");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	*dict;

	if (argc == 2)
	{
		if (ft_check_data_true(argv[1]) == 1)
		{
			dict = "numbers.dict";
			ft_rush02(dict, argv[1]);
		}
	}
	else if (argc == 3)
	{
		if (ft_check_data_true(argv[2]) == 1)
		{
			dict = argv[1];
			ft_rush02(dict, argv[2]);
		}
	}
	else
	{
		ft_put_error("Error 1: Invalid number of arguments.");
	}
}

/*
	Compilacion con Makefile:
		- make
		- ./rush-02 1234567890

	(A cambiar para controlar si se pasan en diferentes argumentos: argv[1])

	*main:
		Es la función principal del programa.
		Se encarga de verificar si el número de argumentos es correcto y
		si el argumento es válido.

	*ft_check_data_true:
		Es una función que verifica si el argumento es válido.
		Si el argumento no es válido, imprime un mensaje de error y retorna 0.
		Si el argumento es válido, retorna 1.
*/
