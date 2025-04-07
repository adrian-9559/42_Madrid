/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:53:50 by adriescr          #+#    #+#             */
/*   Updated: 2025/02/20 21:08:04 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char digit1, char digit2, char digit3)
{
	write(1, &digit1, 1);
	write(1, &digit2, 1);
	write(1, &digit3, 1);
}

void	ft_print_comb(void)
{
	char	digit1;
	char	digit2;
	char	digit3;

	digit1 = '0';
	while (digit1 <= '9')
	{
		digit2 = digit1 + 1;
		while (digit2 <= '9')
		{
			digit3 = digit2 + 1;
			while (digit3 <= '9')
			{
				ft_putchar(digit1, digit2, digit3);
				if (!(digit1 == '7' && digit2 == '8' && digit3 == '9'))
				{
					write(1, ", ", 2);
				}
				digit3++;
			}
			digit2++;
		}
		digit1++;
	}
}
