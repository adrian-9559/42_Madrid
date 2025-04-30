/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 14:01:49 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/30 01:59:02 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	handle_format(char specifier, va_list *va)
{
	size_t	count;

	count = 0;
	if (specifier == 's')
		count = ft_putstr(va_arg(*va, char *));
	else if (specifier == 'c')
		count = ft_putchar((char)va_arg(*va, int));
	else if (specifier == 'p')
		count = ft_putptr(va_arg(*va, void *));
	else if (specifier == 'i' || specifier == 'd')
		count = ft_putnbr(va_arg(*va, int));
	else if (specifier == 'u')
		count = ft_putnbr_unsigned(va_arg(*va, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		count = ft_putnbr_base(va_arg(*va, unsigned int), specifier);
	else if (specifier == '%')
		count = ft_putchar('%');
	return (count);
}

size_t	ft_printf(char const *str, ...)
{
	size_t	count_chr;
	va_list	va;

	va_start(va, str);
	count_chr = 0;
	while (*str)
	{
		if (*str == '%' && *(++str))
			count_chr += handle_format(*str, &va);
		else
			count_chr += ft_putchar(*str);
		str++;
	}
	va_end(va);
	return (count_chr);
}
