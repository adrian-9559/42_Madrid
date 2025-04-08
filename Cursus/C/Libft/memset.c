/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:48:18 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/08 17:47:38 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *b, int c, unsigned int len)
{
	unsigned char	*ptr;
	unsigned int	i;

	ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

/*
#include <stdio.h>

int	main(void)
{
	char str[50] = "Hello World!";
	int c = 'X';
	unsigned int len = 5;

	printf("Before memset: %s\n", str);
	ft_memset(str, c, len);
	printf("After memset: %s\n", str);
	return (0);
}
*/
