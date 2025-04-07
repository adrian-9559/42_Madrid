/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 00:19:28 by adriescr          #+#    #+#             */
/*   Updated: 2025/03/12 00:19:32 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library_functions.h"

int	ft_open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_put_error("Dict Error 1: File not found.\n");
		return (-1);
	}
	return (fd);
}

int	ft_close_file(int fd)
{
	if (close(fd) == -1)
	{
		ft_put_error("Dict Error 2: Failed to close file.\n");
		return (0);
	}
	return (1);
}
