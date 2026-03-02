/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:59:49 by adriescr          #+#    #+#             */
/*   Updated: 2026/02/26 19:06:29 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../class/zombie/Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie* newZombie = new Zombie(name);
	return (newZombie);
}
