/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 18:18:19 by adriescr          #+#    #+#             */
/*   Updated: 2026/06/09 18:18:31 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}
ScalarConverter::ScalarConverter(const ScalarConverter &)
{
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &)
{
	return (*this);
}
ScalarConverter::~ScalarConverter()
{
}


void ScalarConverter::convert(const std::string &literal)
{
	double	d = 0.0;
	bool	parseOverflow = false;
	bool	invalid = false;
	int		type = getType(literal);

	switch (type)
	{
	case -1:
		invalid = true;
		break ;
	case 0:
		d = static_cast<double>(literal[0]);
		break ;
	case 1:
	case 2:
	case 3:
		if (!parseNumberLiteral(literal, type, d))
		{
			invalid = true;
			break ;
		}
		parseOverflow = (errno == ERANGE);
		break ;
	case 4:
		if (literal == "nan")
			d = std::numeric_limits<double>::quiet_NaN();
		else if (literal == "+inf" || literal == "inf")
			d = std::numeric_limits<double>::infinity();
		else
			d = -std::numeric_limits<double>::infinity();
		break ;
	case 5:
		if (literal == "nanf")
			d = std::numeric_limits<float>::quiet_NaN();
		else if (literal == "+inff" || literal == "inff")
			d = std::numeric_limits<float>::infinity();
		else
			d = -std::numeric_limits<float>::infinity();
		break ;
	default:
		break ;
	}
	if (invalid)
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
	}
	else
		printResult(d, parseOverflow);
}
