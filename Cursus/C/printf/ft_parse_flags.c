/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 02:05:22 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/30 03:15:10 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*parse_flags(const char *format, t_flags *flags)
{
	while (*format == '-' || *format == '0' || *format == '#'
		|| *format == '+' || *format == ' ')
	{
		if (*format == '-')
			flags->minus = 1;
		else if (*format == '0')
			flags->zero = 1;
		else if (*format == '#')
			flags->hash = 1;
		else if (*format == '+')
			flags->plus = 1;
		else if (*format == ' ')
			flags->space = 1;
		format++;
	}
	if (flags->minus)
		flags->zero = 0;
	return (format);
}
