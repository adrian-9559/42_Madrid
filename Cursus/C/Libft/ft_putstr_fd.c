/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 01:30:15 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/23 01:31:15 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0 || !s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

/*
int	main(void)
{
	int fd = 1; // Standard output
	char *str = "Hello, World!";

	ft_putstr_fd(str, fd);
	return (0);
}
*/