/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>             +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 10:00:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/09/14 22:46:42 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

/**
 * ENGLISH: Implements the exit command, handling optional numeric arguments
 * 			and error cases.
 *
 * SPANISH: Implementa el comando exit, manejando argumentos numéricos
 * 			opcionales y casos de error.
 *
 * @param cmd The command structure containing arguments. /
 *            La estructura de comando que contiene los argumentos.
 *
 * @returns This function does not return ; it exits the program. /
 *          Esta función no retorna; sale del programa.
 */
int	ft_exit(t_cmd *cmd)
{
	char	**args;
	int		argc;

	args = cmd->argv;
	if (!args)
		exit(0);
	argc = ft_count_arg(args);
	if (argc == 1)
		exit(0);
	else if (argc > 2)
	{
		ft_fprintf(2, "exit\n");
		return (ft_handle_error(7, EXIT_FAILURE, NULL, NULL));
	}
	else if (!ft_is_numeric(args[1]))
	{
		ft_fprintf(2, "exit\n");
		exit(ft_handle_error(14, 2, args[1], NULL));
	}
	else
		exit((int)(ft_atoll(args[1]) % 256));
	return (0);
}
