/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 00:52:09 by adriescr          #+#    #+#             */
/*   Updated: 2026/07/22 00:52:09 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/class/BitcoinExchange/BitcoinExchange.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

static std::string trim(const std::string &s)
{
	size_t	start;
	size_t	end;

	start = s.find_first_not_of(" \t\r\n");
	if (start == std::string::npos)
		return (std::string());
	end = s.find_last_not_of(" \t\r\n");
	return (s.substr(start, end - start + 1));
}

static bool isValidDate(const std::string &date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (date[i] < '0' || date[i] > '9')
			return (false);
	}
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	if (month < 1 || month > 12 || day < 1)
		return (false);
	int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		days_in_month[1] = 29;
	return (day <= days_in_month[month - 1]);
}

int	main(int argc, char **argv)
{
	BitcoinExchange	btc("data.csv");
	double value;

	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	std::ifstream input(argv[1]);
	std::string line;
	if (!input.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	std::getline(input, line);
	while (std::getline(input, line))
	{
		size_t sep = line.find('|');
		if (sep == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		std::string date = trim(line.substr(0, sep));
		std::string value_str = trim(line.substr(sep + 1));
		for (size_t i = 0; i < value_str.length(); i++)
			if (value_str[i] == ',')
				value_str[i] = '.';
		if (date.empty() || value_str.empty())
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		if (!isValidDate(date))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		std::stringstream ss(value_str);
		if (!(ss >> value))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		if (value < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue ;
		}
		if (value > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue ;
		}
		btc.getPriceByDate(date, value);
	}
	return (0);
}
