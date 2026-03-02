/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:53:22 by adriescr          #+#    #+#             */
/*   Updated: 2026/03/02 16:53:37 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include "iostream"

class Harl
{
	public:
		Harl(void);
		~Harl(void);

		void complain(std::string level);

	private:
		void debug(void) const;
		void info(void) const;
		void warning(void) const;
		void error(void) const;
};

#endif
