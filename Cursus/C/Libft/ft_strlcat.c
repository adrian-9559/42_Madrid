/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:04:18 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/16 19:55:37 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	count_1;
	size_t	count_2;

	count_1 = 0;
	count_2 = 0;
	while (dest[count_1] != '\0' && count_1 < size)
		count_1++;
	while (src[count_2] != '\0' && count_1 + count_2 + 1 < size)
	{
		dest[count_1 + count_2] = src[count_2];
		count_2++;
	}
	if (count_1 < size)
		dest[count_1 + count_2] = '\0';
	while (src[count_2] != '\0')
		count_2++;
	return (count_1 + count_2);
}

/*
#include <stdio.h>

int main(void)
{
	char dest[20] = "Hello";
	const char src[] = " World!";
	unsigned int size = 15;

	printf("Before strlcat: %s\n", dest);
	ft_strlcat(dest, src, size);
	printf("After strlcat: %s\n", dest);
	return (0);
}
*/
