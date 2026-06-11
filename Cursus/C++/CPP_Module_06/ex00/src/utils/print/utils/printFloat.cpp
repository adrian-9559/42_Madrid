/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printFloat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 18:13:01 by adriescr          #+#    #+#             */
/*   Updated: 2026/06/09 18:13:37 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils.hpp"

void printFloat(double d, bool parseOverflow)
{
	float f;

	if (parseOverflow)
	{
		std::cout << "float: impossible\n";
		return ;
	}
	if (isNan(d))
	{
		std::cout << "float: nanf\n";
		return ;
	}
	if (isPosInf(d))
	{
		std::cout << "float: +inff\n";
		return ;
	}
	if (isNegInf(d))
	{
		std::cout << "float: -inff\n";
		return ;
	}
	if (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
	{
		std::cout << "float: impossible\n";
		return ;
	}
	f = static_cast<float>(d);
	std::cout << "float: " << f;
	if (!hasDecimalOrExp(static_cast<double>(f)))
		std::cout << ".0f\n";
	else
		std::cout << "f\n";
}
