/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 00:52:48 by adriescr          #+#    #+#             */
/*   Updated: 2026/07/22 00:53:52 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/class/RPN/RPN.hpp"
#include <cctype>
#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	RPN	rpn;

	if (argc != 2)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	std::string input = argv[1];
	for (std::string::iterator it = input.begin(); it != input.end(); ++it)
	{
		if (*it == ' ')
			continue ;
		if (std::isdigit(static_cast<unsigned char>(*it)))
			rpn.pushNumber(*it - '0');
		else
		{
			if (rpn.compute(*it) == 0)
			{
				std::cerr << "Error" << std::endl;
				return (1);
			}
		}
	}
	if (rpn.size() != 1 || rpn.empty())
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	std::cout << rpn.top() << std::endl;
	return (0);
}
