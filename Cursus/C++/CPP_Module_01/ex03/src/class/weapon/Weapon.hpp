/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:27:42 by adriescr          #+#    #+#             */
/*   Updated: 2026/02/26 19:29:25 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
	public:
		Weapon(void);
		Weapon(std::string type);
		~Weapon(void);

		const std::string& getType(void) const;
		void setType(std::string type);

	private:
		std::string _type;
};

#endif
