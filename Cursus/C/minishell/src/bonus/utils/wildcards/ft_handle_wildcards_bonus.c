/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_wildcards_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 00:36:44 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/24 18:56:09 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

/**
 * ENGLISH: Processes a redirection argument that may contain wildcards.
 *
 * Expands the wildcard pattern in 'arg', appends any matching filenames
 * to 'new_argv', and updates '*new_argc' accordingly. Uses 'data' for
 * context (current working directory, expansion options and error handling).
 *
 * SPANISH: Procesa un argumento de redirección que puede contener comodines.
 *
 * Expande el patrón con comodines en 'arg', añade los nombres de archivo
 * coincidentes a 'new_argv' y actualiza '*new_argc' en consecuencia.
 * Utiliza 'data' como contexto (directorio de trabajo, opciones de
 * expansión y manejo de errores).
 *
 * @param arg The redirection argument that may contain wildcards. /
 *            El argumento de redirección que puede contener comodines.
 * @param new_argv The array where expanded arguments will be appended;
 *                 must have enough space for the new entries. /
 *                 El arreglo donde se añadirán los argumentos expandidos;
 *                 debe tener espacio suficiente para las entradas nuevas.
 * @param new_argc Pointer to the current argument count; updated to reflect
 *                the number of arguments after appending. /
 *                Puntero al contador actual de argumentos; se actualiza
 *                para reflejar el número de argumentos tras añadir.
 * @param data Shell state and utilities used during expansion
 * 				(env, cwd, etc.). /
 *             Estado del shell y utilidades usadas durante la expansión (env,
 *             cwd, etc.).
 *
 * @returns The number of entries appended to new_argv on success, or a
 *          negative value on error. /
 *          El número de entradas añadidas a new_argv en caso de éxito,
 *          o un valor negativo en caso de error.
 */
static int	handle_redir_wildcard(char *arg, char **new_argv, int *new_argc,
		t_data *data)
{
	int		matches;
	char	**temp_matches;

	matches = ft_count_matches(arg);
	if (matches != 1)
	{
		if (matches == 0)
		{
			new_argv[(*new_argc)++] = ft_strjoin("!NOFILE!", arg);
		}
		else if (matches != 0)
		{
			ft_fprintf(2, ERROR_AMBIGUOUS_REDIRECT, arg);
			data->last_exit_status = 1;
			new_argv[(*new_argc)++] = ft_strdup("!AMB_REDIRECT!");
			return (0);
		}
		return (0);
	}
	temp_matches = malloc(sizeof(char *) * matches);
	if (!temp_matches)
		return (-1);
	ft_expand_wildcard(arg, temp_matches, matches);
	new_argv[(*new_argc)++] = temp_matches[0];
	return (free(temp_matches), 0);
}

/**
 * ENGLISH: Expands wildcards in the given argument array and copies them
 *          into a new argument array.
 *
 * SPANISH: Expande los comodines en el arreglo de argumentos dado y los
 *          copia en un nuevo arreglo de argumentos.
 *
 * @param argv     The original argument array. /
 *                 El arreglo de argumentos original.
 * @param new_argv The new argument array to populate with expanded arguments. /
 *                 El nuevo arreglo de argumentos para poblar con los
 *                 argumentos expandidos.
 * @param data     Pointer to the shell data structure. /
 *                 Puntero a la estructura de datos del shell.
 *
 * @returns 0 on success, -1 on memory allocation failure. /
 *          0 en éxito, -1 en fallo de asignación de memoria.
 */
static int	expand_and_copy_args(char **argv, char **new_argv, t_data *data)
{
	int	i;
	int	new_argc;

	i = 0;
	new_argc = 0;
	while (argv[i])
	{
		if (ft_has_wildcards(argv[i]) && !is_prev_heredoc(argv, i))
		{
			if ((is_prev_redir(argv, i) && handle_redir_wildcard(argv[i],
						new_argv, &new_argc, data) == -1)
				|| (!is_prev_redir(argv, i) && ft_process_wildcard(argv[i],
						new_argv, &new_argc) == -1))
			{
				ft_free_matrix(new_argv);
				return (-1);
			}
		}
		else
			new_argv[new_argc++] = ft_strdup(argv[i]);
		i++;
	}
	new_argv[new_argc] = NULL;
	data->argc = new_argc;
	return (0);
}

/**
 * ENGLISH: Handles wildcard expansion in the given argument array.
 *          It expands arguments containing wildcards into matching filenames
 *          from the current directory,
 *          while preserving heredoc delimiters.
 *
 * SPANISH: Maneja la expansión de comodines en el arreglo de argumentos dado.
 *
 *          Expande los argumentos que contienen
 *          comodines en nombres de archivos coincidentes del
 *          directorio actual, preservando
 *          los delimitadores heredoc.
 *
 * @param argv  The original argument array. /
 *              El arreglo de argumentos original.
 *
 * @param data  Pointer to the shell data structure. /
 *              Puntero a la estructura de datos del shell.
 *
 * @returns A new argument array with wildcards expanded,
 *          or the original array
 *          on failure. The caller is responsible for freeing the returned
 *          array. /
 *          Un nuevo arreglo de argumentos con los comodines expandidos,
 *          o el arreglo original en caso de fallo. El llamador es responsable
 *          de liberar el arreglo retornado.
 */
char	**ft_handle_wildcards(char **argv, t_data *data)
{
	int		total_args;
	char	**new_argv;

	if (!argv || !data)
		return (argv);
	total_args = count_total_args(argv);
	new_argv = malloc(sizeof(char *) * (total_args + 1));
	if (!new_argv)
		return (argv);
	if (expand_and_copy_args(argv, new_argv, data) == -1)
	{
		free(new_argv);
		return (argv);
	}
	ft_free_matrix(argv);
	return (new_argv);
}
