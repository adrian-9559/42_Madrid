/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:12:19 by adriescr          #+#    #+#             */
/*   Updated: 2026/02/26 19:16:16 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../class/zombie/Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* horde = new Zombie[N];
	std::string nameWithIndex;

	for (int i = 0; i < N; i++)
	{
		nameWithIndex = name + std::to_string(i + 1);
		horde[i].setName(nameWithIndex);
	}
	return (horde);
}

