/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 13:00:40 by adriescr          #+#    #+#             */
/*   Updated: 2026/02/24 18:11:39 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/libraries/phone_book.hpp"

int main(void)
{
	PhoneBook	phoneBook;
	std::string	input;

	std::cout << WELCOME_MESSAGE << std::endl;
	while (true)
	{
		std::cout << MENU_MESSAGE << std::endl;
		std::cout << PROMPT_MESSAGE;
		if (!std::getline(std::cin, input))
		{
			std::cout << "\n";
			break ;
		}
		if (input == "ADD")
			phoneBook.add();
		else if (input == "SEARCH")
			phoneBook.searchContact();
		else if (input == "EXIT")
		{
			std::cout << EXIT_MESSAGE << std::endl;
			break ;
		}
		else
			std::cout << "Unknown command. Please try again.\n";
	}
	return(0);
}
