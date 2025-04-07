/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:36:59 by adriescr          #+#    #+#             */
/*   Updated: 2025/03/05 13:55:44 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	control_limits(int nb)
{
	if (nb <= -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		nb = 147483648;
	}
	else if (nb > 2147483647)
	{
		write(1, "2", 1);
		nb = 147483648;
	}
	return (nb);
}

void	ft_putnbr(int nb)
{
	int		digits[10];
	int		i;
	char	c;

	nb = control_limits(nb);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb == 0)
		write(1, "0", 1);
	i = 0;
	while (nb > 0)
	{
		digits[i] = nb % 10;
		nb = nb / 10;
		i++;
	}
	while (i > 0)
	{
		i--;
		c = digits[i] + '0';
		write(1, &c, 1);
	}
}
