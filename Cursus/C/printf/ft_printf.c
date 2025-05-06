/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:06:12 by adriescr          #+#    #+#             */
/*   Updated: 2025/05/06 18:14:31 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_format(const char **format, va_list *va)
{
	t_flags	flags;
	int		count;
	char	specifier;

	count = 0;
	init_flags(&flags);
	*format = parse_flags(*format, &flags);
	*format = parse_width_precision(*format, &flags, va);
	specifier = **format;
	if (specifier == 'c')
		count = ft_handle_char(va_arg(*va, int), flags);
	else if (specifier == 's')
		count = ft_handle_string(va_arg(*va, char *), flags);
	else if (specifier == 'p')
		count = ft_handle_pointer(va_arg(*va, void *), flags);
	else if (specifier == 'd' || specifier == 'i')
		count = ft_handle_integer(va_arg(*va, int), flags);
	else if (specifier == 'u')
		count = ft_handle_unsigned(va_arg(*va, unsigned int), flags);
	else if (specifier == 'x' || specifier == 'X')
		count = ft_handle_hex(va_arg(*va, unsigned int), specifier, flags);
	else if (specifier == '%')
		count = ft_handle_percent(flags);
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
