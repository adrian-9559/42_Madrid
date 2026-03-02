/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_builtin_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:43:33 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/20 18:04:05 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

/**
 * ENGLISH: Executes a built-in shell command based on the command name.
 *
 * SPANISH: Ejecuta un comando interno del shell según el nombre del comando.
 *
 * Handles: echo, cd, pwd, export, unset, env, exit
 *
 * Maneja: echo, cd, pwd, export, unset, env, exit
 *
 * @param cmd   The command structure containing arguments.
 *              La estructura de comando que contiene los argumentos.
 *
 * @param data  The shell data structure (pointer to environment, etc.).
 *              La estructura de datos del shell (puntero al entorno, etc.).
 *
 * @returns The result of the executed built-in command, or -1 if not found.
 *          El resultado del comando interno ejecutado, o -1 si no se encuentra.
 */
int	ft_exec_builtin(t_cmd *cmd, t_data **data)
{
	if (ft_strcmp(cmd->argv[0], "echo") == 0)
		return (ft_echo(*cmd));
	if (ft_strcmp(cmd->argv[0], "cd") == 0)
		return (ft_cd(cmd->argv, &(*data)->envp));
	if (ft_strcmp(cmd->argv[0], "pwd") == 0)
		return (ft_pwd(*cmd));
	if (ft_strcmp(cmd->argv[0], "export") == 0)
		return (ft_export(cmd->argv, &(*data)->envp));
	if (ft_strcmp(cmd->argv[0], "unset") == 0)
		return (ft_unset(cmd->argv, &(*data)->envp));
	if (ft_strcmp(cmd->argv[0], "env") == 0)
		return (ft_env(*cmd, (*data)->envp));
	if (ft_strcmp(cmd->argv[0], "exit") == 0)
		return (ft_exit(cmd));
	return (-1);
}
