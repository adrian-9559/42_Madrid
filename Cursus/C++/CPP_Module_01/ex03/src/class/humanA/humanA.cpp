/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:31:50 by adriescr          #+#    #+#             */
/*   Updated: 2026/03/02 16:33:41 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// Constructors
HumanA::HumanA(void): _weapon(*(new Weapon()))
{}

HumanA::HumanA(std::string name, Weapon& weapon): _weapon(weapon)
{
	this->name = name;
}

// Methods
void HumanA::attack(void) const
{
	std::cout << this->name << " attacks with their " << this->_weapon.getType() << std::endl;
}

// Destructor
HumanA::~HumanA(void)
{}
