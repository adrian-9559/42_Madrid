/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:20:55 by adriescr          #+#    #+#             */
/*   Updated: 2025/11/24 15:44:59 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * ENGLISH: Extracts a line from the reminder.
 *
 * SPANISH: Extrae una línea del recordatorio.
 *
 * @param reminder   The reminder string. /
 *                   La cadena de recordatorio.
 *
 * @returns A pointer to the extracted line, or NULL on failure. /
 *          Un puntero a la línea extraída, o NULL en caso de error.
 */
static char	*ft_extract_line(char **reminder)
{
	char	*line;
	char	*temp;
	size_t	i;

	if (!reminder || !*reminder)
		return (NULL);
	i = 0;
	while ((*reminder)[i] && (*reminder)[i] != '\n')
		i++;
	line = ft_substr(*reminder, 0, i + ((*reminder)[i] == '\n'));
	if (!line)
		return (free(*reminder), *reminder = NULL, NULL);
	temp = ft_strdup(*reminder + i + ((*reminder)[i] == '\n'));
	if (!temp)
		return (free(line), free(*reminder), *reminder = NULL, NULL);
	free(*reminder);
	*reminder = temp;
	return (line);
}

/**
 * ENGLISH: Allocates a buffer for reading.
 *
 * SPANISH: Reserva un búfer para la lectura.
 *
 * @returns A pointer to the allocated buffer, or NULL on failure. /
 *          Un puntero al búfer asignado, o NULL en caso de error.
 */
static char	*ft_alloc_buffer(void)
{
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	return (buffer);
}

static int	ft_append_to_reminder(char **reminder, char *buffer)
{
	char	*joined;

	joined = ft_strjoin(*reminder, buffer);
	if (!joined)
	{
		free(*reminder);
		*reminder = NULL;
		return (-1);
	}
	free(*reminder);
	*reminder = joined;
	return (0);
}

/**
 * ENGLISH: Reads from the file descriptor and appends to the reminder.
 * 		Stops when a newline is found or EOF is reached.
 * SPANISH: Lee del descriptor de archivo y lo añade al recordatorio.
 * 		Se detiene cuando se encuentra un salto de línea o se alcanza EOF.
 *
 * @param fd         The file descriptor to read from. /
 *                   El descriptor de archivo del que leer.
 * @param reminder   The reminder string to append to. /
 *                   La cadena de recordatorio a la que añadir.
 *
 * @returns The number of bytes read, or -1 on error. /
 *          El número de bytes leídos, o -1 en caso de error.
 */
static int	ft_read_to_reminder(int fd, char **reminder)
{
	char	*buffer;
	int		bytes_read;
	int		res;

	buffer = ft_alloc_buffer();
	if (!buffer)
		return (-1);
	bytes_read = 0;
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), -1);
		buffer[bytes_read] = '\0';
		res = ft_append_to_reminder(reminder, buffer);
		if (res < 0)
			return (free(buffer), -1);
		if (ft_strchr(*reminder, '\n') || bytes_read == 0)
			break ;
	}
	free(buffer);
	return (bytes_read);
}

/**
 * ENGLISH: Reads the next line from a file descriptor.
 *
 * SPANISH: Lee la siguiente línea de un descriptor de archivo.
 *
 * @param fd   The file descriptor to read from. /
 *             El descriptor de archivo del que leer.
 *
 * @returns A pointer to the next line read, or NULL if there are no
 * 			more lines or on error. /
 *          Un puntero a la siguiente línea leída, o NULL si no hay
 * 			más líneas o en caso de error.
 */
char	*ft_get_next_line(int fd)
{
	static char	*reminder;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!reminder)
		reminder = ft_strdup("");
	if (!reminder)
		return (NULL);
	bytes_read = ft_read_to_reminder(fd, &reminder);
	if (bytes_read < 0 || (!bytes_read && !*reminder))
	{
		free(reminder);
		reminder = NULL;
		return (NULL);
	}
	return (ft_extract_line(&reminder));
}
