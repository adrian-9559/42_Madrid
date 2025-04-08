/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:38:12 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/08 17:47:17 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	unsigned int	i;

	if (!dest && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char dest[50];
	const char src[] = "Hello, World!";
	size_t n = 13;

	ft_memcpy(dest, src, n);
	memcpy(dest, src, n); // Using the standard memcpy for comparison
	dest[n] = '\0'; // Null-terminate the destination string
	printf("Destination after memcpy: %s\n", dest);
	// Check if the custom memcpy works correctly
	if (strcmp(dest, src) == 0)
		printf("Custom memcpy works correctly!\n");
	else
		printf("Custom memcpy does not work correctly.\n");

	return 0;
}
*/
