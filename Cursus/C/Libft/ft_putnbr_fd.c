/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 01:35:13 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/23 01:44:46 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}

/*
int main(void)
{
	int fd = 1; // Standard output
	ft_putnbr_fd(42, fd);
	write(fd, "\n", 1);
	ft_putnbr_fd(-42, fd);
	write(fd, "\n", 1);
	ft_putnbr_fd(0, fd);
	write(fd, "\n", 1);
	return (0);
}
*/