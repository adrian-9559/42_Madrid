/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_subshell_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 00:00:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/12/03 01:12:23 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell_bonus.h"

/**
 * ENGLISH: Finds the matching closing parenthesis for an opening one.
 *
 * SPANISH: Encuentra el paréntesis de cierre correspondiente al de apertura.
 *
 * @param argv  The array of tokens. /
 *              El arreglo de tokens.
 *
 * @param start The index of the opening parenthesis. /
 *              El índice del paréntesis de apertura.
 *
 * @param argc  The total number of tokens. /
 *              El número total de tokens.
 *
 * @returns The index of the matching closing parenthesis, or -1 if not found. /
 *          El índice del paréntesis de cierre correspondiente, o -1 si no
 *          se encuentra.
 */
static int	ft_find_closing_paren(char **argv, int start, int argc)
{
	int	i;
	int	depth;

	i = start + 1;
	depth = 1;
	while (i < argc && depth > 0)
	{
		if (!ft_strcmp(argv[i], "("))
			depth++;
		else if (!ft_strcmp(argv[i], ")"))
			depth--;
		if (depth == 0)
			return (i);
		i++;
	}
	return (-1);
}

/**
 * ENGLISH: Updates all commands in a list to point to the correct data.
 *
 * SPANISH: Actualiza todos los comandos en una lista para apuntar al data
 *          correcto.
 *
 * @param cmd_list  The command list to update. /
 *                  La lista de comandos a actualizar.
 *
 * @param data      The data structure to point to. /
 *                  La estructura de datos a la que apuntar.
 */
static void	ft_update_cmd_data(t_cmd *cmd_list, t_data *data)
{
	t_cmd	*current;

	current = cmd_list;
	while (current)
	{
		current->data = data;
		if (current->subshell)
			ft_update_cmd_data(current->subshell, data);
		current = current->next;
	}
}

/**
 * ENGLISH: Allocates and copies tokens for the subshell.
 *
 * SPANISH: Asigna y copia tokens para el subshell.
 *
 * @param argv  The array of tokens. /
 *              El arreglo de tokens.
 *
 * @param start The index of the opening parenthesis. /
 *              El índice del paréntesis de apertura.
 *
 * @param end   The index of the closing parenthesis. /
 *              El índice del paréntesis de cierre.
 *
 * @returns A new argv array for the subshell, or NULL on error. /
 *          Un nuevo array argv para el subshell, o NULL en caso de error.
 */
static char	**ft_extract_subshell_argv(char **argv, int start, int end)
{
	char	**subshell_argv;
	int		i;
	int		j;

	subshell_argv = malloc(sizeof(char *) * (end - start));
	if (!subshell_argv)
		return (NULL);
	i = start + 1;
	j = 0;
	while (i < end)
	{
		subshell_argv[j] = ft_strdup(argv[i]);
		if (!subshell_argv[j])
		{
			while (--j >= 0)
				free(subshell_argv[j]);
			return (free(subshell_argv), NULL);
		}
		i++;
		j++;
	}
	subshell_argv[j] = NULL;
	return (subshell_argv);
}

/**
 * ENGLISH: Extracts tokens between parentheses and parses them into commands.
 *
 * SPANISH: Extrae tokens entre paréntesis y los parsea en comandos.
 *
 * @param argv  The array of tokens. /
 *              El arreglo de tokens.
 *
 * @param start The index of the opening parenthesis. /
 *              El índice del paréntesis de apertura.
 *
 * @param end   The index of the closing parenthesis. /
 *              El índice del paréntesis de cierre.
 *
 * @param data  The original data structure. /
 *              La estructura de datos original.
 *
 * @returns A command list for the subshell, or NULL on error. /
 *          Una lista de comandos para el subshell, o NULL en caso de error.
 */
static t_cmd	*ft_parse_subshell_tokens(char **argv, int start, int end,
		t_data *data)
{
	t_data	temp_data;
	char	**subshell_argv;
	t_cmd	*result;

	subshell_argv = ft_extract_subshell_argv(argv, start, end);
	if (!subshell_argv)
		return (NULL);
	temp_data = *data;
	temp_data.argc = end - start - 1;
	temp_data.argv = subshell_argv;
	result = ft_parse_input(&temp_data);
	if (result)
		ft_update_cmd_data(result, data);
	ft_free_matrix(subshell_argv);
	return (result);
}

/**
 * ENGLISH: Processes a subshell (command group in parentheses).
 *
 * SPANISH: Procesa un subshell (grupo de comandos entre paréntesis).
 *
 * @param current_cmd  Pointer to the current command. /
 *                     Puntero al comando actual.
 *
 * @param data         The shell data structure. /
 *                     La estructura de datos del shell.
 *
 * @param i            Pointer to current index in argv. /
 *                     Puntero al índice actual en argv.
 *
 * @param cmd_index    Pointer to the command index. /
 *                     Puntero al índice del comando.
 *
 * @returns The index after the closing parenthesis, or -1 on error. /
 *          El índice después del paréntesis de cierre, o -1 en caso de error.
 */
int	ft_process_subshell(t_cmd **current_cmd, t_data *data, int *i,
		int *cmd_index)
{
	int	close_idx;

	(void)cmd_index;
	close_idx = ft_find_closing_paren(data->argv, *i, data->argc);
	if (close_idx == -1)
		return (-1);
	(*current_cmd)->subshell = ft_parse_subshell_tokens(data->argv, *i,
			close_idx, data);
	if (!(*current_cmd)->subshell)
		return (-1);
	*i = close_idx;
	return (0);
}
