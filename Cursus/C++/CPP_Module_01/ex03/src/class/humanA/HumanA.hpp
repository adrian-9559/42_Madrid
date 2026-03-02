/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:27:12 by adriescr          #+#    #+#             */
/*   Updated: 2026/02/26 19:38:59 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "iostream"

// Include weapon header
# include "../weapon/Weapon.hpp"

class HumanA
{
	public:
		HumanA(void);
		HumanA(std::string name, Weapon& weapon);
		~HumanA(void);

		void attack(void) const;

	private:
		std::string name;
		Weapon& _weapon;
};

#endif
