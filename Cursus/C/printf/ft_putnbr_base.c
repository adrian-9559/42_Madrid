/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 21:02:12 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/25 23:25:05 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned int nbr, int upper)
{
	int		count;
	char	*base;

	if (upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	count = 0;
	if (nbr >= 16)
	{
		count += ft_putnbr_base(nbr / 16, upper);
		count += ft_putchar(base[nbr % 16]);
	}
	else
		count += ft_putchar(base[nbr]);
	return (count);
}
