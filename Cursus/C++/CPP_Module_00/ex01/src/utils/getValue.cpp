/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getValue.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:02:44 by adriescr          #+#    #+#             */
/*   Updated: 2026/02/26 18:40:42 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libraries/phone_book.hpp"

int	getValue(std::string prompt, std::string &input)
{
	std::cout << prompt;
	if (!std::getline(std::cin, input))
		return (-1);
	return (!input.empty());
}
