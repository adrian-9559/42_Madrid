/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 18:40:01 by adriescr          #+#    #+#             */
/*   Updated: 2026/06/09 18:40:18 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "../class/Array.hpp"
#include <stdexcept>

template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(Array const &other) : _data(NULL), _size(0)
{
	*this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		delete[] _data;
		_size = other._size;
		_data = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_data[i] = other._data[i];
	}
	return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw OutOfBoundsException();
	return (_data[index]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw OutOfBoundsException();
	return (_data[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}

template <typename T>
Array<T>::~Array()
{
	delete[] _data;
}

#endif
