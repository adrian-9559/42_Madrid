/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:56:32 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/09 12:36:03 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(unsigned int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	int c = 'A';

	if (ft_isalpha(c))
		printf("%c is an alphabetic character\n", c);
	else
		printf("%c is not an alphabetic character\n", c);

	c = '1';
	if (ft_isalpha(c))
		printf("%c is an alphabetic character\n", c);
	else
		printf("%c is not an alphabetic character\n", c);

	c = '#';
	if (ft_isalpha(c))
		printf("%c is an alphabetic character\n", c);
	else
		printf("%c is not an alphabetic character\n", c);

	return (0);
}
*/
