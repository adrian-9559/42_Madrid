/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_width_precision.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 02:26:00 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/30 12:05:17 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*parse_width(const char *format,
		t_flags *flags, va_list *va)
{
	if (*format == '*')
	{
		flags->width = va_arg(*va, int);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->width = -flags->width;
			flags->zero = 0;
		}
		format++;
	}
	else if (*format >= '1' && *format <= '9')
	{
		flags->width = 0;
		while (*format >= '0' && *format <= '9')
			flags->width = flags->width * 10 + (*format++ - '0');
	}
	return (format);
}

static const char	*parse_precision(const char *format,
		t_flags *flags, va_list *va)
{
	if (*format == '*')
	{
		flags->precision = va_arg(*va, int);
		if (flags->precision < 0)
		{
			flags->dot = 0;
			flags->precision = 0;
		}
		format++;
	}
	else
	{
		flags->precision = 0;
		while (*format >= '0' && *format <= '9')
			flags->precision = flags->precision * 10 + (*format++ - '0');
	}
	return (format);
}

const char	*parse_width_precision(const char *format,
		t_flags *flags, va_list *va)
{
	format = parse_width(format, flags, va);
	if (*format == '.')
	{
		flags->dot = 1;
		format++;
		format = parse_precision(format, flags, va);
	}
	return (format);
}
