/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:51:26 by adriescr          #+#    #+#             */
/*   Updated: 2026/03/02 17:04:37 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/class/harl/Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl = Harl();

	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <level>\n";
		return (1);
	}

	std::string level = argv[1];
	harl.filter(level);

	return (0);
}
