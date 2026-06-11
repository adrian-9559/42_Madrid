/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isInt.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:58:50 by adriescr          #+#    #+#             */
/*   Updated: 2026/06/09 18:10:40 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils.hpp"

int	is_int(const std::string &literal)
{
	int	len;
	int	i;

	len = static_cast<int>(literal.length());
	i = 0;
	if (len == 0)
		return (0);
	if (literal[i] == '-' || literal[i] == '+')
		i++;
	if (i == len)
		return (0);
	for (; i < len; i++)
	{
		if (!isdigit(literal[i]))
			return (0);
	}
	return (1);
}
