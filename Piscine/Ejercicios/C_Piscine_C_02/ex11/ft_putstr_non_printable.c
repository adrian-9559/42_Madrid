/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:33:11 by adriescr          #+#    #+#             */
/*   Updated: 2025/03/03 18:51:22 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int		c;
	char	*hex;

	hex = "0123456789abcdef";
	c = 0;
	while (str[c] != '\0')
	{
		if (str[c] < 32 || str[c] > 126)
		{
			write(1, "\\", 1);
			write(1, &hex[str[c] / 16], 1);
			write(1, &hex[str[c] % 16], 1);
		}
		else
			write(1, &str[c], 1);
		c++;
	}
}
