/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:10:36 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/09 12:07:55 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_tolower(unsigned int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
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
		printf("%c -> %c\n", i, ft_tolower(i));
		i++;
	}
	return (0);
}
*/
