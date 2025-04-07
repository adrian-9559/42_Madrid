/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:45:10 by adriescr          #+#    #+#             */
/*   Updated: 2025/02/23 13:23:03 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char *d1, char *d2)
{
	write(1, d1, 2);
	write(1, " ", 1);
	write(1, d2, 2);
	if (!(d1[0] == '9' && d1[1] == '8' && d2[0] == '9' && d2[1] == '9'))
		write(1, ", ", 2);
}

char	*ft_translate_char(int digit, char *result)
{
	if (digit <= 9)
	{
		result[0] = '0';
		result[1] = digit + '0';
	}
	else
	{
		result[0] = digit / 10 + '0';
		result[1] = digit % 10 + '0';
	}
	return (result);
}

void	ft_print_comb2(void)
{
	int		d1;
	int		d2;
	char	r1[2];
	char	r2[2];

	d1 = 0;
	while (d1 <= 99)
	{
		d2 = d1 + 1;
		while (d2 <= 99)
		{
			ft_putchar(ft_translate_char(d1, r1), ft_translate_char(d2, r2));
			d2++;
		}
		d1++;
	}
}
