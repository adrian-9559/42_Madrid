/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_debug.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 17:30:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/24 17:23:57 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * ENGLISH: Displays the contents of an argument array with a title and prefix.
 *
 * SPANISH: Muestra el contenido de un arreglo de argumentos
 * 			con un título y prefijo.
 *
 * @param title   The title to display before the arguments.
 *                El título que se muestra antes de los argumentos.
 *
 * @param prefix  The prefix for each argument line.
 *                El prefijo para cada línea de argumento.
 *
 * @param argv    The array of argument strings.
 *                El arreglo de cadenas de argumentos.
 *
 * @param argc    The number of arguments in the array.
 *                El número de argumentos en el arreglo.
 */
static void	ft_show_argv(char *title, char *prefix, char **argv, int argc)
{
	int	i;

	printf("%s:\n", title);
	i = 0;
	while (i < argc)
	{
		printf("  %s[%d]: %s\n", prefix, i, argv[i]);
		i++;
	}
}

/**
 * ENGLISH: Displays the details of a linked list of command structures.
 *

	* SPANISH: Muestra los detalles de una lista enlazada
	* de estructuras de comando.
 *
 * @param cmd_list   The head of the linked list of command structures.
 *                   La cabeza de la lista enlazada de estructuras de comando.
 */
static void	ft_show_cmd_list(t_cmd *cmd_list)
{
	t_cmd	*curr;
	int		arg_count;

	curr = cmd_list;
	while (curr)
	{
		printf("cmd: \n");
		arg_count = 0;
		if (curr->argv)
			arg_count = ft_count_arg(curr->argv);
		ft_show_argv("  argv", "argv", curr->argv, arg_count);
		printf("  fd_in: %d, fd_out: %d\n", curr->infd, curr->outfd);
		printf("  has_error: %d\n", curr->has_error);
		curr = curr->next;
		if (curr)
			printf("  |\n  v\n");
	}
}

/**
 * ENGLISH: Displays debug information about the parsed commands.
 *
 * SPANISH: Muestra información de depuración sobre los comandos parseados.
 *
 * @param cmd_list   The head of the linked list of command structures.
 *                   La cabeza de la lista enlazada de estructuras de comando.
 */
void	ft_show_debug(t_cmd *cmd_list)
{
	(void)cmd_list;
	if (!cmd_list)
	{
		printf("\033[38;5;208m========== DEBUG INFO ==========\033[0m\n");
		printf("\n\033[34mNo commands parsed.\033[0m\n");
		printf("\033[38;5;208m================================\033[0m\n\n");
		return ;
	}
	printf("\033[38;5;208m========== DEBUG INFO ==========\033[0m\n");
	printf("\n\033[34mComandos parseados:\033[0m\n");
	ft_show_cmd_list(cmd_list);
	printf("\033[38;5;208m================================\033[0m\n\n");
}
