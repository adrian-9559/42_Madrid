/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 02:47:47 by adriescr          #+#    #+#             */
/*   Updated: 2025/05/08 17:44:44 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int	count;

	count = 0;
	if (ptr == NULL)
	{
		count += ft_putstr("(nil)");
		return (count);
	}
	count += ft_putstr("0x");
	count += ft_putnbr_base((unsigned long)ptr, 'x');
	return (count);
}

int	ft_handle_pointer(void *ptr, t_flags flags)
{
	int	count;
	int	len;

	count = 0;
	len = ft_ptrlen(ptr);
	if (flags.width > len && !flags.minus)
		count += ft_putnchar(' ', flags.width - len);
	count += ft_putptr(ptr);
	if (flags.width > len && flags.minus)
		count += ft_putnchar(' ', flags.width - len);
	return (count);
}
