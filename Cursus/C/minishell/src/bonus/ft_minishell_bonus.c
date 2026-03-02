/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:47:21 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/25 00:12:46 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

/**
 * ENGLISH: Initializes a default environment if none is provided.
 *
 * SPANISH: Inicializa un entorno por defecto si no se proporciona ninguno.
 *
 * @returns A newly allocated array of environment variables. /
 *          Un arreglo de variables de entorno recién asignado.
 */
static char	**ft_init_env(void)
{
	char	**env;
	char	*cwd;
	int		i;

	i = 3;
	env = malloc(sizeof(*env) * 5);
	if (!env)
		return (NULL);
	cwd = getcwd(NULL, 0);
	if (cwd)
	{
		env[0] = ft_strjoin("PWD=", cwd);
		free(cwd);
	}
	else
		env[0] = ft_strdup("PWD=/");
	env[1] = ft_strdup("SHLVL=0");
	env[2] = ft_strdup("_=/usr/bin/env");
	env[3] = ft_strdup("PATH=/usr/local/bin:/usr/bin:/bin:./usr/sbin:/sbin:.");
	env[4] = NULL;
	if (env[0] || env[1] || env[2] || env[3])
		return (env);
	while (i >= 0)
		free(env[i--]);
	return (free(env), NULL);
}

/**
 * ENGLISH: Updates the SHLVL environment variable.
 *
 * SPANISH: Actualiza la variable de entorno SHLVL.
 *
 * @param data   Pointer to the shell data structure. /
 *               Puntero a la estructura de datos del shell.
 */
static void	update_shlvl(t_data *data)
{
	char	*val;
	int		lvl;
	char	*newlvl;

	val = ft_getenv("SHLVL", data->envp);
	if (val && ft_is_number(val))
		lvl = ft_atoi(val);
	else
		lvl = 0;
	if (lvl < 0)
		lvl = 0;
	else if (lvl >= 1000)
		lvl = 1;
	else
		lvl = lvl + 1;
	newlvl = ft_itoa(lvl);
	if (!newlvl)
		return ;
	if (val)
		ft_update_existing_env("SHLVL", newlvl, data->envp);
	else
		ft_setenv("SHLVL", newlvl, &(data->envp));
	free(newlvl);
}

/**
 * ENGLISH: Initializes the shell data structure with environment variables.
 *
 * SPANISH: Inicializa la estructura de datos del shell con las variables de
 *          entorno.
 *
 * @param data   Pointer to store the initialized data structure. /
 *               Puntero para almacenar la estructura de datos inicializada.
 * @param envp   The environment variables. /
 *               Las variables de entorno.
 *
 * @returns 0 on success, 1 on memory allocation failure. /
 *          0 en éxito, 1 en fallo de asignación de memoria.
 */
static int	ft_init_data(t_data **data, char **envp)
{
	*data = ft_calloc(1, sizeof **data);
	if (!*data)
		return (1);
	(*data)->envp = ft_dupenv(envp);
	if (!(*data)->envp)
		(*data)->envp = ft_init_env();
	if (!(*data)->envp)
	{
		free(*data);
		return (1);
	}
	(*data)->isatty = isatty(STDIN_FILENO);
	update_shlvl(*data);
	return (0);
}

/**
 * ENGLISH: The main function for the minishell program.
 *          It initializes the shell, displays a welcome message if in
 *          interactive mode,
 *          reads user input, processes commands, and executes
 *          them in a loop until exit.
 *
 * SPANISH: La función principal para el programa minishell.
 *          Inicializa el shell, muestra un mensaje de bienvenida si está
 *          en modo interactivo,
 *          lee la entrada del usuario, procesa los comandos y los ejecuta
 *          en un bucle hasta salir.
 *
 * @param envp   The environment variables. /
 *               Las variables de entorno.
 *
 * @param debug  Flag to indicate if debug information should be shown. /
 *               Indicador para indicar si se debe mostrar información de
 *               depuración.
 *
 * @returns The exit status of the last executed command. /
 *          El estado de salida del último comando ejecutado.
 */
static int	ft_process_lines(char *input, t_data **data, int debug)
{
	char	**lines;
	int		i;
	int		exit_status;
	t_cmd	*cmd_list;

	lines = ft_split(input, '\n');
	free(input);
	if (!lines)
		return (ERROR);
	i = -1;
	exit_status = 0;
	while (lines[++i])
	{
		if (lines[i][0] != '\0')
		{
			cmd_list = ft_process_input(ft_strdup(lines[i]), *data, debug);
			exit_status = ft_execute_cmds(cmd_list, data);
		}
	}
	return (ft_free_matrix(lines), exit_status);
}

/**
 * ENGLISH: The main function for the minishell program.
 *          It initializes the shell, displays a welcome message if in
 *          interactive mode,
 *          reads user input, processes commands, and executes
 *          them in a loop until exit.
 *
 * SPANISH: La función principal para el programa minishell.
 *          Inicializa el shell, muestra un mensaje de bienvenida si está
 *          en modo interactivo,
 *          lee la entrada del usuario, procesa los comandos y los ejecuta
 *          en un bucle hasta salir.
 *
 * @param envp   The environment variables. /
 *               Las variables de entorno.
 *
 * @param debug  Flag to indicate if debug information should be shown. /
 *               Indicador para indicar si se debe mostrar información de
 *               depuración.
 *
 * @returns The exit status of the last executed command. /
 *          El estado de salida del último comando ejecutado.
 */
int	ft_minishell(char **envp, int debug)
{
	char	*input;
	t_data	*data;
	int		exit_status;

	exit_status = 0;
	if (ft_init_data(&data, envp))
		return (ERROR);
	if (data->isatty)
		ft_msg_start(data->envp);
	ft_init_signals();
	while (ft_read_input(&input, data))
		exit_status = ft_process_lines(input, &data, debug);
	ft_cleanup(data);
	return (exit_status);
}
