/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir_error_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 19:23:16 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/24 18:45:00 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell_bonus.h"

/**
 * ENGLISH: Checks if the given filename for redirection is ambiguous.
 *
 * SPANISH: Verifica si el nombre de archivo dado para la redirección es
 *          ambiguo.
 *
 * @param filename  The filename to check. /
 *                  El nombre del archivo a verificar.
 *
 * @returns 1 if the filename is ambiguous, 0 otherwise. /
 *          1 si el nombre del archivo es ambiguo, 0 en caso contrario.
 */
int	ft_is_ambiguous_redirect(char *filename)
{
	int	i;

	if (!filename || !filename[0])
		return (1);
	i = 0;
	while (filename[i])
	{
		if (filename[i] == ' ' || filename[i] == '\t')
			return (1);
		i++;
	}
	return (0);
}

/**
 * ENGLISH: Checks for ambiguous redirection errors and updates the command
 *          structure accordingly.
 *
 * SPANISH: Verifica errores de redirección ambiguos y actualiza la
 *          estructura del comando en consecuencia.
 *
 * @param cmd           Pointer to the command structure. /
 *                      Puntero a la estructura del comando.
 *
 * @param argv          The array of argument strings. /
 *                      El arreglo de cadenas de argumentos.
 *
 * @param i             The current index in the argument array. /
 *                      El índice actual en el arreglo de argumentos.
 *
 * @param expanded_arg  The expanded argument string. /
 *                      La cadena de argumento expandida.
 *
 * @returns 1 if an ambiguous redirection error is found, 0 otherwise. /
 *          1 si se encuentra un error de redirección ambiguo, 0 en caso
 *          contrario.
 */
int	ft_check_ambiguous(t_cmd *cmd, char **argv, int i, char *expanded_arg)
{
	char	*clean_arg;
	char	*original_arg;

	original_arg = argv[i + 1];
	clean_arg = ft_remove_quotes(argv[i + 1]);
	if (!clean_arg)
		clean_arg = argv[i + 1];
	if (ft_strcmp(argv[i], "<<") != 0 && ((!original_arg || !expanded_arg)
			|| ft_strcmp(original_arg, expanded_arg) != 0)
		&& ft_is_ambiguous_redirect(expanded_arg))
	{
		if (clean_arg != argv[i + 1])
			free(clean_arg);
		ft_fprintf(2, ERROR_AMBIGUOUS_REDIRECT, original_arg);
		cmd->data->last_exit_status = 1;
		cmd->has_error = 1;
		free(expanded_arg);
		return (1);
	}
	if (clean_arg != argv[i + 1])
		free(clean_arg);
	return (0);
}

/**
 * ENGLISH: Handles file descriptor errors during redirection setup.
 *
 * SPANISH: Maneja errores de descriptores de archivo durante la
 *          configuración de redirecciones.
 *
 * @param cmd      Pointer to the command structure. /
 *                 Puntero a la estructura del comando.
 *
 * @param fd_ret   The return value from the file descriptor assignment. /
 *                 El valor de retorno de la asignación del descriptor
 *                 de archivo.
 *
 * @returns -1 on critical error, 0 otherwise. /
 *          -1 en caso de error crítico, 0 en caso contrario.
 */
int	ft_handle_fd_error(t_cmd *cmd, int fd_ret)
{
	if (fd_ret == -2)
		return (-1);
	if (fd_ret == -1)
	{
		cmd->data->last_exit_status = 1;
		cmd->has_error = 1;
	}
	return (0);
}

/**
 * ENGLISH: Handles wildcard sentinel values in expanded arguments
 *          during redirection processing.
 *
 * SPANISH: Maneja valores centinela de comodines en argumentos expandidos
 *          durante el procesamiento de redirecciones.
 *
 * @param cmd           Pointer to the command structure. /
 *                      Puntero a la estructura del comando.
 * @param expanded_arg  The expanded argument string. /
 * 					La cadena de argumento expandida.
 *
 * @returns 1 if a wildcard sentinel is found, 0 otherwise. /
 *          1 si se encuentra un centinela de comodín, 0 en caso contrario.
 */
int	ft_handle_wildcard_sentinel(t_cmd *cmd, char *expanded_arg)
{
	if (!expanded_arg)
		return (0);
	if (ft_strncmp(expanded_arg, "!NOFILE!", 8) == 0 || ft_strcmp(expanded_arg,
			"!AMB_REDIRECT!") == 0)
	{
		if (ft_strncmp(expanded_arg, "!NOFILE!", 8) == 0)
			ft_fprintf(2, ERROR_NO_SUCH_FILE, expanded_arg + 8);
		cmd->data->last_exit_status = 1;
		cmd->has_error = 1;
		free(expanded_arg);
		return (1);
	}
	return (0);
}
