/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:27:54 by adriescr          #+#    #+#             */
/*   Updated: 2026/02/26 19:02:58 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	private:
		std::string name;
	public:
		// Constructors
		Zombie(void);
		Zombie(std::string name);

		// Destructor
		~Zombie(void);

		void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
