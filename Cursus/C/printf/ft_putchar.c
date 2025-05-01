/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:46:32 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/30 02:49:58 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnchar(char c, int n)
{
	int	count;

	count = 0;
	while (n-- > 0)
		count += ft_putchar(c);
	return (count);
}

int	ft_handle_char(char c, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.width > 1 && !flags.minus)
		count += ft_putnchar(' ', flags.width - 1);
	count += ft_putchar(c);
	if (flags.width > 1 && flags.minus)
		count += ft_putnchar(' ', flags.width - 1);
	return (count);
}

int	ft_handle_percent(t_flags flags)
{
	int	count;

	count = 0;
	if (flags.width > 1 && !flags.minus)
		count += ft_putnchar(' ', flags.width - 1);
	count += ft_putchar('%');
	if (flags.width > 1 && flags.minus)
		count += ft_putnchar(' ', flags.width - 1);
	return (count);
}
