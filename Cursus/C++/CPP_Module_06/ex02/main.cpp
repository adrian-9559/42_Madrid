/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 18:26:50 by adriescr          #+#    #+#             */
/*   Updated: 2026/06/09 18:30:26 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/class/Base/Base.hpp"
#include "./src/class/A.hpp"
#include "./src/class/B.hpp"
#include "./src/class/C.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

Base *generate(void)
{
	int n = rand() % 3;
	if (n == 0)
		return new A();
	if (n == 1)
		return new B();
	return new C();
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
}

void identify(Base& p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A\n";
		return;
	} catch (std::exception&) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B\n";
		return;
	} catch (std::exception&) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C\n";
		return;
	} catch (std::exception&) {}
}

int main()
{
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		Base *ptr = generate();
		std::cout << "pointer: ";
		identify(ptr);
		std::cout << "reference: ";
		identify(*ptr);
		delete ptr;
	}
	return 0;
}
