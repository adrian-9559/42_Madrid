/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 00:06:21 by adriescr          #+#    #+#             */
/*   Updated: 2026/07/22 00:06:22 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>

Span::Span() : _maxSize(0)
{
}

Span::Span(unsigned int n) : _maxSize(n)
{
}

Span::Span(const Span &other) : _maxSize(other._maxSize), _values(other._values)
{
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_values = other._values;
	}
	return (*this);
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
	if (_values.size() >= _maxSize)
		throw SpanFullException();
	_values.push_back(n);
}

long long Span::shortestSpan()
{
	long long	minSpan;
	long long	span;

	if (_values.size() < 2)
		throw NoSpanFoundException();
	std::vector<long long> sorted(_values.begin(), _values.end());
	std::sort(sorted.begin(), sorted.end());
	minSpan = sorted[1] - sorted[0];
	for (size_t i = 1; i + 1 < sorted.size(); i++)
	{
		span = sorted[i + 1] - sorted[i];
		if (span < minSpan)
			minSpan = span;
	}
	return (minSpan);
}

long long Span::longestSpan()
{
	if (_values.size() < 2)
		throw NoSpanFoundException();

	long long maxVal = *std::max_element(_values.begin(), _values.end());
	long long minVal = *std::min_element(_values.begin(), _values.end());
	return (maxVal - minVal);
}
