/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getType.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 18:09:49 by adriescr          #+#    #+#             */
/*   Updated: 2026/06/09 18:10:45 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.hpp"

int getType(const std::string &literal)
{
	if (is_char(literal))
		return 0;
	else if (is_int(literal))
		return 1;
	else if (is_float(literal))
		return 2;
	else if (is_double(literal))
		return 3;
	else if (literal == "nan" || literal == "+inf" || literal == "-inf" || literal == "inf")
		return 4;
	else if (literal == "nanf" || literal == "+inff" || literal == "-inff" || literal == "inff")
		return 5;
	return -1;
}
