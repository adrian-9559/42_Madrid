/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 02:49:14 by adriescr          #+#    #+#             */
/*   Updated: 2025/05/13 18:26:58 by adriescr         ###   ########.fr       */
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

	count = 0;
	if (!str)
		str = "(null)";
	if (flags.dot && flags.precision < (int)ft_strlen(str))
		str = ft_substr(str, 0, flags.precision);
	if (!flags.minus && flags.width > (int)ft_strlen(str))
		count += ft_putnchar(' ', flags.width - ft_strlen(str));
	count += ft_putstr(str);
	if (flags.minus && flags.width > (int)ft_strlen(str))
		count += ft_putnchar(' ', flags.width - ft_strlen(str));
	if (flags.dot && flags.precision < (int)ft_strlen(str))
		free(str);
	return (count);
}
