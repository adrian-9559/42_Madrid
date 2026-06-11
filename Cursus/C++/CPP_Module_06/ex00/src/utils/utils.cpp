/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 18:16:02 by adriescr          #+#    #+#             */
/*   Updated: 2026/06/09 18:16:39 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

bool hasDecimalOrExp(double num)
{
	std::ostringstream oss;
	oss << num;
	std::string s = oss.str();
	return (s.find('.') != std::string::npos || s.find('e') != std::string::npos);
}

bool isNan(double d)
{
	return (d != d);
}

bool isPosInf(double d)
{
	return (d == std::numeric_limits<double>::infinity());
}

bool isNegInf(double d)
{
	return (d == -std::numeric_limits<double>::infinity());
}

bool isInf(double d)
{
	return (isPosInf(d) || isNegInf(d));
}
