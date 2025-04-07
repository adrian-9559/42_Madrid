/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 00:11:15 by adriescr          #+#    #+#             */
/*   Updated: 2025/03/12 16:58:22 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library_functions.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_get_document_rows(char *file)
{
	int		size;
	char	c;
	int		fd;

	fd = ft_open_file(file);
	size = 1;
	while (read(fd, &c, 1))
		if (c == '\n')
			size++;
	if (size < 1)
		ft_put_error("Error 2: Memory allocation failed.\n");
	if (ft_close_file(fd) == 0)
		ft_put_error("Error 3: Memory allocation failed.\n");
	return (size);
}

int	ft_get_document_cols(char *file)
{
	int		size;
	char	c;
	int		fd;

	fd = ft_open_file(file);
	if (fd == -1)
		return (0);
	while (read(fd, &c, 1) && c != '\n')
		;
	size = 0;
	while (read(fd, &c, 1) && c != '\n')
		size++;
	if (size < 1)
		ft_put_error("Error 4: Memory allocation failed.\n");
	if (ft_close_file(fd) == 0)
		ft_put_error("Error 5: Memory allocation failed.\n");
	return (size);
}
