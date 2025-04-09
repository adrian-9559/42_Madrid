/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:07:48 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/09 12:28:51 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_toupper(unsigned int c)
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
