/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:46:32 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/09 12:00:04 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(unsigned int c)
{
	return (c >= 32 && c <= 126);
}

/*
#include <stdio.h>

int	main(void)
{
	int c = 65; // ASCII value for 'A'

	if (ft_isprint(c))
		printf("%c is a printable character\n", c);
	else
		printf("%c is not a printable character\n", c);

	c = 31; // Non-printable value

	if (ft_isprint(c))
		printf("%c is a printable character\n", c);
	else
		printf("%c is not a printable character\n", c);

	return (0);
}
*/
