/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:29:35 by adriescr          #+#    #+#             */
/*   Updated: 2026/02/26 19:31:04 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// Constructors
Weapon::Weapon(void)
{
}

Weapon::Weapon(std::string type)
{
	this->_type = type;
}

// Getters
const std::string& Weapon::getType(void) const
{
	return (this->_type);
}

// Setters
void Weapon::setType(std::string type)
{
	this->_type = type;
}

// Destructor
Weapon::~Weapon(void)
{
}
