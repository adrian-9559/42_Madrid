/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_env_expansion_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 10:00:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/24 18:39:45 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

/**
 * ENGLISH: Checks if the previous argument is a redirection operator.
 *
 * SPANISH: Verifica si el argumento anterior es un operador de redirección.
 *
 * @param argv  The array of argument strings. /
 *              El arreglo de cadenas de argumentos.
 *
 * @param i     The current index in the argument array. /
 *              El índice actual en el arreglo de argumentos.
 *
 * @returns 1 if the previous argument is a redirection operator, 0 otherwise. /
 *          1 si el argumento anterior es un operador de redirección, 0 en
 *          caso contrario.
 */
static int	ft_prev_redir(char **argv, int i)
{
	if (i == 0)
		return (0);
	if (ft_strcmp(argv[i - 1], "<<") == 0 || ft_strcmp(argv[i - 1], "<") == 0
		|| ft_strcmp(argv[i - 1], ">") == 0 || ft_strcmp(argv[i - 1],
			">>") == 0)
		return (1);
	return (0);
}

/**
 * ENGLISH: Handles environment variable expansion for an array of argument
 *          strings, returning a new array with expanded values.
 *
 * SPANISH: Maneja la expansión de variables de entorno para un arreglo de
 *          cadenas de argumentos, devolviendo un nuevo arreglo con los
 *          valores expandidos.
 *
 * @param argv  The original array of argument strings. /
 *              El arreglo original de cadenas de argumentos.
 *
 * @param data  Pointer to the shell data structure containing environment
 *              variables. /
 *              Puntero a la estructura de datos del shell que contiene las
 *              variables de entorno.
 *
 * @returns A new array of argument strings with expanded environment variables,
 *          or the original array on memory allocation failure. /
 *          Un nuevo arreglo de cadenas de argumentos con las variables de
 *          entorno expandidas, o el arreglo original en caso de fallo de
 *          asignación de memoria.
 */
char	**ft_handle_env_expansion(char **argv, t_data *data)
{
	int		i;
	char	**new_argv;

	if (!argv || !data || !data->envp)
		return (argv);
	new_argv = malloc(sizeof(char *) * (data->argc + 1));
	if (!new_argv)
		return (argv);
	i = -1;
	while (argv[++i])
	{
		if (ft_prev_redir(argv, i))
			new_argv[i] = ft_strdup(argv[i]);
		else
			new_argv[i] = ft_process_arg(argv[i], data);
		if (!new_argv[i])
		{
			ft_free_matrix(new_argv);
			return (argv);
		}
	}
	new_argv[i] = NULL;
	ft_free_matrix(argv);
	return (new_argv);
}
