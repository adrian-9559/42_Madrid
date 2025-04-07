/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:27:41 by adriescr          #+#    #+#             */
/*   Updated: 2025/03/08 12:27:43 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library_functions.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_recor_string(char *arr)
{
	int	i;

	i = 0;
	while (arr[i] != '\0')
	{
		ft_putchar(arr[i]);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_put_error(char *arr)
{
	int	i;

	i = 0;
	while (arr[i] != '\0')
	{
		write(2, "\033[31m", 5);
		write(2, &arr[i], 1);
		write(2, "\033[0m", 4);
		i++;
	}
	write(2, "\n", 1);
}

/*
	*ft_putchar:
		Es una función que imprime un caracter en la salida estándar.

	*ft_recor_string:
		Es una función que imprime un string en la salida estándar.
		Ideada para crear el numero en string para imprimirlo con esta funcion.

	*ft_put_error:
		Es una función que imprime un string en la salida de error.
*/
