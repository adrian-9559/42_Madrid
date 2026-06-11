/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printDouble.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 18:12:47 by adriescr          #+#    #+#             */
/*   Updated: 2026/06/09 18:13:32 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils.hpp"

void printDouble(double d, bool parseOverflow)
{
	if (parseOverflow)
	{
		std::cout << "double: impossible\n";
		return ;
	}
	if (isNan(d))
	{
		std::cout << "double: nan\n";
		return ;
	}
	if (isPosInf(d))
	{
		std::cout << "double: +inf\n";
		return ;
	}
	if (isNegInf(d))
	{
		std::cout << "double: -inf\n";
		return ;
	}
	std::cout << "double: " << d;
	if (!hasDecimalOrExp(d))
		std::cout << ".0\n";
	else
		std::cout << "\n";
}
