/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_var_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:30:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/12/02 17:35:25 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

/**
 * ENGLISH: Expands a variable in the argument string starting at index j.
 *          It handles special cases for quotes, exit status, and process ID.
 *          Otherwise, it expands environment variables.
 *
 * SPANISH: Expande una variable en la cadena de argumento comenzando en el
 *          índice j. Maneja casos especiales para comillas, estado de salida
 *          e ID de proceso. De lo contrario, expande variables de entorno.
 *
 * @param dst  Pointer to the destination string. /
 *             Puntero a la cadena de destino.
 * @param arg  The argument string containing the variable to expand. /
 *             La cadena de argumento que contiene la variable a expandir.
 * @param j    Pointer to the current index in the argument string. /
 *             Puntero al índice actual en la cadena de argumento.
 * @param data Pointer to the shell data structure. /
 *             Puntero a la estructura de datos del shell.
 *
 * @returns SUCCESS on successful expansion, or ERROR on memory allocation
 *          failure. /
 *          SUCCESS en caso de expansión exitosa, o ERROR en caso de fallo.
 */
int	ft_expand_var(char **dst, char *arg, int *j, t_data *data)
{
	if (arg[*j + 1] == '"')
		return (ft_handle_quoted_after_dollar(dst, arg, j));
	if (arg[*j + 1] == '\'')
	{
		*j += 2;
		return (ft_append(dst, "$\'"));
	}
	if (arg[*j + 1] == '?')
		return (ft_expand_exit_status(dst, j, data));
	if (arg[*j + 1] == '$')
		return (ft_expand_pid(dst, j, data));
	return (ft_expand_env_var(dst, arg, j, data));
}
