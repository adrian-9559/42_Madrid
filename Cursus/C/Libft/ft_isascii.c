/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:45:29 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/16 19:49:32 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/*
#include <stdio.h>

int	main(void)
{
	int c = 65; // ASCII value for 'A'

	if (ft_isascii(c))
		printf("%c is an ASCII character\n", c);
	else
		printf("%c is not an ASCII character\n", c);

	c = 128; // Non-ASCII value

	if (ft_isascii(c))
		printf("%c is an ASCII character\n", c);
	else
		printf("%c is not an ASCII character\n", c);

	return (0);
}
*/
