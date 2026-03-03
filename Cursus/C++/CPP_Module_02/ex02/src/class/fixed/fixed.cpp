/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:57:16 by adriescr          #+#    #+#             */
/*   Updated: 2026/03/03 17:17:29 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : rawBits(0)
{
}

Fixed::Fixed(const int value)
{
	this->rawBits = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
	this->rawBits = static_cast<int>(roundf(value * (1 << fractionalBits)));
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed::~Fixed(void)
{
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->rawBits = other.rawBits;
	return (*this);
}

bool Fixed::operator>(const Fixed& other) const
{
	return (this->rawBits > other.rawBits);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (this->rawBits < other.rawBits);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (this->rawBits >= other.rawBits);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (this->rawBits <= other.rawBits);
}

bool Fixed::operator==(const Fixed& other) const
{
	return (this->rawBits == other.rawBits);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (this->rawBits != other.rawBits);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed& other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed& other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed& other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed& Fixed::operator++(void)
{
	++this->rawBits;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++this->rawBits;
	return (tmp);
}

Fixed& Fixed::operator--(void)
{
	--this->rawBits;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	--this->rawBits;
	return (tmp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

int Fixed::getRawBits(void) const
{
	return (this->rawBits);
}

void Fixed::setRawBits(int const raw)
{
	this->rawBits = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->rawBits) / (1 << fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->rawBits >> fractionalBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}
