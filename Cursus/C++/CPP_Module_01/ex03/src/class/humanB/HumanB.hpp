/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:30:49 by adriescr          #+#    #+#             */
/*   Updated: 2026/03/02 16:32:47 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "iostream"

// Include weapon header
# include "../weapon/Weapon.hpp"

class HumanB
{
	public:
		HumanB(void);
		HumanB(std::string name);
		~HumanB(void);

		void setWeapon(Weapon& weapon);
		void attack(void) const;

	private:
		std::string name;
		Weapon* _weapon;
};

#endif
