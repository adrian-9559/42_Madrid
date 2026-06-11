/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 18:01:17 by adriescr          #+#    #+#             */
/*   Updated: 2026/06/09 18:16:26 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <sstream>
#include <cerrno>
#include <cstdlib>
#include <cctype>

// Type checking functions
int	is_char(const std::string &literal);
int	is_int(const std::string &literal);
int	is_double(const std::string &literal);
int	is_float(const std::string &literal);
int	getType(const std::string &literal);

// Print functions
void printFloat(double d, bool parseOverflow);
void printDouble(double d, bool parseOverflow);
void printResult(double d, bool parseOverflow);

// Parsing functions
bool parseNumberLiteral(const std::string &literal, int type, double &out);

// Helpers
bool hasDecimalOrExp(double num);
bool isNan(double d);
bool isPosInf(double d);
bool isNegInf(double d);
bool isInf(double d);

#endif
