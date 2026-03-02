/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 10:00:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/24 17:21:56 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * ENGLISH: Retrieves the current working directory from the PWD environment
 * 			variable.
 * 		If PWD is not set or invalid, returns NULL.
 *
 * SPANISH: Obtiene el directorio de trabajo actual de la variable de entorno
 * 			PWD.
 * 		Si PWD no está establecido o es inválido, devuelve NULL.
 *
 * @param data The shell data structure containing environment variables. /
 *             La estructura de datos del shell que contiene las variables de
 *             entorno.
 *
 * @returns The current working directory as a string, or NULL if not found. /
 *          El directorio de trabajo actual como cadena, o NULL si no se
 *          encuentra.
 */
static char	*get_pwd_from_env(t_data *data)
{
	char	*pwd_env;
	char	*out;
	int		len;

	if (!data || !data->envp)
		return (NULL);
	pwd_env = ft_getenv("PWD", data->envp);
	if (!pwd_env || pwd_env[0] != '/')
		return (NULL);
	len = ft_strlen(pwd_env);
	out = malloc(len + 1);
	if (!out)
		return (NULL);
	ft_strcpy(out, pwd_env);
	return (out);
}

/**
 * ENGLISH: Allocates and retrieves the current working directory using
 * 			getcwd.
 *
 * SPANISH: Asigna y obtiene el directorio de trabajo actual usando getcwd.
 *
 * @returns The current working directory as a string, or NULL on failure. /
 *          El directorio de trabajo actual como cadena, o NULL en caso de
 *          error.
 */
static char	*get_cwd_alloc(void)
{
	char	cwd[1024];
	char	*out;
	int		len;

	if (getcwd(cwd, sizeof(cwd)) == NULL)
		return (NULL);
	len = ft_strlen(cwd);
	out = malloc(len + 1);
	if (!out)
		return (NULL);
	ft_strcpy(out, cwd);
	return (out);
}

/**
 * ENGLISH: Writes the current working directory to the command's output file
 * 			descriptor and frees the allocated memory.
 *
 * SPANISH: Escribe el directorio de trabajo actual en el descriptor de
 * 			archivo de salida del comando y libera la memoria asignada.
 *
 * @param cmd The command structure containing output file descriptor. /
 * 			La estructura de comando que contiene el descriptor de archivo
 * 			de salida.
 * @param pwd The current working directory string to write. /
 * 			La cadena del directorio de trabajo actual a escribir.
 * @returns 0 on success, 1 on failure. /
 * 			0 en caso de éxito, 1 en caso de error.
 */
static int	write_pwd_and_free(t_cmd cmd, char *pwd)
{
	char	*buf;
	int		len;

	if (!pwd)
		return (1);
	len = ft_strlen(pwd);
	buf = malloc(len + 2);
	if (!buf)
	{
		free(pwd);
		return (1);
	}
	ft_strcpy(buf, pwd);
	buf[len] = '\n';
	buf[len + 1] = '\0';
	write(cmd.outfd, buf, len + 1);
	free(buf);
	free(pwd);
	return (0);
}

/**
 * ENGLISH: Implements the pwd command, retrieving and printing the current
 * 			working directory.
 *
 * SPANISH: Implementa el comando pwd, obteniendo e imprimiendo el directorio
 * 			de trabajo actual.
 *
 * @param cmd The command structure containing arguments and environment data. /
 *            La estructura de comando que contiene los argumentos y datos de
 *            entorno.
 *
 * @returns 0 on success, 1 on failure. /
 *          0 en caso de éxito, 1 en caso de error.
 */
int	ft_pwd(t_cmd cmd)
{
	char	*pwd;

	pwd = get_pwd_from_env(cmd.data);
	if (!pwd)
		pwd = get_cwd_alloc();
	if (!pwd)
	{
		perror("minishell: pwd");
		return (1);
	}
	return (write_pwd_and_free(cmd, pwd));
}
