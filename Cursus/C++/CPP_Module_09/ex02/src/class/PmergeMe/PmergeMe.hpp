/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 23:00:00 by adriescr          #+#    #+#             */
/*   Updated: 2026/07/26 22:59:43 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <cstddef>
# include <deque>
# include <iostream>
# include <set>
# include <string>
# include <utility>
# include <vector>

/**
 * ENGLISH: Implements the merge-insertion sort algorithm (Ford-Johnson)
 *          using two STL containers (std::vector and std::deque).
 *
 * SPANISH: Implementa el algoritmo merge-insertion sort (Ford-Johnson)
 *          usando dos contenedores STL (std::vector y std::deque).
 */
class PmergeMe
{
	private:
		PmergeMe();

	public:
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		static bool	parseInput(int argc, char **argv, std::vector<int> &values);
		static void	printSequence(const std::vector<int> &values);

		template <typename Container>
		static Container mergeInsertionSort(const Container &input);
};

# include "../../templates/PairFirstLess.tpp"
# include "../../templates/buildJacobsthalOrder.tpp"
# include "../../templates/mergeInsertionSort.tpp"

#endif
