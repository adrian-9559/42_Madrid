/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:15:30 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/08 18:20:11 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	const char	*last_occ;

	last_occ = 0;
	while (*s != '\0')
	{
		if (*s == (char)c)
			last_occ = s;
		s++;
	}
	if (last_occ != 0)
		return ((char *)last_occ);
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	char str[] = "Hello, World!";
	char *result;

	result = ft_strrchr(str, 'o');
	if (result)
		printf("Found: %s\n", result);
	else
		printf("Not found\n");
	return (0);
}
*/
