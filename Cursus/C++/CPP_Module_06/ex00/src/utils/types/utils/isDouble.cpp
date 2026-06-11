/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isDouble.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 18:00:32 by adriescr          #+#    #+#             */
/*   Updated: 2026/06/09 18:10:33 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils.hpp"

int	is_double(const std::string &literal)
{
	int	len;
	int	i;
	int	hasDot;

	len = static_cast<int>(literal.length());
	i = 0;
	hasDot = 0;
	if (len < 3)
		return (0);
	if (literal[i] == '-' || literal[i] == '+')
		i++;
	for (; i < len; i++)
	{
		if (literal[i] == '.' && !hasDot)
		{
			if (i == 0 || i == len - 1)
				return (0);
			hasDot = 1;
		}
		else if (!isdigit(literal[i]))
			return (0);
	}
	return (hasDot);
}
