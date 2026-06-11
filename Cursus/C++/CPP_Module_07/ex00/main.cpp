/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 18:34:17 by adriescr          #+#    #+#             */
/*   Updated: 2026/06/09 18:34:29 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/class/whatever/whatever.hpp"
#include <iostream>

int main()
{
	int a = 2;
	int b = 3;
	double c = 2.5;
	double d = 3.5;
	float e = 2.5f;
	float f = 3.5f;

	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	::swap(a, b);
	std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

		std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
	::swap(c, d);
	std::cout << "After swap: c = " << c << ", d = " << d << std::endl;

		std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min(e, f) = " << ::min(e, f) << std::endl;
	std::cout << "max(e, f) = " << ::max(e, f) << std::endl;
	::swap(e, f);
	std::cout << "After swap: e = " << e << ", f = " << f << std::endl;

}
