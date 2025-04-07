/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 14:10:53 by adriescr          #+#    #+#             */
/*   Updated: 2025/03/02 19:05:48 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdlib.h>

int	*ft_converter(char *arr)
{
	int	i;
	int	*arr_p;
	int	j;

	i = 0;
	j = 0;
	arr_p = (int *)malloc(sizeof(int) * 16);
	if (!arr_p)
		return (NULL);
	while (arr[i] != '\0' && j < 16)
	{
		if (arr[i] >= '1' && arr[i] <= '4')
		{
			arr_p[j] = arr[i] - '0';
			j++;
		}
		i++;
	}
	return (arr_p);
}

void	insert_restrictions(int arr_p[6][6], int *arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			arr_p[i][j] = 0;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 4)
	{
		arr_p[0][i + 1] = arr[i];
		arr_p[5][i + 1] = arr[i + 4];
		arr_p[i + 1][0] = arr[i + 8];
		arr_p[i + 1][5] = arr[i + 12];
		i++;
	}
}

/*

	*ft_converter: Es una funcion que transforma un string 
		en un array de enteros.
			*arr:				Es un string que contiene los numeros 
								a transformar.

			malloc:				Es una funcion que asigna un espacio de memoria.
								Lo que hace es asignar un espacio de memoria 
								para un array de 16 enteros.

			*arr_p:				Es un puntero a un array de enteros.

			return (arr_p): 	Retorna el array de enteros.
			
			return (NULL): 		Retorna NULL si no se pudo asignar el espacio 
								de memoria.

	insert_restrictions: Es una funcion que inserta las restricciones 
		exteriores en un array de 6x6 en las posiciones correctas.
			*arr_p:				Es un array de 6x6 que contiene las 
								restricciones.

			*arr:				Es un array de enteros que contiene las 
								restricciones.

*/
