/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 18:36:33 by adriescr          #+#    #+#             */
/*   Updated: 2026/06/09 18:36:58 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/class/Iter/iter.hpp"
#include <iostream>

void printInt(int &x)
{
	std::cout << x << std::endl;
}
void printFloat(float &x)
{
	std::cout << x << std::endl;
}

void printChar(char &x)
{
	std::cout << x << std::endl;
}

int main()
{
	int arr[5] = {1, 2, 3, 4, 5};
	float arr2[5] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
	char arr3[5] = {'a', 'b', 'c', 'd', 'e'};
	iter(arr, 5, printInt);
	iter(arr2, 5, printFloat);
	iter(arr3, 5, printChar);

	std::cout << std::endl;
}
