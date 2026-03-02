/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:33:00 by adriescr          #+#    #+#             */
/*   Updated: 2026/03/02 16:33:51 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

// Constructors
HumanB::HumanB(void): _weapon(NULL)
{}

HumanB::HumanB(std::string name): _weapon(NULL)
{
	this->name = name;
}

// Methods
void HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}

void HumanB::attack(void) const
{
	if (this->_weapon)
		std::cout << this->name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->name << " has no weapon to attack with!" << std::endl;
}

// Destructor
HumanB::~HumanB(void)
{}
