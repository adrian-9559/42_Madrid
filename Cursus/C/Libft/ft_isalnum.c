/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:37:51 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/09 11:59:47 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(unsigned int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	int c = 'A';

	if (ft_isalnum(c))
		printf("%c is alphanumeric\n", c);
	else
		printf("%c is not alphanumeric\n", c);

	c = '1';
	if (ft_isalnum(c))
		printf("%c is alphanumeric\n", c);
	else
		printf("%c is not alphanumeric\n", c);

	c = '#';
	if (ft_isalnum(c))
		printf("%c is alphanumeric\n", c);
	else
		printf("%c is not alphanumeric\n", c);

	return (0);
}
*/
