/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_prompt.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 11:30:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/09/22 14:55:54 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * ENGLISH: Generates the shell prompt string based on the current directory.
 *
 * SPANISH: Genera la cadena del prompt del shell basada en el directorio actual.
 *
 * @param envp   The environment variables. /
 *               Las variables de entorno.
 *
 * @returns A dynamically allocated string with the prompt. /
 *          Una cadena asignada dinámicamente con el prompt.
 */
char	*ft_generate_prompt(char **envp)
{
	char	*dir_path;
	char	*temp;
	char	*prompt;

	dir_path = ft_get_directory_path(envp);
	if (!dir_path)
		return (ft_strdup("minishell> "));
	temp = ft_strjoin(PROMPT_PREFIX, dir_path);
	free(dir_path);
	if (!temp)
		return (ft_strdup("minishell> "));
	prompt = ft_strjoin(temp, PROMPT_SUFFIX);
	free(temp);
	if (!prompt)
		return (ft_strdup("minishell> "));
	return (prompt);
}
