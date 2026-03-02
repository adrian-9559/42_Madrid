/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:27:11 by adriescr          #+#    #+#             */
/*   Updated: 2026/02/26 19:05:02 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/class/zombie/Zombie.hpp"

int main(void)
{
	Zombie* newZombie1 = newZombie("Zombie1");
	newZombie1->announce();
	delete newZombie1;

	Zombie* newZombie2 = newZombie("Zombie2");
	newZombie2->announce();
	delete newZombie2;
	randomChump("Zombie3");
	return (0);
}
