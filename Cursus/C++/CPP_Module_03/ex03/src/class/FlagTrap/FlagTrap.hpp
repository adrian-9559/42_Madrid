/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 13:35:29 by adriescr          #+#    #+#             */
/*   Updated: 2026/03/17 13:51:12 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGTRAP_HPP
# define FLAGTRAP_HPP

# include "../ClapTrap/ClapTrap.hpp"

class FlagTrap : virtual public ClapTrap
{
	public:
		FlagTrap(void);
		FlagTrap(std::string name);
		FlagTrap(const FlagTrap &other);
		~FlagTrap(void);

		FlagTrap &operator=(const FlagTrap &other);

		void attack(const std::string &target);
		void highFivesGuys(void);
};

#endif
