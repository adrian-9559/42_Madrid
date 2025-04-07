/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 23:10:04 by adriescr          #+#    #+#             */
/*   Updated: 2025/03/11 23:10:07 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_strcat(char *str, char **strs, char *sep, int size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			str[k++] = strs[i][j++];
		}
		if (i < size - 1)
		{
			j = 0;
			while (sep[j] != '\0')
			{
				str[k++] = sep[j++];
			}
		}
		i++;
	}
	str[k] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		total_length;
	char	*str;

	if (size == 0)
	{
		str = (char *)malloc(sizeof(char));
		if (str)
			str[0] = '\0';
		return (str);
	}
	total_length = 0;
	i = 0;
	while (i < size)
	{
		total_length += ft_strlen(strs[i]);
		i++;
	}
	total_length += ft_strlen(sep) * (size - 1);
	str = (char *)malloc(sizeof(char) * (total_length + 1));
	if (!str)
		return (NULL);
	ft_strcat(str, strs, sep, size);
	return (str);
}
