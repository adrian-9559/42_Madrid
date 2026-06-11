/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isChar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 17:58:04 by adriescr          #+#    #+#             */
/*   Updated: 2026/06/09 18:10:27 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils.hpp"

int	is_char(const std::string &literal)
{
	return (literal.length() == 1
		&& !std::isdigit(static_cast<unsigned char>(literal[0])));
}
