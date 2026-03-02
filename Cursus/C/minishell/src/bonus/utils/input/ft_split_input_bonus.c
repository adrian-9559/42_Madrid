/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_input_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 00:33:34 by agarcia           #+#    #+#             */
/*   Updated: 2025/12/03 01:15:57 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

/**
 * ENGLISH: Handles token extraction from the input string,
 *          updating the current index and argument list.
 *
 * SPANISH: Maneja la extracción de tokens de la cadena de entrada,
 *          actualizando el índice actual y la lista de argumentos.
 *
 * @param input The input string to parse.
 *               La cadena de entrada a analizar.
 *
 * @param args  The array to store extracted tokens.
 *               El arreglo para almacenar los tokens extraídos.
 *
 * @param i     Pointer to the current index in the input string.
 *               Puntero al índice actual en la cadena de entrada.
 *
 * @param j     Pointer to the current index in the args array.
 *               Puntero al índice actual en el arreglo args.
 *
 * @returns 0 on success, -1 on memory allocation failure.
 *          0 en caso de éxito, -1 en caso de fallo de asignación de memoria.
 */
static int	ft_extract_word(const char *input, char **args, int *i, int *j)
{
	int	start;

	start = *i;
	while (input[*i] && (!ft_strchr("<>|()", input[*i])
			|| ft_is_in_quotes(input, *i) || ft_is_escaped(input, *i))
		&& (!ft_isspace(input[*i]) || ft_is_in_quotes(input, *i)))
		*i += 1 + (input[*i] == '\\' && input[*i + 1]);
	if (*i > start)
	{
		args[*j] = ft_substr((char *)input, start, *i - start);
		*j += 1;
	}
	return (0);
}

static int	ft_handle_token(const char *input, char **args, int *i, int *j)
{
	ft_skip_whitespace(input, i);
	if (ft_strchr("<>|()", input[*i]) && !ft_is_escaped(input, *i)
		&& !ft_is_in_quotes(input, *i))
	{
		args[*j] = ft_substr((char *)input, *i, 1 + (input[*i + 1] == input[*i]
					&& input[*i] != '(' && input[*i] != ')'));
		*j += 1;
		*i += 1 + (input[*i + 1] == input[*i] && input[*i] != '('
				&& input[*i] != ')');
	}
	else
		ft_extract_word(input, args, i, j);
	return (0);
}

/**
 * ENGLISH: Splits the input string into tokens based on spaces and special
 *          characters, respecting quotes and escape sequences.
 *
 * SPANISH: Divide la cadena de entrada en tokens basados en espacios y
 *          caracteres especiales, respetando comillas y secuencias de escape.
 *
 * @param input The input string to split.
 *               La cadena de entrada a dividir.
 *
 * @param argc  The number of expected tokens (arguments).
 *               El número de tokens esperados (argumentos).
 *
 * @returns An array of token strings, or NULL on memory allocation failure.
 *          Un arreglo de cadenas de tokens, o NULL en caso de fallo de
 *          asignación de memoria.
 */
char	**ft_split_input(const char *input, int argc)
{
	char	**args;
	int		i;
	int		j;

	args = malloc(sizeof(char *) * (argc + 1));
	if (!args)
		return (NULL);
	i = 0;
	j = 0;
	while (input[i] && j < argc)
		ft_handle_token(input, args, &i, &j);
	args[j] = NULL;
	return (args);
}
