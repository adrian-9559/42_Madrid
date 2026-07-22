/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 23:59:42 by adriescr          #+#    #+#             */
/*   Updated: 2026/07/22 00:04:08 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "../includes/easyfind.hpp"
#include <stdexcept>
#include <algorithm>
#include <map>

template <typename T>
typename T::iterator easyfind(T& container, int n)
{
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it != container.end())
		return it;
	throw std::runtime_error("Element not found");
}

template <typename K, typename V>
typename std::map<K, V>::iterator easyfind(std::map<K, V>& m, int n)
{
	typename std::map<K, V>::iterator it = m.find(n);
	if (it != m.end())
		return it;
	throw std::runtime_error("Element not found");
}

template <typename K, typename V>
typename std::map<K, V>::const_iterator easyfind(const std::map<K, V>& m, int n)
{
	typename std::map<K, V>::const_iterator it = m.find(n);
	if (it != m.end())
		return it;
	throw std::runtime_error("Element not found");
}

#endif
