/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:56:10 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/09 12:07:45 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *str2, size_t len)
{
	size_t	i;
	size_t	j;

	if (*str2 == '\0')
		return ((char *)str);
	i = 0;
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] == str2[j] && (i + j) < len)
		{
			if (!str2[j + 1])
				return ((char *)&str[i]);
			j++;
		}
		i++;
	}
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	char str1[] = "Hello, world!";
	char str2[] = "world";
	int len = 12;

	char *result = ft_strnstr(str1, str2, len);
	if (result)
		printf("Found: %s\n", result);
	else
		printf("Not found\n");
	return (0);
}
*/
