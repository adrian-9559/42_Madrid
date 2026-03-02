/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:27:59 by adriescr          #+#    #+#             */
/*   Updated: 2026/02/26 19:02:33 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie " << name << " has been destroyed." << std::endl;
}

void Zombie::announce(void)
{
	std::cout << "Zombie " << name << " says: BraiiiiiiinnnzzzZ..." << std::endl;
}

