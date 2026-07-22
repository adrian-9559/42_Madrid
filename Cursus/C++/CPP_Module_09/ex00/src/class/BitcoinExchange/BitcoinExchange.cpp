/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 00:27:57 by adriescr          #+#    #+#             */
/*   Updated: 2026/07/22 00:52:15 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

BitcoinExchange::BitcoinExchange(const std::string &db)
{
	std::ifstream	file(db.c_str());
	std::string		line;

	if (!file.is_open())
	{
		std::cerr << "Error: could not open " << db << std::endl;
		return ;
	}
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t	sep = line.find(',');
		if (sep == std::string::npos)
			continue ;
		std::string	date = line.substr(0, sep);
		std::string	value_str = line.substr(sep + 1);
		std::stringstream	ss(value_str);
		double	price;
		if (!(ss >> price))
			continue ;
		_prices[date] = price;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_prices = other._prices;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::getPriceByDate(std::string date, double value)
{
	std::map<std::string, double>::iterator	it = _prices.lower_bound(date);

	if (it == _prices.end() || it->first != date)
	{
		if (it == _prices.begin())
		{
			std::cout << "Error: no data available for date " << date << std::endl;
			return ;
		}
		--it;
	}
	std::cout << date << " => " << value << " = " << value * it->second << std::endl;
}
