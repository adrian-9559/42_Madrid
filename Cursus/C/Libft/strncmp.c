/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:20:26 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/08 18:23:14 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	const char str1[] = "Hello";
	const char str2[] = "Hello, World!";
	int n = 5;

	int result = ft_strncmp(str1, str2, n);
	if (result == 0)
		printf("The first %d characters are equal.\n", n);
	else
		printf("The first %d characters are not equal.\n", n);
	return (0);
}
*/
