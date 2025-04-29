/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 20:13:35 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/28 20:17:47 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_putstr_fd(char *str, int fd)
{
	size_t count_char;

	count_char = 0;
	if (!str)
		return(count_char);
	while(*str)
		count_char += ft_putchar_fd(str, fd);
	return(count_char);
}
