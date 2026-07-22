/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutandstack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 00:13:11 by adriescr          #+#    #+#             */
/*   Updated: 2026/07/22 00:22:59 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../class/MuntandStack/MutandStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}
