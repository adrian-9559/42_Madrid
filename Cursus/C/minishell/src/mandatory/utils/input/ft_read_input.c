/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 20:00:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/12/02 17:40:16 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * ENGLISH: Reads input from the user, handling both interactive
 *          and non-interactive modes.
 *
 * SPANISH: Lee la entrada del usuario, manejando tanto los modos
 *          interactivo como no interactivo.
 *
 * @param input Pointer to store the read input string. /
 *              Puntero para almacenar la cadena de entrada leída.
 * @param data  Pointer to the shell data structure. /
 *              Puntero a la estructura de datos del shell.
 *
 * @returns 1 on successful input read, 0 on EOF or error. /
 *          1 en caso de lectura de entrada exitosa, 0 en EOF o error.
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
 * ENGLISH: Reads input in non-interactive mode (e.g., from a pipe or file).
 *          It reads a line from standard input and removes the trailing
 *          newline.
 *
 * SPANISH: Lee la entrada en modo no interactivo (por ejemplo, desde una
 *          tubería o archivo).
 *          Lee una línea de la entrada estándar y elimina la nueva línea
 *          final.
 *
 * @returns The read input string without the trailing newline, or NULL on EOF
 * 		or error. /
 * 		La cadena de entrada leída sin la nueva línea final, o NULL en EOF
 * 		o error.
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
 * ENGLISH: Reads input from the user, handling both interactive
 *          and non-interactive modes. It continues to prompt until
 *          a non-empty input is received or EOF occurs.
 *
 * SPANISH: Lee la entrada del usuario, manejando tanto los modos
 *          interactivo como no interactivo.
 *          Continúa solicitando hasta que se reciba una entrada
 *          no vacía o ocurra EOF.
 *
 * @param input Pointer to store the read input string. /
 *              Puntero para almacenar la cadena de entrada leída.
 * @param data  Pointer to the shell data structure. /
 *              Puntero a la estructura de datos del shell.
 *
 * @returns 1 on successful input read, 0 on EOF or error. /
 *          1 en caso de lectura de entrada exitosa, 0 en EOF o error.
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
