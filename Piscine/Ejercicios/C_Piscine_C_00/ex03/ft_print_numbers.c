/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:59:37 by adriescr          #+#    #+#             */
/*   Updated: 2025/02/20 18:24:52 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	intnuminit;

	intnuminit = '0';
	while (intnuminit <= '9')
	{
		write(1, &intnuminit, 1);
		intnuminit++;
	}
}
