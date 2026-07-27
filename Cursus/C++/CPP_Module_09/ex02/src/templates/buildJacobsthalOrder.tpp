/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildJacobsthalOrder.tpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 23:00:00 by adriescr          #+#    #+#             */
/*   Updated: 2026/07/26 23:03:28 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILDJACOBSTHALORDER_TPP
# define BUILDJACOBSTHALORDER_TPP

/**
 * ENGLISH: Builds the insertion order for the merge-insertion sort using
 *          Jacobsthal numbers. Determines which pair's second element to
 *          insert at each step for optimal comparisons.
 *
 * SPANISH: Construye el orden de inserción para el merge-insertion sort
 *          usando números de Jacobsthal. Determina qué segundo elemento
 *          de cada par insertar en cada paso para comparaciones óptimas.
 *
 * @tparam Container The container type (used for SFINAE / overload).
 *                   / El tipo del contenedor (para SFINAE / overload).
 *
 * @param count The number of pairs minus one. / El número de pares menos uno.
 *
 * @return A vector of indices specifying the insertion order.
 *         / Un vector de índices que especifica el orden de inserción.
 */
template <typename Container>
std::vector<size_t> PmergeMe_buildJacobsthalOrder(size_t count)
{
	std::vector<size_t> order;
	size_t previous = 1;
	size_t jacobPrev = 1;
	size_t jacobCurr = 3;

	if (count == 0)
		return (order);
	order.push_back(1);
	while (jacobCurr <= count)
	{
		for (size_t index = jacobCurr; index > previous; --index)
			order.push_back(index);
		previous = jacobCurr;
		const size_t next = jacobCurr + (2 * jacobPrev);
		jacobPrev = jacobCurr;
		jacobCurr = next;
	}
	for (size_t index = count; index > previous; --index)
		order.push_back(index);
	return (order);
}

#endif
