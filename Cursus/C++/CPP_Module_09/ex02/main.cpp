/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 23:00:00 by adriescr          #+#    #+#             */
/*   Updated: 2026/07/26 22:59:43 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/class/PmergeMe/PmergeMe.hpp"
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

/**
 * ENGLISH: Converts clock ticks into elapsed time in microseconds.
 *
 * SPANISH: Convierte los ticks de reloj en tiempo transcurrido en
 * microsegundos.
 *
 * @param start The starting clock value. / El valor de reloj inicial.
 * @param end   The ending clock value. / El valor de reloj final.
 *
 * @return The elapsed time in microseconds. // El tiempo transcurrido en
 *         microsegundos.
 */
static double elapsedMicroseconds(const clock_t start, const clock_t end)
{
	return (static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC);
}

/**
 * ENGLISH: Entry point. Parses input, sorts with both vector and deque,
 *         and prints the results with timing.
 *
 * SPANISH: Punto de entrada. Analiza la entrada, ordena con vector y deque,
 *          e imprime los resultados con tiempos.
 *
 * @param argc The argument count. / El conteo de argumentos.
 * @param argv The argument vector. / El vector de argumentos.
 *
 * @return 0 on success, 1 on error. // 0 en éxito, 1 en error.
 */
int	main(int argc, char **argv)
{
	vector<int>	inputValues;

	if (!PmergeMe::parseInput(argc, argv, inputValues))
	{
		cerr << "Error" << endl;
		return (1);
	}
	cout << "Before: ";
	PmergeMe::printSequence(inputValues);
	clock_t vectorStart = clock();
	vector<int> vectorResult = PmergeMe::mergeInsertionSort(inputValues);
	clock_t vectorEnd = clock();
	deque<int> dequeInput(inputValues.begin(), inputValues.end());
	clock_t dequeStart = clock();
	deque<int> dequeResult = PmergeMe::mergeInsertionSort(dequeInput);
	clock_t dequeEnd = clock();
	(void)dequeResult;
	cout << "After: ";
	PmergeMe::printSequence(vectorResult);
	cout << fixed << setprecision(5);
	cout << "Time to process a range of " << inputValues.size()
		<< " elements with std::vector : " << elapsedMicroseconds(vectorStart, vectorEnd)
		<< " us" << endl;
	cout << "Time to process a range of " << inputValues.size()
		<< " elements with std::deque : " << elapsedMicroseconds(dequeStart, dequeEnd)
		<< " us" << endl;
	return (0);
}
