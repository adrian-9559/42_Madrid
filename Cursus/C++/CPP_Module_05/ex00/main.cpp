/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:43:39 by adriescr          #+#    #+#             */
/*   Updated: 2026/04/21 15:06:46 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/class/Bureaucrat/Bureaucrat.hpp"

int main()
{
	/* Normal usage */
	Bureaucrat a("Alice", 42);
	std::cout << a << std::endl;

	/* Exception handling */
	try
	{
		Bureaucrat b("Bob", 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat c("Charlie", 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	/* Incrementing and decrementing grade */
	Bureaucrat d("David", 100);
	std::cout << d << std::endl;
	d.incrementGrade();
	std::cout << d << std::endl;
	d.decrementGrade();
	std::cout << d << std::endl;

	/* Incrementing and decrementing grade exceptions */
	try
	{
		Bureaucrat e("Eve", 1);
		e.incrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat f("Frank", 150);
		f.decrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	/* Copy constructor and assignment operator */
	Bureaucrat g("Grace", 50);
	Bureaucrat h("Henry", 100);
	h = g;
	std::cout << g << std::endl;
	std::cout << h << std::endl;

	return 0;
}
