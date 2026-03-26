/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:56:10 by adriescr          #+#    #+#             */
/*   Updated: 2026/03/26 17:26:26 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "../Animal/AAnimal.hpp"
#include "../Brain/Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain* brain;
	public:
		Cat(void);
		Cat(const Cat& other);
		virtual ~Cat();

		Cat& operator=(const Cat& other);

		virtual void makeSound() const;
		void setIdea(int index, const std::string& idea);
		std::string getIdea(int index) const;
};

#endif
