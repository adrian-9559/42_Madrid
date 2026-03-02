/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 10:00:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/24 18:26:26 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

/**
 * ENGLISH: Handles quoted arguments by determining the start and end
 * 			indices for printing.
 *
 * SPANISH: Maneja los argumentos entre comillas determinando los índices
 * 			de inicio y fin para la impresión.
 *
 * @param arg   The argument string to check for quotes. /
 *              La cadena de argumentos a comprobar en busca de comillas.
 *
 * @param start Pointer to store the start index for printing. /
 *              Puntero para almacenar el índice de inicio para la impresión.
 *
 * @param end   Pointer to store the end index for printing. /
 *              Puntero para almacenar el índice de fin para la impresión.
 *
 * @returns 1 if the argument is quoted, 0 otherwise. /
 *          1 si el argumento está entre comillas, 0 en caso contrario.
 */
int	ft_handle_quoted_arg(char *arg, int *start, int *end)
{
	(void)arg;
	*start = 0;
	*end = ft_strlen(arg);
	return (0);
}

/**
 * ENGLISH: Prints a single argument for the echo command, handling
 * 			quoted sections and the -n flag.
 *
 * SPANISH: Imprime un solo argumento para el comando echo, manejando
 * 			secciones entre comillas y la bandera -n.
 *
 * @param arg    The argument string to print. /
 *               La cadena de argumentos a imprimir.
 *
 * @param flag_n If set to 1, indicates that the -n flag is active
 *               (no trailing newline). /
 *               Si se establece en 1, indica que la bandera -n está activa
 *               (sin nueva línea final).
 *
 * @param outfd  The file descriptor to write the output to. /
 *               El descriptor de archivo donde escribir la salida.
 *
 * @returns 0 on success, -1 on error. /
 *          0 en caso de éxito, -1 en caso de error.
 */
static int	ft_putarg_echo(char *arg, int flag_n, int outfd)
{
	int	start;
	int	end;

	if (!arg)
		return (0);
	ft_handle_quoted_arg(arg, &start, &end);
	if (ft_print_arg_content(arg, start, end, outfd) == -1)
		return (-1);
	if (flag_n && arg[end - 1] == ' ' && ft_putchar_fd('%', outfd) == -1)
		return (-1);
	return (0);
}

/**
 * ENGLISH: Prints all arguments for the echo command, handling spacing
 * 			between arguments.
 *
 * SPANISH: Imprime todos los argumentos para el comando echo, manejando
 * 			el espaciado entre argumentos.
 *
 * @param cmd         The command structure containing arguments. /
 *                    La estructura de comando que contiene los argumentos.
 * @param start_index The index to start printing arguments from. /
 * 					El índice desde el cual comenzar a imprimir los
 * 					argumentos.
 * @param outfd       The file descriptor to write the output to. /
 * 					El descriptor de archivo donde escribir la salida.
 * @param n_flag      If set to 1, indicates that the -n flag is active
 * 					(no trailing newline). /
 * 				Si se establece en 1, indica que la bandera -n está activa
 * 				(sin nueva línea final).
 *
 * @returns 0 on success, 1 on error. /
 *          0 en caso de éxito, 1 en caso de error.
 */
static int	ft_print_echo_args(t_cmd cmd, int start_index, int outfd,
		int n_flag)
{
	int	i;

	i = start_index;
	while (cmd.argv[i])
	{
		if (ft_putarg_echo(cmd.argv[i], n_flag, outfd) == -1)
			return (1);
		if (cmd.argv[i][0] != '\0' && cmd.argv[i + 1] && ft_putchar_fd(' ',
				outfd) == -1)
			return (1);
		i++;
	}
	return (0);
}

/**
 * ENGLISH: Implements the echo command, printing arguments to the specified
 * 			output file descriptor, handling the -n flag and spacing.
 *
 * SPANISH: Implementa el comando echo, imprimiendo argumentos en el
 * 			descriptor de archivo de salida especificado, manejando la
 * 			bandera -n y los espacios.
 *
 * @param cmd The command structure containing arguments and file descriptors. /
 *            La estructura de comando que contiene argumentos y descriptores
 * 				de archivo.
 *
 * @returns 0 on success, 1 on error. /
 *          0 en caso de éxito, 1 en caso de error.
 */
int	ft_echo(t_cmd cmd)
{
	int	n_flag;
	int	start_index;
	int	j;

	if (!cmd.argv || !cmd.argv[0] || cmd.outfd < 0)
		return (1);
	n_flag = 0;
	start_index = 1;
	while (cmd.argv[start_index] && cmd.argv[start_index][0] == '-')
	{
		j = 1;
		if (cmd.argv[start_index][j] == '\0')
			break ;
		while (cmd.argv[start_index][j] == 'n')
			j++;
		if (cmd.argv[start_index][j] != '\0')
			break ;
		n_flag = 1;
		start_index++;
	}
	if (ft_print_echo_args(cmd, start_index, cmd.outfd, n_flag) || (!n_flag
			&& ft_putchar_fd('\n', cmd.outfd) == -1))
		return (1);
	return (0);
}
