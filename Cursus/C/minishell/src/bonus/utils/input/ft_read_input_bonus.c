/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 20:00:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/12/02 18:01:42 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

/**
 * ENGLISH: Reads input in interactive mode with a generated prompt.
 *
 * SPANISH: Lee la entrada en modo interactivo con un prompt generado.
 *
 * @param data   Pointer to the shell data structure. /
 *               Puntero a la estructura de datos del shell.
 *
 * @returns The input string or NULL on EOF. /
 *          La cadena de entrada o NULL en EOF.
 */
static char	*read_interactive(t_data *data)
{
	char	*prompt;
	char	*input;

	prompt = ft_generate_prompt(data->envp);
	input = readline(prompt);
	free(prompt);
	return (input);
}

/**
 * ENGLISH: Reads input in non-interactive mode using get_next_line.
 *
 * SPANISH: Lee la entrada en modo no interactivo usando get_next_line.
 *
 * @returns The input string or NULL on EOF. /
 *          La cadena de entrada o NULL en EOF.
 */
static char	*read_noninteractive(void)
{
	char	*input;
	size_t	len;

	input = ft_get_next_line(STDIN_FILENO);
	if (input)
	{
		len = ft_strlen(input);
		if (len > 0 && input[len - 1] == '\n')
			input[len - 1] = '\0';
	}
	return (input);
}

/**
 * ENGLISH: Reads input from the user, displaying a prompt if in interactive
 * 			mode.
 *          Adds non-empty input to history if in interactive mode.
 *
 * SPANISH: Lee la entrada del usuario, mostrando un aviso si está en modo
 * 			interactivo.
 *          Añade la entrada no vacía al historial si está en modo interactivo.
 *
 * @param input  Pointer to store the input string. /
 *               Puntero para almacenar la cadena de entrada.
 *
 * @param data   Pointer to the data structure containing environment and status
 * 				info. /
 *               Puntero a la estructura de datos que contiene información del
 * 				entorno y estado.
 *
 * @returns 1 if input was read successfully, 0 if EOF was encountered. /
 *          1 si se leyó la entrada con éxito, 0 si se encontró EOF.
 */
int	ft_read_input(char **input, t_data *data)
{
	while (1)
	{
		if (data->isatty)
			*input = read_interactive(data);
		else
			*input = read_noninteractive();
		if (!*input)
			return (0);
		if (**input)
		{
			if (data->isatty)
				add_history(*input);
			return (1);
		}
		free(*input);
	}
}
