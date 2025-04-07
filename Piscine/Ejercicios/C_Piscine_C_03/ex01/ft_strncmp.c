/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:43:38 by adriescr          #+#    #+#             */
/*   Updated: 2025/02/26 18:00:37 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *arr1, char *arr2, unsigned int n)
{
	unsigned int	count;

	count = 0;
	while (count < n && arr1[count] != '\0' && arr2[count] != '\0')
	{
		if (arr1[count] != arr2[count])
			return (arr1[count] - arr2[count]);
		count++;
	}
	if (count == n)
		return (0);
	return (arr1[count] - arr2[count]);
}
