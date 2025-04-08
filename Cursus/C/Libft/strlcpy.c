/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:55:01 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/08 18:04:08 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int size)
{
	unsigned int	i;

	if (size == 0)
		return (0);
	i = 0;
	while (i < size && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

/*
#include <stdio.h>

int	main(void)
{
	char	src[] = "Hello, World!";
	char	dst[20];
	unsigned int	size = 10;

	printf("Custom strlcpy: %u\n", ft_strlcpy(dst, src, size));
	printf("Destination string: %s\n", dst);
	return (0);
}
*/
