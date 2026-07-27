/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeInsertionSort.tpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 23:00:00 by adriescr          #+#    #+#             */
/*   Updated: 2026/07/26 23:03:33 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MERGEINSERTIONSORT_TPP
# define MERGEINSERTIONSORT_TPP

/**
 * ENGLISH: Implements the merge-insertion sort algorithm (Ford-Johnson).
 *          Pairs elements, sorts the pairs by their larger element,
 *          and inserts the smaller elements using binary search in
 *          Jacobsthal-optimal order.
 *
 * SPANISH: Implementa el algoritmo merge-insertion sort (Ford-Johnson).
 *          Empareja elementos, ordena los pares por su elemento mayor,
 *          e inserta los elementos menores usando búsqueda binaria en
 *          orden óptimo de Jacobsthal.
 *
 * @tparam Container The container type (std::vector or std::deque).
 *                   / El tipo del contenedor (std::vector o std::deque).
 *
 * @param input The unsorted input container. / El contenedor de entrada
 *              desordenado.
 *
 * @return A new container with the sorted elements.
 *         / Un nuevo contenedor con los elementos ordenados.
 */
template <typename Container>
Container PmergeMe::mergeInsertionSort(const Container &input)
{
	typedef typename Container::value_type		ValueType;
	typedef std::pair<ValueType, ValueType>		PairType;

	Container result;
	std::vector<PairType> pairs;
	std::vector<size_t> order;
	bool hasStraggler = false;
	ValueType straggler = ValueType();
	typename Container::const_iterator it = input.begin();

	if (input.size() <= 1)
		return (input);
	while (it != input.end())
	{
		ValueType first = *it;
		++it;
		if (it == input.end())
		{
			straggler = first;
			hasStraggler = true;
			break ;
		}
		ValueType second = *it;
		++it;
		if (first < second)
			std::swap(first, second);
		pairs.push_back(PairType(first, second));
	}
	if (pairs.empty())
	{
		if (hasStraggler)
			result.push_back(straggler);
		return (result);
	}
	std::sort(pairs.begin(), pairs.end(), PmergeMe_PairFirstLess<PairType>());
	result.push_back(pairs[0].second);
	result.push_back(pairs[0].first);
	for (size_t index = 1; index < pairs.size(); ++index)
		result.push_back(pairs[index].first);
	order = PmergeMe_buildJacobsthalOrder<Container>(pairs.size() - 1);
	for (size_t i = 0; i < order.size(); ++i)
	{
		const size_t pairIndex = order[i];
		if (pairIndex >= pairs.size())
			continue ;
		result.insert(std::upper_bound(result.begin(), result.end(), pairs[pairIndex].second), pairs[pairIndex].second);
	}
	if (hasStraggler)
		result.insert(std::upper_bound(result.begin(), result.end(), straggler), straggler);
	return (result);
}

#endif
