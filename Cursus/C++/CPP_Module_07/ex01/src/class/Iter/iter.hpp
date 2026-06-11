/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 18:36:14 by adriescr          #+#    #+#             */
/*   Updated: 2026/06/09 18:36:15 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T, typename Func>
void iter(T *array, const size_t len, Func f)
{
	for (size_t i = 0; i < len; ++i)
		f(array[i]);
}

template <typename T, typename Func>
void iter(const T *array, const size_t len, Func f)
{
	for (size_t i = 0; i < len; ++i)
		f(array[i]);
}

#endif
