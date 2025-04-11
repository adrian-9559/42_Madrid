/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 09:46:46 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/11 11:24:11 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
    int		i;
    int		j;
    int		k;
    char	**result;

    result = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
    if (!s || !result)
        return (NULL);
    i = 0;
    j = 0;
    while (s[i])
        if (s[i] != c)
        {
            k = 0;
            while (s[i + k] && s[i + k] != c)
                k++;
            result[j] = ft_substr(s, i, k);
            j++;
            i += k;
        }
        else
            i++;
    result[j] = NULL;
    return (result);
}

/*
int	main(void)
{
	char *str = "Hello, World! This is a test.";
	char **result = ft_split(str, ' ');

	for (int i = 0; result[i] != NULL; i++)
	{
		printf("%s\n", result[i]);
		free(result[i]);
	}
	free(result);
	return (0);
}
*/
