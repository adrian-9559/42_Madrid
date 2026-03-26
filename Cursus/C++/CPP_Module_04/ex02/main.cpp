/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:43:00 by adriescr          #+#    #+#             */
/*   Updated: 2026/03/26 17:27:20 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/class/Animal/AAnimal.hpp"
#include "./src/class/Cat/Cat.hpp"
#include "./src/class/Dog/Dog.hpp"
#include "./src/class/WrongAnimal/WrongAnimal.hpp"
#include "./src/class/WrongCat/WrongCat.hpp"

int main()
{
	std::cout << "===== Brain copy tests =====" << std::endl;
	{
		Cat originalCat;
		for (int idx = 0; idx < 10; idx++)
		{
			originalCat.setIdea(idx, "Cat idea #" + std::string(1, static_cast<char>('0' + idx)));
		}
		std::cout << "Cat first 10 ideas:" << std::endl;
		for (int idx = 0; idx < 10; idx++)
		{
			std::cout << "- " << originalCat.getIdea(idx) << std::endl;
		}

		Cat copiedCat(originalCat);
		Cat assignedCat;
		assignedCat = originalCat;

		Dog originalDog;
		for (int idx = 0; idx < 10; idx++)
		{
			originalDog.setIdea(idx, "Dog idea #" + std::string(1, static_cast<char>('0' + idx)));
		}
		std::cout << "Dog first 10 ideas:" << std::endl;
		for (int idx = 0; idx < 10; idx++)
		{
			std::cout << "- " << originalDog.getIdea(idx) << std::endl;
		}

		Dog copiedDog(originalDog);
		Dog assignedDog;
		assignedDog = originalDog;
	}
	std::cout << "===== Polymorphism tests =====" << std::endl;

	const AAnimal* meta = new Dog();
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

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
