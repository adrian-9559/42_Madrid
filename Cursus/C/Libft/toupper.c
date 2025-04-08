/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toupper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:07:48 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/08 18:10:05 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

/*
#include <stdio.h>

int main(void)
{
	int i;

	i = 0;
	while (i < 256)
	{
		printf("%c -> %c\n", i, ft_toupper(i));
		i++;
	}
	return (0);
}
*/
