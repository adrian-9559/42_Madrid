/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 10:00:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/24 18:29:55 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

/**
 * ENGLISH: Retrieves the current working directory from the PWD environment
 *          variable.
 *
 * SPANISH: Recupera el directorio de trabajo actual de la variable de entorno
 *          PWD.
 *
 * @param data The global data structure containing environment variables. /
 *             La estructura de datos global que contiene las variables de
 *             entorno.
 *
 * @returns A dynamically allocated string containing the PWD value, or NULL
 *          if not found or on error. /
 *          Una cadena asignada dinámicamente que contiene el valor de PWD, o
 *          NULL si no se encuentra o en caso de error.
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
 *          getcwd.
 *
 * SPANISH: Asigna y recupera el directorio de trabajo actual usando getcwd.
 *
 * @returns A dynamically allocated string containing the current working
 *          directory, or NULL on error. /
 *          Una cadena asignada dinámicamente que contiene el directorio de
 *          trabajo actual, o NULL en caso de error.
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
 * ENGLISH: Writes the current working directory to the specified output file
 *          descriptor and frees the allocated memory.
 *
 * SPANISH: Escribe el directorio de trabajo actual en el descriptor de archivo
 *          de salida especificado y libera la memoria asignada.
 *
 * @param cmd The command structure containing file descriptors. /
 *            La estructura de comando que contiene descriptores de archivo.
 * @param pwd The current working directory string to write. /
 *            La cadena del directorio de trabajo actual a escribir.
 *
 * @returns 0 on success, 1 on error. /
 *          0 en caso de éxito, 1 en caso de error.
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
 * ENGLISH: Implements the pwd command, printing the current working
 *          directory to the specified output file descriptor.
 *
 * SPANISH: Implementa el comando pwd, imprimiendo el directorio de trabajo
 *          actual en el descriptor de archivo de salida especificado.
 *
 * @param cmd The command structure containing file descriptors. /
 *            La estructura de comando que contiene descriptores de archivo.
 *
 * @returns 0 on success, 1 on error. /
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
