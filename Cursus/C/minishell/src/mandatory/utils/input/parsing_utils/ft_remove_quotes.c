/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 20:16:59 by agarcia           #+#    #+#             */
/*   Updated: 2025/12/02 17:35:23 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

/**
 * ENGLISH: Removes surrounding quotes from the input string.
 *
 * SPANISH: Elimina las comillas que rodean la cadena de entrada.
 *
 * @param str  The input string with potential quotes.
 *             La cadena de entrada con posibles comillas.
 * @param i    The current index in the input string.
 *             El índice actual en la cadena de entrada.
 *
 * @returns A new string without surrounding quotes, or NULL on memory
 *          allocation failure.
 *          Una nueva cadena sin comillas que la rodean, o NULL en caso de
 *          fallo de asignación de memoria.
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
 * 		It accounts for quoted sections and unquoted characters.
 *
 * SPANISH: Calcula la longitud de la cadena después de eliminar las comillas.
 * 		Tiene en cuenta las secciones entre comillas y los caracteres
 * 		sin comillas.
 *
 * @param str The input string with potential quotes. /
 *            La cadena de entrada con posibles comillas.
 *
 * @returns The length of the string after removing quotes. /
 * 		La longitud de la cadena después de eliminar las comillas.
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

	q = str[(*i)++];
	while (str[*i] && str[*i] != q)
		res[(*j)++] = str[(*i)++];
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
	return (res[j] = '\0', res);
}
