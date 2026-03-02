/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:16:33 by adriescr          #+#    #+#             */
/*   Updated: 2025/11/24 16:58:41 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * ENGLISH: Determines the target directory for the 'cd' command based
 * 			on the arguments and environment.
 *
 * SPANISH: Determina el directorio de destino para el comando 'cd' según
 * 			los argumentos y el entorno.
 *
 * @param argv  The argument vector; argv[1] may contain the target directory.
 *              El vector de argumentos; argv[1] puede contener el directorio
 * 				de destino.
 * @param envp  The environment variables.
 *              Las variables de entorno.
 *
 * @returns The target directory as a string, or NULL if not found.
 *          El directorio de destino como cadena, o NULL si no se encuentra.
 */
static char	*ft_get_target_dir(char **argv, char **envp)
{
	if (!argv[1])
		return (ft_getenv("HOME", envp));
	else if (ft_strcmp(argv[1], "~") == 0)
		return (ft_getenv("HOME", envp));
	else
		return (argv[1]);
}

/**
 * ENGLISH: Checks for errors when retrieving the current working directory.
 *
 * SPANISH: Verifica errores al obtener el directorio de trabajo actual.
 *
 * @returns 1 if no error occurred, 0 otherwise.
 *          1 si no ocurrió ningún error, 0 en caso contrario.
 */
static int	ft_check_getcwd_error(void)
{
	char	*check_cwd;

	check_cwd = getcwd(NULL, 0);
	if (!check_cwd)
	{
		ft_fprintf(2, ERROR_CD_GETCWD, strerror(errno));
		return (0);
	}
	free(check_cwd);
	return (1);
}

/**
 * ENGLISH: Handles successful directory change for the 'cd' command.
 *
 * SPANISH: Maneja el cambio de directorio exitoso para el comando 'cd'.
 *
 * @param target_dir The target directory that was changed to.
 *                   El directorio de destino al que se cambió.
 * @param prev       Indicates if the previous directory should be printed.
 *                   Indica si se debe imprimir el directorio anterior.
 * @param envp       A pointer to the environment variables array.
 *                   Un puntero al array de variables de entorno.
 *
 * @returns 0 on success.
 *          0 en caso de éxito.
 */
static int	ft_handle_chdir_success(char *target_dir, int prev, char ***envp)
{
	int	should_normalize;

	if (prev)
		printf("%s\n", target_dir);
	should_normalize = ft_check_getcwd_error();
	return (ft_update_pwd_env(ft_getenv("PWD", *envp), target_dir, envp,
			should_normalize), 0);
}

/**
 * ENGLISH: Changes the current working directory to the target directory.
 *
 * SPANISH: Cambia el directorio de trabajo actual al directorio de destino.
 *
 * @param argv  The argument vector; argv[1] may contain the target directory.
 *              El vector de argumentos; argv[1] puede contener el
 * 				directorio de destino.
 * @param envp  A pointer to the environment variables array.
 *              Un puntero al array de variables de entorno.
 *
 * @returns 0 on success, 1 on failure.
 *          0 en caso de éxito, 1 en caso de error.
 */
int	ft_cd(char **argv, char ***envp)
{
	int		prev;
	char	*target_dir;

	if (argv[1] && argv[2])
		return (ft_handle_error(7, EXIT_FAILURE, NULL, NULL));
	prev = (argv[1] && ft_strlen(argv[1]) == 1 && ft_strcmp(argv[1], "-") == 0);
	if (prev)
		target_dir = ft_getenv("OLDPWD", *envp);
	else
		target_dir = ft_get_target_dir(argv, *envp);
	if (!target_dir)
	{
		if (prev)
			return (ft_handle_error(11, EXIT_FAILURE, "OLDPWD", "not set"));
		return (ft_handle_error(8, EXIT_FAILURE, NULL, NULL));
	}
	if (chdir(target_dir) == 0)
		return (ft_handle_chdir_success(target_dir, prev, envp));
	else
		return (ft_handle_error(11, EXIT_FAILURE, target_dir, strerror(errno)));
}
