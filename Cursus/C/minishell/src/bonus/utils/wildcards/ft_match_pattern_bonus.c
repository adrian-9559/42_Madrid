/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match_pattern_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 01:46:11 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/24 18:56:56 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

/**
 * ENGLISH: Handles the case when a '*' is encountered in the pattern.
 *
 * SPANISH: Maneja el caso cuando se encuentra un '*' en el patrón.
 *
 * @param pat         Pointer to the current position in the pattern. /
 *                    Puntero a la posición actual en el patrón.
 * @param str         Pointer to the current position in the string. /
 *                    Puntero a la posición actual en la cadena.
 * @param last_star   Pointer to store the position of the last '*' found. /
 *                    Puntero para almacenar la posición del último '*'
 *                    encontrado.
 * @param str_backup  Pointer to store the position in the string to backtrack
 *                    to. /
 *                    Puntero para almacenar la posición en la cadena a la que
 *                    retroceder.
 */
static int	handle_star(const char **pat, const char **str,
		const char **last_star, const char **str_backup)
{
	*last_star = (*pat)++;
	*str_backup = *str;
	return (1);
}

/**
 * ENGLISH: Handles backtracking when a mismatch occurs after a '*'.
 *
 * SPANISH: Maneja el retroceso cuando ocurre una discrepancia después de un
 *          '*'.
 *
 * @param pat         Pointer to the current position in the pattern. /
 *                    Puntero a la posición actual en el patrón.
 * @param str         Pointer to the current position in the string. /
 *                    Puntero a la posición actual en la cadena.
 * @param last_star   Pointer to the position of the last '*' found. /
 *                    Puntero a la posición del último '*' encontrado.
 * @param str_backup  Pointer to the position in the string to backtrack to. /
 *                    Puntero a la posición en la cadena a la que retroceder.
 *
 * @returns 1 if backtracking was successful, 0 otherwise. /
 *          1 si el retroceso fue exitoso, 0 en caso contrario.
 */
static int	handle_backtrack(const char **pat, const char **str,
		const char *last_star, const char **str_backup)
{
	if (!last_star)
		return (0);
	*pat = last_star + 1;
	*str = ++(*str_backup);
	return (1);
}

/**
 * ENGLISH: Matches a filename against a wildcard pattern.
 *          Supports '?' for single character and '*' for any sequence of
 *          characters.
 *
 * SPANISH: Coincide un nombre de archivo con un patrón comodín.
 *          Soporta '?' para un solo carácter y '*' para cualquier secuencia
 *          de caracteres.
 *
 * @param pattern   The wildcard pattern to match against. /
 *                  El patrón comodín para coincidir.
 * @param filename  The filename to be matched. /
 *                  El nombre de archivo a coincidir.
 *
 * @returns 1 if the filename matches the pattern, 0 otherwise. /
 *          1 si el nombre de archivo coincide con el patrón, 0 en caso
 *          contrario.
 */
int	ft_match_pattern(const char *pattern, const char *filename)
{
	const char	*pat;
	const char	*str;
	const char	*last_star;
	const char	*str_backup;

	pat = pattern;
	str = filename;
	last_star = NULL;
	str_backup = NULL;
	while (*str)
	{
		if (*pat == '?' || *pat == *str)
		{
			pat++;
			str++;
		}
		else if (*pat == '*')
			handle_star(&pat, &str, &last_star, &str_backup);
		else if (!handle_backtrack(&pat, &str, last_star, &str_backup))
			return (0);
	}
	while (*pat == '*')
		pat++;
	return (*pat == '\0');
}
