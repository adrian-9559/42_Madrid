/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:57:27 by adriescr          #+#    #+#             */
/*   Updated: 2026/03/26 17:25:52 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "../Animal/Animal.hpp"
#include "../Brain/Brain.hpp"

class Dog : public Animal
{
	private:
		Brain* brain;
	public:
		Dog(void);
		Dog(const Dog& other);
		virtual ~Dog();

		Dog& operator=(const Dog& other);

		virtual void makeSound() const;
		void setIdea(int index, const std::string& idea);
		std::string getIdea(int index) const;
};

#endif
