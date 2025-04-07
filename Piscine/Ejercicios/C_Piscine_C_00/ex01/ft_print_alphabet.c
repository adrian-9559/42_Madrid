/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:57:05 by adriescr          #+#    #+#             */
/*   Updated: 2025/02/20 16:26:27 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	chrinit;

	chrinit = 'a';
	while (chrinit <= 'z')
	{
		write(1, &chrinit, 1);
		chrinit++;
	}
}
