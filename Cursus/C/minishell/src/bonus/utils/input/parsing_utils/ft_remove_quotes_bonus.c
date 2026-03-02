/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_quotes_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 20:16:59 by agarcia           #+#    #+#             */
/*   Updated: 2025/12/02 17:38:28 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell_bonus.h"

/**
 * ENGLISH: Handles quoted sections of the string, updating the index and
 *          returning the length of the quoted content.
 *
 * SPANISH: Maneja secciones entre comillas de la cadena, actualizando el
 *          índice y devolviendo la longitud del contenido entre comillas.
 *
 * @param str   The input string. /
 *              La cadena de entrada.
 * @param i     Pointer to the current index in the string. /
 * 			Puntero al índice actual en la cadena.
 *
 * @returns The length of the quoted content. /
 *          La longitud del contenido entre comillas.
 */
static int	handle_quoted(const char *str, int *i)
{
	int		len;
	char	q;

	len = 0;
	q = str[(*i)++];
	while (str[*i] && str[*i] != q)
	{
		len++;
		(*i)++;
	}
	if (str[*i] == q)
		(*i)++;
	return (len);
}

/**
 * ENGLISH: Calculates the length of the string after removing quotes.
 *
 * SPANISH: Calcula la longitud de la cadena después de eliminar las comillas.
 *
 * @param str   The input string. /
 *              La cadena de entrada.
 *
 * @returns The length of the unquoted string. /
 *          La longitud de la cadena sin comillas.
 */
static int	ft_calc_unquoted_len(const char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if ((str[i] == '\'' || str[i] == '"') && ft_has_closing_quote(str + i
				+ 1, str[i]))
			len += handle_quoted(str, &i);
		else
		{
			len++;
			i++;
		}
	}
	return (len);
}

/**
 * ENGLISH: Copies a quoted section from the input string to the result
 *          string, removing the surrounding quotes.
 *
 * SPANISH: Copia una sección entre comillas de la cadena de entrada a la
 *          cadena de resultado, eliminando las comillas que la rodean.
 *
 * @param str The input string with potential quotes. /
 *            La cadena de entrada con posibles comillas.
 * @param i   Pointer to the current index in the input string. /
 *            Puntero al índice actual en la cadena de entrada.
 * @param res The result string where the unquoted section will be copied. /
 *            La cadena de resultado donde se copiará la sección sin comillas.
 * @param j   Pointer to the current index in the result string. /
 *            Puntero al índice actual en la cadena de resultado.
 */
static void	copy_quoted(const char *str, int *i, char *res, int *j)
{
	char	q;
	char	other_q;

	q = str[(*i)++];
	if (q == '"')
		other_q = '\'';
	else
		other_q = '"';
	while (str[*i] && str[*i] != q)
	{
		if (str[*i] == other_q)
			res[(*j)++] = str[(*i)++];
		else
			res[(*j)++] = str[(*i)++];
	}
	if (str[*i] == q)
		(*i)++;
}

static void	copy_escaped_quote(const char *str, int *i, char *res, int *j)
{
	res[(*j)++] = str[*i + 1];
	*i += 2;
}

/**
 * ENGLISH: Removes surrounding quotes from the input string.
 * 		It returns a new string without quotes.
 *
 * SPANISH: Elimina las comillas que rodean la cadena de entrada.
 * 		Devuelve una nueva cadena sin comillas.
 *
 * @param str The input string with potential quotes. /
 *            La cadena de entrada con posibles comillas.
 *
 * @returns A new string without surrounding quotes, or NULL on memory
 *          allocation failure. /
 *          Una nueva cadena sin comillas que la rodean, o NULL en caso de
 *          fallo de asignación de memoria.
 */
char	*ft_remove_quotes(const char *str)
{
	int		i;
	int		j;
	int		unlen;
	char	*res;

	if (!str)
		return (NULL);
	unlen = ft_calc_unquoted_len(str);
	res = malloc((size_t)unlen + 1);
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == 1 && (str[i + 1] == '\'' || str[i + 1] == '"'))
			copy_escaped_quote(str, &i, res, &j);
		else if ((str[i] == '\'' || str[i] == '"') && ft_has_closing_quote(str
				+ i + 1, str[i]))
			copy_quoted(str, &i, res, &j);
		else
			res[j++] = str[i++];
	}
	res[j] = '\0';
	return (res);
}
