/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:00:41 by adriescr          #+#    #+#             */
/*   Updated: 2026/02/26 19:12:03 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../class/zombie/Zombie.hpp"

void randomChump(std::string name)
{
	Zombie newZombie(name);
	newZombie.announce();
}
