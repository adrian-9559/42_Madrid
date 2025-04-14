/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian_9559 <adrian_9559@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:48:18 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/14 16:51:39 by adrian_9559      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	size_t			i;

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
