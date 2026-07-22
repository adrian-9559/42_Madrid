/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 00:05:47 by adriescr          #+#    #+#             */
/*   Updated: 2026/07/22 00:09:20 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/class/Span/Span.hpp"
#include <cstdlib>
#include <ctime>
#include <deque>
#include <exception>
#include <iostream>
#include <list>
#include <set>
#include <vector>

static void printTitle(const std::string &title)
{
	std::cout << "\n====== " << title << " ======" << std::endl;
}

int main(void)
{
	// 0) Test basico
	std::cout << "=== Test basico ===" << std::endl;
	{
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan:  " << sp.longestSpan() << std::endl;
	}

	// 1) Negativos y mezcla
	printTitle("Negativos y mezcla signos");
	{
		Span sp(8);
		sp.addNumber(-10);
		sp.addNumber(0);
		sp.addNumber(42);
		sp.addNumber(-9999);
		sp.addNumber(5);
		sp.addNumber(-1);
		sp.addNumber(100);
		sp.addNumber(-100);
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan:  " << sp.longestSpan() << std::endl;
	}

	// 2) Span exacta al límite (addNumber uno a uno)
	printTitle("Llenado exacto uno a uno");
	{
		Span sp(3);
		sp.addNumber(100);
		sp.addNumber(200);
		sp.addNumber(300);
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan:  " << sp.longestSpan() << std::endl;
	}

	// 3) Dos elementos iguales → shortestSpan = 0
	printTitle("Duplicados (shortestSpan = 0)");
	{
		Span sp(5);
		sp.addNumber(7);
		sp.addNumber(7);
		sp.addNumber(3);
		sp.addNumber(9);
		sp.addNumber(7);
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan:  " << sp.longestSpan() << std::endl;
	}

	// 4) INT_MAX e INT_MIN
	printTitle("Limites de int");
	{
		Span sp(4);
		sp.addNumber(INT_MAX);
		sp.addNumber(INT_MIN);
		sp.addNumber(0);
		sp.addNumber(42);
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan:  " << sp.longestSpan() << std::endl;
	}

	// 5) addNumbers (vector overload) con varios casos
	printTitle("addNumbers (vector overload)");
	{
		std::vector<int> v;
		for (int i = 0; i < 10; ++i)
			v.push_back(i * 10);

		Span sp(10);
		sp.addNumbers(v);
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan:  " << sp.longestSpan() << std::endl;
	}

	// 6) addRange con diferentes contenedores (deque, list)
	printTitle("addRange con deque y list");
	{
		std::deque<int> d;
		d.push_back(1);
		d.push_back(100);
		d.push_back(50);
		d.push_back(99);
		d.push_back(2);
		Span sp1(5);
		sp1.addRange(d.begin(), d.end());
		std::cout << "sp1 (deque): " << sp1.shortestSpan() << " / "
				  << sp1.longestSpan() << std::endl;

		std::list<int> lst;
		lst.push_back(1000);
		lst.push_back(2000);
		lst.push_back(1500);
		lst.push_back(3000);
		Span sp2(4);
		sp2.addRange(lst.begin(), lst.end());
		std::cout << "sp2 (list):  " << sp2.shortestSpan() << " / "
				  << sp2.longestSpan() << std::endl;
	}

	// 7) Copy constructor
	printTitle("Copy constructor");
	{
		Span original(5);
		original.addNumber(10);
		original.addNumber(20);
		original.addNumber(30);
		original.addNumber(40);
		original.addNumber(50);

		Span copia(original);
		std::cout << "original:  " << original.shortestSpan() << " / "
				  << original.longestSpan() << std::endl;
		std::cout << "copia:     " << copia.shortestSpan() << " / "
				  << copia.longestSpan() << std::endl;

		// Verificar que son independientes añadiendo otro elemento (debe lanzar)
		try
		{
			copia.addNumber(999);
			std::cout << "ERROR: copia debio estar llena" << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "copia llena (OK): " << e.what() << std::endl;
		}
	}

	// 8) Assignment operator
	printTitle("Assignment operator");
	{
		Span a(3);
		a.addNumber(5);
		a.addNumber(15);
		a.addNumber(25);

		Span b(10);
		b = a;
		std::cout << "a: " << a.shortestSpan() << " / " << a.longestSpan()
				  << std::endl;
		std::cout << "b: " << b.shortestSpan() << " / " << b.longestSpan()
				  << std::endl;

		// b debe tener capacidad 3 (se copia _maxSize)
		try
		{
			b.addNumber(999);
			std::cout << "ERROR: b debio estar llena" << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "b llena (OK): " << e.what() << std::endl;
		}
	}

	// 9) Excepciones: shortestSpan/longestSpan con 0 y 1 elementos
	printTitle("Excepciones: 0 y 1 elementos");
	{
		try
		{
			Span vacio(5);
			vacio.shortestSpan();
			std::cout << "ERROR: debio lanzar excepcion" << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "shortestSpan vacio: " << e.what() << std::endl;
		}

		try
		{
			Span uno(5);
			uno.addNumber(42);
			uno.longestSpan();
			std::cout << "ERROR: debio lanzar excepcion" << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "longestSpan con 1:   " << e.what() << std::endl;
		}
	}

	// 10) Excepcion de llenado con addNumbers
	printTitle("Excepciones de llenado");
	{
		try
		{
			std::vector<int> v(10, 1);
			Span sp(5);
			sp.addNumbers(v);
			std::cout << "ERROR: addNumbers debio lanzar" << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "addNumbers full: " << e.what() << std::endl;
		}
	}

	// 11) Numeros en orden descendente
	printTitle("Orden descendente");
	{
		Span sp(6);
		sp.addNumber(1000);
		sp.addNumber(500);
		sp.addNumber(250);
		sp.addNumber(125);
		sp.addNumber(62);
		sp.addNumber(31);
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan:  " << sp.longestSpan() << std::endl;
	}

	// 12) 20000 numeros con addRange (estres)
	printTitle("Estres: 20000 numeros");
	{
		std::srand((unsigned int)std::time(NULL));
		std::vector<int> v;
		v.reserve(20000);
		for (int i = 0; i < 20000; ++i)
			v.push_back(std::rand());

		Span sp(20000);
		sp.addRange(v.begin(), v.end());
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan:  " << sp.longestSpan() << std::endl;
	}

	// 13) Numeros identicos en cascada
	printTitle("Cascada de iguales");
	{
		Span sp(10);
		for (int i = 0; i < 10; ++i)
			sp.addNumber(5);
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan:  " << sp.longestSpan() << std::endl;
	}

	// 14) Rango muy pequeno: solo 2 elementos consecutivos
	printTitle("Solo 2 elementos consecutivos");
	{
		Span sp(2);
		sp.addNumber(10);
		sp.addNumber(11);
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan:  " << sp.longestSpan() << std::endl;
	}

	// 15) addRange con set (contendor asociativo)
	printTitle("addRange con std::set");
	{
		std::set<int> s;
		s.insert(5);
		s.insert(15);
		s.insert(25);
		s.insert(30);
		s.insert(3);

		Span sp(5);
		sp.addRange(s.begin(), s.end());
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan:  " << sp.longestSpan() << std::endl;
	}

	return (0);
}
