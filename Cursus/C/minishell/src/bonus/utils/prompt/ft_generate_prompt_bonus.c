/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_prompt_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 11:30:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/09/27 22:27:16 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

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
