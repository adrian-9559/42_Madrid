/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isEmpty.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 20:13:05 by adriescr          #+#    #+#             */
/*   Updated: 2025/12/29 20:16:27 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libraries/phone_book.hpp"

static std::string delete_whitespaces(const std::string& str) {
	std::string result;
	char	c;

	result.reserve(str.size());
	for (std::size_t i = 0; i < str.size(); ++i) {
		c = str[i];
		if (!std::isspace(static_cast<unsigned char>(c))) {
			result += c;
		}
	}
	return (result);
}

bool isEmpty(const std::string& str) {
	std::string trimmed = delete_whitespaces(str);
	return (trimmed.empty());
}
