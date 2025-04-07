/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkers_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:04:40 by adriescr          #+#    #+#             */
/*   Updated: 2025/03/12 16:32:04 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library_functions.h"

int	ft_is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

char	*ft_header_map_num(char *file)
{
	int		fd;
	char	*line;
	char	c;
	int		i;

	fd = ft_open_file(file);
	if (fd == -1)
	{
		return (NULL);
	}
	line = NULL;
	i = 0;
	while (read(fd, &c, 1) != '\n')
	{
		line[i] = c;
	}
	if (ft_close_file(fd) == -1)
	{
		return (NULL);
	}
	return (line);
}

int	ft_get_num_header_rows(char *file)
{
	int		fd;
	int		rows;
	char	c;

	fd = ft_open_file(file);
	if (fd == -1)
		return (-1);
	rows = 0;
	while (read(fd, &c, 1) != '\n')
	{
		if (ft_is_digit(c))
			rows = rows * 10 + (c - '0');
		else if (c == '\n')
		{
			ft_close_file(fd);
			return (rows);
		}
	}
	ft_close_file(fd);
	return (rows);
}

char	*ft_get_fills(char *file)
{
	int		fd;
	int		i;
	char	*line;
	char	*fill;
	char	c;

	i = 0;
	fd = ft_open_file(file);
	if (fd == -1)
		return (NULL);
	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	while (read(fd, &c, 1) > 0 && c != '\n' && i < BUFFER_SIZE)
		line[i++] = c;
	line[i] = '\0';
	ft_close_file(fd);
	if (i < 3)
		return (free(line), NULL);
	fill = malloc(4);
	if (!fill)
		return (free(line), NULL);
	fill[0] = line[i - 3];
	fill[1] = line[i - 2];
	fill[2] = line[i - 1];
	fill[3] = '\0';
	free(line);
	return (fill);
}
