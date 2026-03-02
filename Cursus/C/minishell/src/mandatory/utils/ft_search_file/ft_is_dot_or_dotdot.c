/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_dot_or_dotdot.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 20:34:25 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/16 20:34:25 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * ENGLISH: Checks if the given name is "." or "..".
 *
 * SPANISH: Comprueba si el nombre dado es "." o "..".
 *
 * @param name  The name to check. /
 *              El nombre a comprobar.
 *
 * @returns 1 if the name is "." or "..", 0 otherwise. /
 *          1 si el nombre es "." o "..", 0 en caso contrario.
 */
int	ft_is_dot_or_dotdot(const char *name)
{
	return (!ft_strcmp(name, ".") || !ft_strcmp(name, ".."));
}
