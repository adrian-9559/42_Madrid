/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian_9559 <adrian_9559@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:24:09 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/14 16:51:20 by adrian_9559      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)(str + i));
		i++;
	}
	return (0);
}

/*
#include <stdio.h>

int main(void)
{
	char str[] = "Hello, World!";
	char *result;

	result = ft_memchr(str, 'W', 13);
	if (result != 0)
		printf("Found: %s\n", result);
	else
		printf("Not found\n");

	return (0);
}
*/
