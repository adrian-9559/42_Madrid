/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:28:02 by adriescr          #+#    #+#             */
/*   Updated: 2025/05/09 17:58:57 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long nbr, int upper)
{
	int		count;
	char	*base;

	if (upper == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	count = 0;
	if (nbr >= 16)
		count += ft_putnbr_base(nbr / 16, upper);
	count += ft_putchar(base[nbr % 16]);
	return (count);
}
