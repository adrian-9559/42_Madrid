/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chekers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:27:05 by adriescr          #+#    #+#             */
/*   Updated: 2025/03/08 12:27:08 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library_functions.h"

int	ft_number_arguments(char *arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] < '0' || arr[i] > '9')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_strlen(char *arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		i++;
	}
	return (i);
}

int	ft_check_dict(char *dict)
{
	int	i;

	i = 0;
	while (dict[i])
	{
		i++;
	}
	if (dict[i - 1] == 't' && dict[i - 2] == 'c' && dict[i - 3] == 'i'
		&& dict[i - 4] == 'd' && dict[i - 5] == '.')
	{
		return (1);
	}
	else
	{
		ft_put_error("Error 10: Invalid dictionary.");
		return (0);
	}
}

/*
	*ft_number_arguments:
		Es una función que verifica si los argumentos son números.
		Si el argumento no es un número, la función devuelve 0.
		Si el argumento es un número, la función devuelve 1.

	*ft_strlen:
		Es una función que devuelve la longitud de un array de caracteres.

*/
