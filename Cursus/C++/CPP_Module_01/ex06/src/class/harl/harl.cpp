/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:52:46 by adriescr          #+#    #+#             */
/*   Updated: 2026/03/02 17:04:42 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// Constructor
Harl::Harl(void)
{}

// Destructor
Harl::~Harl(void)
{}

void Harl::debug(void) const
{
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void Harl::info(void) const
{
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning(void) const
{
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void Harl::error(void) const
{
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level)
{
	if (level == "DEBUG")
		this->debug();
	else if (level == "INFO")
		this->info();
	else if (level == "WARNING")
		this->warning();
	else if (level == "ERROR")
		this->error();
	else
		std::cout << "[ Probably complaining about insignificant problems ]\n";
}

void Harl::filter(std::string level)
{
	int lvl = -1;
	if (level == "DEBUG")
		lvl = 0;
	else if (level == "INFO")
		lvl = 1;
	else if (level == "WARNING")
		lvl = 2;
	else if (level == "ERROR")
		lvl = 3;

	switch (lvl)
	{
		case 0:
			this->debug();
			[[fallthrough]];
		case 1:
			this->info();
			[[fallthrough]];
		case 2:
			this->warning();
			[[fallthrough]];
		case 3:
			this->error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}
