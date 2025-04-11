/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 09:15:23 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/11 09:31:25 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen((char *)s);
	if (start >= str_len)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}

/*
int	main(void)
{
	char	*s = "Hello, World!";
	char	*substr;

	substr = ft_substr(s, 7, 5);
	if (substr)
	{
		printf("Substring: %s\n", substr);
		free(substr);
	}
	else
	{
		printf("Error allocating memory for substring.\n");
	}
	return (0);
}
*/
