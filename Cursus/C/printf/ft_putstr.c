/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 02:49:14 by adriescr          #+#    #+#             */
/*   Updated: 2025/05/09 17:58:17 by adriescr         ###   ########.fr       */
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
