/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:06:12 by adriescr          #+#    #+#             */
/*   Updated: 2025/05/09 18:02:26 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_format(const char **format, va_list *va)
{
	int		count;
	int		specifier;

	count = 0;
	specifier = **format;
	if (specifier == 'c')
		count = ft_putchar(va_arg(*va, int));
	else if (specifier == 's')
		count = ft_putstr(va_arg(*va, char *));
	else if (specifier == 'p')
		count = ft_putptr(va_arg(*va, void *));
	else if (specifier == 'd' || specifier == 'i')
		count = ft_putnbr(va_arg(*va, int));
	else if (specifier == 'u')
		count = ft_putnbr_unsigned(va_arg(*va, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		count = ft_putnbr_base(va_arg(*va, unsigned int), specifier);
	else if (specifier == '%')
		count = ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	va;
	int		count;

	count = 0;
	va_start(va, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			count += ft_handle_format(&format, &va);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(va);
	return (count);
}
