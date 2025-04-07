/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:22:51 by adriescr          #+#    #+#             */
/*   Updated: 2025/03/03 19:28:06 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	count_1;
	int	count_2;

	count_1 = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[count_1] != '\0')
	{
		count_2 = 0;
		while (str[count_1 + count_2] == to_find[count_2])
		{
			if (to_find[count_2 + 1] == '\0')
				return (&str[count_1]);
			count_2++;
		}
		count_1++;
	}
	return (0);
}
