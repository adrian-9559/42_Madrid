/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 11:31:57 by adriescr          #+#    #+#             */
/*   Updated: 2026/03/17 13:53:45 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/class/ClapTrap/ClapTrap.hpp"
#include "./src/class/ScavTrap/ScavTrap.hpp"
#include "./src/class/FlagTrap/FlagTrap.hpp"
#include "./src/class/DiamondTrap/DiamondTrap.hpp"

int main()
{
	ClapTrap clap("Clappy");
	ScavTrap scav("Scavvy");
	FlagTrap flag("Flaggy");
	DiamondTrap diamond("Diamondy");

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

	diamond.attack("Target4");
	diamond.takeDamage(20);
	diamond.beRepaired(10);
	diamond.whoAmI();

	DiamondTrap diamond2 = diamond;
	diamond2.whoAmI();

	DiamondTrap diamond3;
	diamond3 = diamond;
	diamond3.whoAmI();

	return 0;
}
