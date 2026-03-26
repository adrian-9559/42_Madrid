/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:43:00 by adriescr          #+#    #+#             */
/*   Updated: 2026/03/26 16:19:20 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/class/Animal/AAnimal.hpp"
#include "./src/class/Cat/Cat.hpp"
#include "./src/class/Dog/Dog.hpp"
#include "./src/class/WrongAnimal/WrongAnimal.hpp"
#include "./src/class/WrongCat/WrongCat.hpp"

int main()
{
	const AAnimal* meta = new Dog();
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();


	const AAnimal* a = new AAnimal()

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();

	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongI = new WrongCat();
	std::cout << wrongI->getType() << " " << std::endl;
	wrongI->makeSound();
	wrongMeta->makeSound();

	delete meta;
	delete j;
	delete i;
	delete wrongMeta;
	delete wrongI;

	return 0;
}
