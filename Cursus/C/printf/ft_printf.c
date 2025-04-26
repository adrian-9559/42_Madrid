/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 14:01:49 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/27 00:59:41 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	handle_format(char specifier, va_list va)
{
	if (specifier == 's')
		return (ft_putstr(va_arg(va, char *)));
	else if (specifier == 'c')
		return (ft_putchar((char)va_arg(va, int)));
	else if (specifier == 'p')
		return (ft_putptr(va_arg(va, void *)));
	else if (specifier == 'i' || specifier == 'd')
		return (ft_putnbr(va_arg(va, int)));
	else if (specifier == 'u')
		return (ft_putnbr_unsigned(va_arg(va, unsigned int)));
	else if (specifier == 'x' || specifier == 'X')
		return (ft_putnbr_base(va_arg(va, unsigned int), specifier));
	else if (specifier == '%')
		return (ft_putchar('%'));
	return (0);
}

size_t	ft_printf(char const *str, ...)
{
	va_list	va;
	size_t	count_chr;

	if (!str)
		return (0);
	count_chr = 0;
	va_start(va, str);
	while (*str)
	{
		if (*str == '%' && *(++str))
			count_chr += handle_format(*str, va);
		else
			count_chr += ft_putchar(*str);
		str++;
	}
	va_end(va);
	return (count_chr);
}
