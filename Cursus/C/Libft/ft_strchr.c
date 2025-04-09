/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:13:33 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/09 12:00:25 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, size_t c)
{
	while (*s != (char)c && *s != '\0')
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	char str[] = "Hello, World!";
	char *result;

	result = ft_strchr(str, 'W');
	if (result)
		printf("Found: %s\n", result);
	else
		printf("Not found\n");
	return (0);
}
*/
