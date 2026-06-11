/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isFloat.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 18:02:00 by adriescr          #+#    #+#             */
/*   Updated: 2026/06/09 18:10:37 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils.hpp"

int	is_float(const std::string &literal)
{
	int	len;

	len = static_cast<int>(literal.length());
	if (len < 4)
		return (0);
	if (literal[len - 1] != 'f')
		return (0);
	std::string sub = literal.substr(0, len - 1);
	return (is_double(sub));
}
