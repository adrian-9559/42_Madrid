/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 20:06:20 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/19 18:24:08 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * ENGLISH: Cleans the argument array by removing NULL or empty string entries.
 *
 * SPANISH: Limpia el arreglo de argumentos eliminando entradas NULL o
 * 			cadenas vacías.
 *
 * @param argv   The argument array to clean. /
 *               El arreglo de argumentos a limpiar.
 *
 * @returns The new count of arguments after cleaning. /
 *          El nuevo conteo de argumentos después de limpiar.
 */
static int	ft_clean_argv(char **argv)
{
	int	i;
	int	j;

	if (!argv)
		return (0);
	i = 0;
	j = 0;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) > 0)
		{
			if (i != j)
				argv[j] = argv[i];
			j++;
		}
		i++;
	}
	argv[j] = NULL;
	return (j);
}

/**
 * ENGLISH: Checks if the command path is valid, exists, is not a directory,
 *          and has execute permissions.
 *
 * SPANISH: Verifica si la ruta del comando es válida, existe, no es
 * 			un directorio, y tiene permisos de ejecución.
 *
 * @param path      The command path to check.
 *                  La ruta del comando a verificar.
 *
 * @param cmd_name  The name of the command (for error messages).
 *                  El nombre del comando (para mensajes de error).
 *
 * @returns 0 if the path is valid and executable, otherwise returns
 * 			an appropriate exit code after handling the error. /
 *          0 si la ruta es válida y ejecutable, de lo contrario
 * 			devuelve un código de salida apropiado después de manejar
 * 			el error.
 */
static int	ft_check_cmd_path(const char *path, const char *cmd_name)
{
	struct stat	file_stat;

	if (!path)
		return (ft_handle_error(1, EXIT_COMMAND_NOT_FOUND, (char *)cmd_name,
				NULL));
	if (stat(path, &file_stat) == -1)
		return (ft_handle_error(4, EXIT_COMMAND_NOT_FOUND, (char *)cmd_name,
				NULL));
	if (S_ISDIR(file_stat.st_mode))
		return (ft_handle_error(3, EXIT_PERMISSION_DENIED, (char *)cmd_name,
				NULL));
	if (access(path, X_OK) == -1)
		return (ft_handle_error(2, EXIT_PERMISSION_DENIED, (char *)cmd_name,
				NULL));
	return (0);
}

/**
 * ENGLISH: Executes a command by finding its path and invoking execve.
 *
 * SPANISH: Ejecuta un comando encontrando su ruta e invocando execve.
 *
 * @param cmd   The command structure containing arguments and environment data.
 *              La estructura de comando que contiene argumentos y datos
 *              de entorno.
 *
 * @returns EXIT_SUCCESS on success, or an appropriate exit code on failure. /
 *          EXIT_SUCCESS en caso de éxito, o un código de salida apropiado en
 * 			caso de fallo.
 * @returns EXIT_FAILURE if execve fails. /
 *				EXIT_FAILURE si execve falla.
 */
int	ft_exec_bin(t_cmd *cmd)
{
	char	*path;
	int		ret;

	if (!cmd)
		return (1);
	if (!cmd->argv)
		return (0);
	if (ft_clean_argv(cmd->argv) == 0)
		return (0);
	if (!ft_strchr(cmd->argv[0], '/') && !ft_getenv("PATH", cmd->data->envp))
		return (ft_handle_error(4, EXIT_COMMAND_NOT_FOUND, cmd->argv[0], NULL));
	path = ft_get_cmd_path(cmd->argv[0], cmd->data->envp);
	ret = ft_check_cmd_path(path, cmd->argv[0]);
	if (ret)
	{
		free(path);
		return (ret);
	}
	execve(path, cmd->argv, cmd->data->envp);
	perror("minishell: execve");
	free(path);
	return (EXIT_FAILURE);
}
