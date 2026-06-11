/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printResult.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 18:11:46 by adriescr          #+#    #+#             */
/*   Updated: 2026/06/09 18:13:43 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.hpp"

void printResult(double d, bool parseOverflow)
{
	if (isNan(d) || isInf(d) || d < 0 || d > 127)
		std::cout << "char: impossible\n";
	else if (!isprint(static_cast<int>(d)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(d) << "'\n";
	if (isNan(d) || isInf(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(d) << '\n';
	printFloat(d, parseOverflow);
	printDouble(d, parseOverflow);
}
