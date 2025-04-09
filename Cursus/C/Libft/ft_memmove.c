/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:48:59 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/09 12:00:18 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*source;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (dest == source || len == 0)
		return (dst);
	if (dest < source)
	{
		while (len--)
			*dest++ = *source++;
	}
	else
	{
		dest += len;
		source += len;
		while (len--)
			*(--dest) = *(--source);
	}
	return (dst);
}

/*
#include <stdio.h>

int	main(void)
{
	char str1[50] = "Hello World!";
	char str2[50] = "Goodbye World!";
	unsigned int len = 5;

	printf("Before memmove: %s\n", str1);
	ft_memmove(str1, str2, len);
	printf("After memmove: %s\n", str1);
	return (0);
}
*/
