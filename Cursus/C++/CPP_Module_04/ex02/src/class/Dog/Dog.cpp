/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:58:19 by adriescr          #+#    #+#             */
/*   Updated: 2026/03/26 17:26:42 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : AAnimal(), brain(new Brain())
{
	type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other), brain(new Brain(*other.brain))
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
		if (brain)
			delete brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}

void Dog::setIdea(int index, const std::string& idea)
{
	brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
	return brain->getIdea(index);
}
