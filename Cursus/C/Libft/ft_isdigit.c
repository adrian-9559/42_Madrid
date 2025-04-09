/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:35:59 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/09 11:59:58 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(unsigned int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	int c = '5';

	if (ft_isdigit(c))
		printf("%c is a digit\n", c);
	else
		printf("%c is not a digit\n", c);

	c = 'A';
	if (ft_isdigit(c))
		printf("%c is a digit\n", c);
	else
		printf("%c is not a digit\n", c);

	c = '#';
	if (ft_isdigit(c))
		printf("%c is a digit\n", c);
	else
		printf("%c is not a digit\n", c);

	return (0);
}
*/
