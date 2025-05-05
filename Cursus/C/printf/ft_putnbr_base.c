/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:28:02 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/30 16:21:20 by adriescr         ###   ########.fr       */
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

int	ft_handle_hex(unsigned int n, char specifier, t_flags flags)
{
	int		count;
	int		len;
	char	prefix[3];

	count = 0;
	prefix[0] = '0';
	if (specifier == 'x')
		prefix[1] = 'x';
	else
		prefix[1] = 'X';
	prefix[2] = '\0';
	len = ft_numlen_unsigned(n);
	if (flags.precision > len)
		len = flags.precision;
	if (flags.hash && n != 0)
		len += 2;
	if (flags.width > len && !flags.minus && !flags.zero)
		count += ft_putnchar(' ', flags.width - len);
	if (flags.hash && n != 0)
		count += ft_putstr(prefix);
	if (flags.width > len && flags.zero && !flags.minus)
		count += ft_putnchar('0', flags.width - len);
	if (flags.precision > ft_numlen_unsigned(n))
		count += ft_putnchar('0', flags.precision - ft_numlen_unsigned(n));
	count += ft_putnbr_base(n, (int)specifier);
	if (flags.width > len && flags.minus)
		count += ft_putnchar(' ', flags.width - len);
	return (count);
}
