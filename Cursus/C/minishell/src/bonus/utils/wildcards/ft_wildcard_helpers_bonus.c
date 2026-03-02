/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildcard_helpers_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 01:30:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/24 18:57:44 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

/**
 * ENGLISH: Checks if the previous argument is a redirection operator.
 *
 * SPANISH: Comprueba si el argumento anterior es un operador de redirección.
 *
 * @param a   The array of arguments. /
 *            El arreglo de argumentos.
 * @param idx The current index in the array. /
 *            El índice actual en el arreglo.
 *
 * @returns 1 if the previous argument is a redirection operator, 0 otherwise. /
 *          1 si el argumento anterior es un operador de redirección, 0 en caso
 *          contrario.
 */
int	is_prev_redir(char **a, int idx)
{
	if (idx == 0)
		return (0);
	if (ft_strcmp(a[idx - 1], "<") == 0)
		return (1);
	if (ft_strcmp(a[idx - 1], ">") == 0)
		return (1);
	if (ft_strcmp(a[idx - 1], ">>") == 0)
		return (1);
	return (0);
}

/**
 * ENGLISH: Checks if the previous argument is a heredoc operator.
 *
 * SPANISH: Comprueba si el argumento anterior es un operador heredoc.
 *
 * @param a   The array of arguments. /
 *            El arreglo de argumentos.
 * @param idx The current index in the array. /
 *            El índice actual en el arreglo.
 *
 * @returns 1 if the previous argument is a heredoc operator, 0 otherwise. /
 *          1 si el argumento anterior es un operador heredoc, 0 en caso
 *          contrario.
 */
int	is_prev_heredoc(char **a, int idx)
{
	if (idx == 0)
		return (0);
	if (ft_strcmp(a[idx - 1], "<<") == 0)
		return (1);
	return (0);
}

/**
 * ENGLISH: Counts the total number of arguments after wildcard expansion.
 *
 * SPANISH: Cuenta el número total de argumentos después de la expansión de
 *          comodines.
 *
 * @param argv The original argument array. /
 *             El arreglo de argumentos original.
 *
 * @returns The total number of arguments after expansion. /
 *          El número total de argumentos después de la expansión.
 */
int	count_total_args(char **argv)
{
	int	total_args;
	int	i;
	int	matches;

	total_args = 0;
	i = 0;
	while (argv[i])
	{
		if (ft_has_wildcards(argv[i]))
		{
			matches = ft_count_matches(argv[i]);
			if (matches > 0)
				total_args += matches;
			else
				total_args += 1;
		}
		else
			total_args++;
		i++;
	}
	return (total_args);
}

/**
 * ENGLISH: Processes a single argument for wildcard expansion.
 *          If matches are found, they are added to the new argument array.
 *          If no matches are found, the original argument is added.
 *
 * SPANISH: Procesa un solo argumento para la expansión de comodines.
 *          Si se encuentran coincidencias, se agregan al nuevo arreglo de
 *          argumentos.
 *          Si no se encuentran coincidencias, se agrega el argumento original.
 *
 * @param arg       The argument to process. /
 *                  El argumento a procesar.
 * @param new_argv  The new argument array to store results. /
 *                  El nuevo arreglo de argumentos para almacenar resultados.
 * @param new_argc  Pointer to the current count of arguments in new_argv. /
 *                  Puntero al conteo actual de argumentos en new_argv.
 *
 * @returns 0 on success, -1 on memory allocation failure. /
 *          0 en caso de éxito, -1 en caso de fallo de asignación de memoria.
 */
int	ft_process_wildcard(char *arg, char **new_argv, int *new_argc)
{
	int		matches;
	char	**temp_matches;
	int		k;

	matches = ft_count_matches(arg);
	if (matches > 0)
	{
		temp_matches = malloc(sizeof(char *) * matches);
		if (!temp_matches)
			return (-1);
		matches = ft_expand_wildcard(arg, temp_matches, matches);
		ft_sort_strings(temp_matches, matches);
		k = 0;
		while (k < matches)
		{
			new_argv[(*new_argc)++] = temp_matches[k];
			k++;
		}
		free(temp_matches);
	}
	else
		new_argv[(*new_argc)++] = ft_strdup(arg);
	return (0);
}
