/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 11:31:57 by adriescr          #+#    #+#             */
/*   Updated: 2026/03/17 13:31:07 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/class/ClapTrap/ClapTrap.hpp"
#include "./src/class/ScavTrap/ScavTrap.hpp"

int main()
{
	ClapTrap clap("Clappy");
	ScavTrap scav("Scavvy");

	clap.attack("Target 1");
	clap.takeDamage(5);
	clap.beRepaired(3);

	scav.attack("Target 2");
	scav.takeDamage(10);
	scav.beRepaired(5);
	scav.guardGate();

	ScavTrap scav2 = scav;
	scav2.attack("Target 3");

	ScavTrap scav3;
	scav3 = scav;
	scav3.guardGate();

	return 0;
}
