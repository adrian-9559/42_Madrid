/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 00:00:33 by adriescr          #+#    #+#             */
/*   Updated: 2026/07/22 00:04:41 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/includes/easyfind.hpp"
#include <iostream>
#include <map>

int	main(void)
{
	try
	{
		std::map<int, int> nums;
		nums[1] = 1;
		nums[2] = 2;
		nums[3] = 3;
		nums[4] = 4;
		nums[5] = 5;
		std::map<int, int>::iterator it = easyfind(nums, 3);
		std::cout << "Element found: " << it->second << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}
