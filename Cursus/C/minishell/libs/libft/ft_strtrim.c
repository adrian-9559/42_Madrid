/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 00:45:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/09/22 12:54:49 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ENGLISH: Trims all occurrences of the specified character from the start
 *          and end of the given string.
 *
 * SPANISH: Elimina todas las ocurrencias del carácter especificado
 *          del inicio y el final de la cadena dada.
 *
 * @param str  The string to be trimmed. /
 *             La cadena a ser recortada.
 *
 * @param c    The character to trim from the string. /
 *             El carácter a eliminar de la cadena.
 *
 * @returns A pointer to the newly allocated trimmed string. /
 *          Un puntero a la nueva cadena recortada asignada.
 * @returns Returns NULL if memory allocation fails or if str is NULL. /
 *          Devuelve NULL si la asignación de memoria falla o si str es NULL.
 */
char	*ft_strtrim(const char *str, char c)
{
	int		array[4];
	char	*trimmed;

	if (!str)
		return (NULL);
	array[0] = 0;
	array[1] = ft_strlen(str) - 1;
	while (str[array[0]] && str[array[0]] == c)
		array[0]++;
	while (array[1] >= array[0] && str[array[1]] == c)
		array[1]--;
	array[2] = array[1] - array[0] + 1;
	if (array[2] <= 0)
		return (ft_strdup(""));
	trimmed = malloc((array[2] + 1) * sizeof(char));
	if (!trimmed)
		return (NULL);
	array[3] = 0;
	while (array[3] < array[2])
	{
		trimmed[array[3]] = str[array[0] + array[3]];
		array[3]++;
	}
	trimmed[array[3]] = '\0';
	return (trimmed);
}
