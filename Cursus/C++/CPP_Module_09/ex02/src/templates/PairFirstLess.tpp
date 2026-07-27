/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PairFirstLess.tpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 23:00:00 by adriescr          #+#    #+#             */
/*   Updated: 2026/07/26 23:03:39 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIRFIRSTLESS_TPP
# define PAIRFIRSTLESS_TPP

/**
 * ENGLISH: Functor that compares two pairs by their first element (ascending).
 *
 * SPANISH: Functor que compara dos pares por su primer elemento (ascendente).
 *
 * @tparam PairType The pair type. / El tipo del par.
 */
template <typename PairType>
struct PmergeMe_PairFirstLess
{
	/**
	 * ENGLISH: Returns true if lhs.first < rhs.first.
	 *
	 * SPANISH: Devuelve true si lhs.first < rhs.first.
	 *
	 * @param lhs The left-hand side pair. / El par izquierdo.
	 * @param rhs The right-hand side pair. / El par derecho.
	 *
	 * @return true if lhs.first is less than rhs.first. / true si lhs.first
	 *         es menor que rhs.first.
	 */
	bool operator()(const PairType &lhs, const PairType &rhs) const
	{
		return (lhs.first < rhs.first);
	}
};

#endif
