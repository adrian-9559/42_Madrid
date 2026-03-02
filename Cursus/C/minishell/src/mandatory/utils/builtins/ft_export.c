/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 10:00:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/19 23:10:09 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * ENGLISH: Checks if a string is a valid environment variable identifier.
 * 			Valid identifiers start with a letter or underscore, followed by
 * 			letters, digits, or underscores, and may include an optional '='.
 *
 * SPANISH: Verifica si una cadena es un identificador válido de variable
 * 			de entorno. Los identificadores válidos comienzan con una letra
 * 			o guion bajo, seguidos de letras, dígitos o guiones bajos,
 * 			y pueden incluir un '=' opcional.
 *
 * @param str The string to check. /
 *            La cadena a verificar.
 *
 * @return 1 if valid, 0 if invalid. /
 *         1 si es válido, 0 si es inválido.
 */
static int	ft_is_valid_identifier(const char *str)
{
	int	i;

	if (!str || *str == '\0')
		return (0);
	if (!((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z')
			|| str[0] == '_'))
		return (0);
	i = 1;
	while (str[i] && str[i] != '=')
	{
		if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A'
					&& str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9')
				|| str[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}

/**
 * ENGLISH: Prints all environment variables in the format used by the export
 * 			command, i.e., declare -x NAME="value" or declare -x NAME.
 *
 * SPANISH: Imprime todas las variables de entorno en el formato utilizado
 * 			por el comando export, es decir, declare -x NOMBRE="valor"
 * 			o declare -x NOMBRE.
 *
 * @param envp The environment variables array. /
 *             La matriz de variables de entorno.
 */
static void	ft_print_exported_vars(char **envp)
{
	int		i;
	int		j;
	char	*name;
	char	*value;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		name = ft_substr(envp[i], 0, j);
		if (envp[i][j] == '=')
		{
			value = ft_substr(envp[i], j + 1, ft_strlen(envp[i]) - j - 1);
			ft_fprintf(1, "declare -x %s=\"%s\"\n", name, value);
			free(value);
		}
		else
			ft_fprintf(1, "declare -x %s\n", name);
		free(name);
		i++;
	}
}

/**
 * ENGLISH: Exports a single environment variable from the given argument.
 * 			The argument can be in the form NAME=value or just NAME.
 * 			If the identifier is invalid, an error is returned.
 * 			Uses ft_setenv to set the variable in the environment.
 * 			Returns 0 on success, 1 on error.
 *
 * SPANISH: Exporta una sola variable de entorno a partir del argumento
 * 			dado. El argumento puede estar en la forma NOMBRE=valor o
 * 			solo NOMBRE.
 * 			Si el identificador es inválido, se devuelve un error.
 * 			Utiliza ft_setenv para establecer la variable en el entorno.
 * 			Devuelve 0 en caso de éxito, 1 en caso de error.
 *
 * @param arg  The argument string (NAME=value or NAME). /
 * 			La cadena de argumentos (NOMBRE=valor o NOMBRE).
 * @param envp The pointer to the environment variables array. /
 * 		El puntero a la matriz de variables de entorno.
 *
 * @return 0 on success, 1 on error. /
 * 			0 en caso de éxito, 1 en caso de error.
 */
static int	ft_export_variable(const char *arg, char ***envp)
{
	char	*array[3];
	int		ret;

	if (!ft_is_valid_identifier(arg))
		return (ft_handle_error(13, 1, (char *)arg, NULL));
	array[0] = ft_strchr(arg, '=');
	if (array[0])
	{
		array[1] = ft_substr((char *)arg, 0, array[0] - arg);
		array[2] = ft_strdup(array[0] + 1);
		ret = ft_setenv(array[1], array[2], envp);
		free(array[1]);
		free(array[2]);
		return (ret);
	}
	else
	{
		return (ft_setenv((char *)arg, NULL, envp));
	}
}

/**
 * ENGLISH: Implements the export command, handling multiple arguments.
 * 			If no arguments are provided, it prints all environment variables.
 * 			Returns 0 on success, 1 if any argument is invalid.
 *
 * SPANISH: Implementa el comando export, manejando múltiples argumentos.
 * 			Si no se proporcionan argumentos, imprime todas las variables
 * 			de entorno. Devuelve 0 en caso de éxito, 1 si algún argumento
 * 			es inválido.
 *
 * @param argv The command arguments array. /
 *             La matriz de argumentos del comando.
 * @param envp The pointer to the environment variables array. /
 *             El puntero a la matriz de variables de entorno.
 *
 * @return 0 on success, 1 if any argument is invalid. /
 *         0 en caso de éxito, 1 si algún argumento es inválido.
 */
int	ft_export(char **argv, char ***envp)
{
	int	i;
	int	exit_status;

	if (!argv[1])
	{
		ft_print_exported_vars(*envp);
		return (0);
	}
	exit_status = 0;
	i = 1;
	while (argv[i])
	{
		if (ft_export_variable(argv[i], envp) != 0)
			exit_status = 1;
		i++;
	}
	return (exit_status);
}
