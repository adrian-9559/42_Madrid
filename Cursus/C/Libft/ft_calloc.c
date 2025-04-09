/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:59:50 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/09 17:02:08 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
/*
#include <stdio.h>

int	main(void)
{
	int	*ptr;
	int	i;

	ptr = ft_calloc(5, sizeof(int));
	if (!ptr)
		return (1);
	for (i = 0; i < 5; i++)
	{
		printf("%d ", ptr[i]);
	}
	free(ptr);
	return (0);
}
*/
