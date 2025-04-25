/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 23:29:23 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/26 00:52:30 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int		count;

	count = 0;
	if (ptr == NULL)
	{
		count += ft_putstr("(null)");
		return (count);
	}
	count += ft_putstr("0x");
	count += ft_putnbr_base((unsigned long)ptr, 0);
	return (count);
}
