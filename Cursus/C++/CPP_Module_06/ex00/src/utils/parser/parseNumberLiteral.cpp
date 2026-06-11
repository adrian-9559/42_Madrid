/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseNumberLiteral.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 18:15:16 by adriescr          #+#    #+#             */
/*   Updated: 2026/06/09 18:15:34 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.hpp"

bool parseNumberLiteral(const std::string &literal, int type, double &out)
{
	char *end;

	std::string toParse = literal;
	end = NULL;
	if (type == 2)
		toParse = literal.substr(0, literal.length() - 1);
	errno = 0;
	out = std::strtod(toParse.c_str(), &end);
	if (end == toParse.c_str() || *end != '\0')
		return false;
	return true;
}
