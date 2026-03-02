/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_exit_status.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 10:00:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/16 20:50:14 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * ENGLISH: Expands the special variable '$?' in the given argument string,
 *          appending the last exit status to the destination string.
 *
 * SPANISH: Expande la variable especial '$?' en la cadena de argumentos
 * 			dada, añadiendo el último estado de salida a la cadena de
 * 			destino.
 *
 * @param dst   Pointer to the destination string to append the exit
 *              status to. /
 *              Puntero a la cadena de destino donde se añadirá el
 *              estado de salida.
 *
 * @param j     Pointer to the current index in the argument string
 *              (points to '$'). /
 *              Puntero al índice actual en la cadena de argumentos
 *              (apunta a '$').
 *
 * @param data  Pointer to the shell data structure containing the last exit
 *              status. /
 *              Puntero a la estructura de datos del shell que contiene el
 *              último estado de salida.
 *
 * @returns 1 on success, 0 on memory allocation failure. /
 *          1 en caso de éxito, 0 en caso de fallo de asignación de memoria.
 */
int	ft_expand_exit_status(char **dst, int *j, t_data *data)
{
	char	*temp;

	temp = ft_itoa(data->last_exit_status);
	if (!temp)
		return (ERROR);
	if (ft_append(dst, temp) == ERROR)
	{
		free(temp);
		return (ERROR);
	}
	free(temp);
	(*j) += 2;
	return (SUCCESS);
}
