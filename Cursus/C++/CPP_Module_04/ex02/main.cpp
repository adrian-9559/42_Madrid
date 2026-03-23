/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:43:00 by adriescr          #+#    #+#             */
/*   Updated: 2026/03/23 16:18:30 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/class/Animal/Animal.hpp"
#include "./src/class/Cat/Cat.hpp"
#include "./src/class/Dog/Dog.hpp"

int main()
{
	const Animal* meta = new Dog();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();



	delete meta;
	delete j;
	delete i;

	return 0;
}
