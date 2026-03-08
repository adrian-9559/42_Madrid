/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 13:00:40 by adriescr          #+#    #+#             */
/*   Updated: 2026/03/06 16:29:10 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

int main(int argc, char	**argv)
{
	char c;

	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (1);
	}
	for(int i = 1; i < argc; i++)
	{
		for(int j = 0; argv[i][j]; j++)
		{
			c =  std::toupper(argv[i][j]);
			std::cout << c;
		}
	}
	std::cout << "\n";
	return(0);
}
