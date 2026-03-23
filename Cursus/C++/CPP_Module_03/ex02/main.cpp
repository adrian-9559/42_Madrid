/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 11:31:57 by adriescr          #+#    #+#             */
/*   Updated: 2026/03/17 13:45:55 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/class/ClapTrap/ClapTrap.hpp"
#include "./src/class/ScavTrap/ScavTrap.hpp"
#include "./src/class/FlagTrap/FlagTrap.hpp"

int main()
{
	ClapTrap clap("Clappy");
	ScavTrap scav("Scavvy");
	FlagTrap flag("Flaggy");

	clap.attack("Target1");
	clap.takeDamage(5);
	clap.beRepaired(3);

	scav.attack("Target2");
	scav.takeDamage(10);
	scav.beRepaired(5);
	scav.guardGate();

	flag.attack("Target3");
	flag.takeDamage(15);
	flag.beRepaired(7);
	flag.highFivesGuys();

	FlagTrap flag2 = flag;
	flag2.attack("Target4");

	FlagTrap flag3;
	flag3 = flag;
	flag3.highFivesGuys();

	return 0;
}
