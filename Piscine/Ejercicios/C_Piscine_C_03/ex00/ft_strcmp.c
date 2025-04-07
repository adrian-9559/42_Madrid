/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:30:20 by adriescr          #+#    #+#             */
/*   Updated: 2025/02/26 17:51:05 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *arr1, char *arr2)
{
	int	count;

	count = 0;
	while ((arr1[count] != '\0') && (arr2[count] != '\0'))
	{
		if (arr1[count] != arr2[count])
		{
			return (arr1[count] - arr2[count]);
		}
		count++;
	}
	if ((arr1[count] == '\0') && (arr2[count] == '\0'))
	{
		return (0);
	}
	else
	{
		return (arr1[count] - arr2[count]);
	}
}
