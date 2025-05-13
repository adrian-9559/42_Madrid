/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_printf.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: adriescr <adriescr@student.42madrid.com	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/04/30 12:06:12 by adriescr		  #+#	#+#			 */
/*   Updated: 2025/05/13 17:07:58 by adriescr		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->precision = -1;
	flags->dot = 0;
	flags->hash = 0;
	flags->plus = 0;
	flags->space = 0;
}

static t_flags	ft_parse_flags(const char **format)
{
	t_flags	flags;

	init_flags(&flags);
	while (**format == '-' || **format == '0' || **format == '#' || **format == '+' || **format == ' ')
	{
		if (**format == '-')
			flags.minus += 1;
		else if (**format == '0')
			flags.zero += 1;
		else if (**format == '#')
			flags.hash += 1;
		else if (**format == '+')
			flags.plus += 1;
		else if (**format == ' ')
			flags.space += 1;
		(*format)++;
	}
	while (**format >= '0' && **format <= '9')
		flags.width = flags.width * 10 + (*((*format)++) - '0');
	if (**format == '.')
	{
		flags.dot = 1;
		flags.precision = 0;
		while (*++(*format) >= '0' && **format <= '9')
			flags.precision = flags.precision * 10 + (**format - '0');
	}
	return (flags);
}

static int	ft_handle_format(const char **format, va_list *va)
{
	int		count;
	t_flags	flags;

	count = 0;
	flags = ft_parse_flags(format);
	if (**format == 'c')
		count += ft_handle_char(va_arg(*va, int), flags);
	else if (**format == 's')
		count += ft_handle_string(va_arg(*va, char *), flags);
	else if (**format == 'p')
		count += ft_handle_pointer(va_arg(*va, void *), flags);
	else if (**format == 'd' || **format == 'i')
		count += ft_handle_integer(va_arg(*va, int), flags);
	else if (**format == 'u')
		count += ft_handle_unsigned(va_arg(*va, unsigned int), flags);
	else if (**format == 'x' || **format == 'X')
		count += ft_handle_hex(va_arg(*va, unsigned int), **format, flags);
	else if (**format == '%')
		count += ft_handle_char('%', flags);
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
