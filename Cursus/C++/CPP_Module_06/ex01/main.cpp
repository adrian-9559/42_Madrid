/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 18:20:52 by adriescr          #+#    #+#             */
/*   Updated: 2026/06/09 18:25:01 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/class/Serializer/Serializer.hpp"
#include <iostream>

int main()
{
	Data data;
	data.value = 42;
	data.name  = "hello";

	std::cout << "Original pointer : " << &data << std::endl;

	uintptr_t n = Serializer::serialize(&data);
	std::cout << "Serialized value : " << n << std::endl;

	Data* recovered = Serializer::deserialize(n);
	std::cout << "Recovered pointer: " << recovered << std::endl;

	if (recovered == &data)
		std::cout << "OK: pointers match\n";
	else
		std::cout << "KO: pointers do not match\n";
}
