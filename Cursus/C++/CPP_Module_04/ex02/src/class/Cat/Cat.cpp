/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:56:30 by adriescr          #+#    #+#             */
/*   Updated: 2026/03/26 17:26:54 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : AAnimal(), brain(new Brain())
{
	type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other), brain(new Brain(*other.brain))
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
		if (brain)
			delete brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}


void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

void Cat::setIdea(int index, const std::string& idea)
{
	brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
	return brain->getIdea(index);
}
