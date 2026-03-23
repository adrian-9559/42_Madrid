/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 13:36:07 by adriescr          #+#    #+#             */
/*   Updated: 2026/03/17 13:42:04 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FlagTrap.hpp"

FlagTrap::FlagTrap(void) : ClapTrap()
{
	std::cout << "FlagTrap default constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FlagTrap::FlagTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FlagTrap parameterized constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FlagTrap::FlagTrap(const FlagTrap &other) : ClapTrap(other)
{
	std::cout << "FlagTrap copy constructor called" << std::endl;
}

FlagTrap::~FlagTrap(void)
{
	std::cout << "FlagTrap destructor called" << std::endl;
}

FlagTrap &FlagTrap::operator=(const FlagTrap &other)
{
	std::cout << "FlagTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

void FlagTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "FlagTrap " << this->_name << " attacks " << target
				  << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else
	{
		std::cout << "FlagTrap " << this->_name << " cannot attack!" << std::endl;
	}
}

void FlagTrap::highFivesGuys(void)
{
	std::cout << "FlagTrap " << this->_name << " is requesting a high five!" << std::endl;
}
