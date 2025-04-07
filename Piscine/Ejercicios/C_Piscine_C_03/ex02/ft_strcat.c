/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:07:03 by adriescr          #+#    #+#             */
/*   Updated: 2025/03/03 19:15:55 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	count_1;
	int	count_2;

	count_1 = 0;
	count_2 = 0;
	while (dest[count_1] != '\0')
		count_1++;
	while (src[count_2] != '\0')
	{
		dest[count_1] = src[count_2];
		count_1++;
		count_2++;
	}
	dest[count_1] = '\0';
	return (dest);
}
