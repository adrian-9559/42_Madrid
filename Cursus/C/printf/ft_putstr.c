/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 02:49:14 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/30 02:49:15 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int		count_char;

	count_char = 0;
	if (!str)
	{
		count_char += ft_putstr("(null)");
		return (count_char);
	}
	while (str[count_char] != '\0')
		count_char += ft_putchar(str[count_char]);
	return (count_char);
}

int	ft_handle_string(char *str, t_flags flags)
{
	int	count;
	int	len;

	count = 0;
	if (!str)
		str = "(null)";
	if (flags.precision >= 0 && flags.precision < (int)ft_strlen(str))
		len = flags.precision;
	else
		len = ft_strlen(str);
	if (flags.width > len && !flags.minus)
		count += ft_putnchar(' ', flags.width - len);
	count += ft_putstr_len(str, len);
	if (flags.width > len && flags.minus)
		count += ft_putnchar(' ', flags.width - len);
	return (count);
}
