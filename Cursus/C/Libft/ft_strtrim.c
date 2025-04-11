/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 09:39:28 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/11 09:45:23 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*trimmed_str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	trimmed_str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!trimmed_str)
		return (NULL);
	i = 0;
	while (start < end)
	{
		trimmed_str[i++] = s1[start++];
	}
	trimmed_str[i] = '\0';
	return (trimmed_str);
}

/*
int	main(void)
{
	char	*str = "   Hello, World!   ";
	char	*set = " ";
	char	*trimmed_str;

	trimmed_str = ft_strtrim(str, set);
	if (trimmed_str)
	{
		printf("Original string: '%s'\n", str);
		printf("Trimmed string: '%s'\n", trimmed_str);
		free(trimmed_str);
	}
	else
	{
		printf("Error trimming string.\n");
	}
	return (0);
}
*/
