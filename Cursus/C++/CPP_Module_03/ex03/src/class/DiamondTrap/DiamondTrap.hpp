/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 13:47:44 by adriescr          #+#    #+#             */
/*   Updated: 2026/03/17 13:50:40 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "../ClapTrap/ClapTrap.hpp"
# include "../ScavTrap/ScavTrap.hpp"
# include "../FlagTrap/FlagTrap.hpp"

class DiamondTrap : virtual public ScavTrap, virtual public FlagTrap
{
	private:
		std::string _name;
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &other);
		~DiamondTrap(void);

		DiamondTrap &operator=(const DiamondTrap &other);

		void attack(const std::string &target);
		void whoAmI(void);
};

#endif
