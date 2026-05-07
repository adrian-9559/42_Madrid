/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 18:25:21 by adriescr          #+#    #+#             */
/*   Updated: 2026/05/07 18:25:22 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "../AForm/AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &other);
		Intern& operator=(const Intern &other);
		~Intern();

		AForm* makeForm(const std::string &formName, const std::string &target) const;
};

#endif
