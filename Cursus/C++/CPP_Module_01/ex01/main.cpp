/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:27:11 by adriescr          #+#    #+#             */
/*   Updated: 2026/02/26 19:17:23 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/class/zombie/Zombie.hpp"

int main(void)
{
	Zombie* horde = zombieHorde(5, "Zombie");

	for (int i = 0; i < 5; i++)
		horde[i].announce();

	delete[] (horde);

	return (0);
}
