/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 13:23:06 by adriescr          #+#    #+#             */
/*   Updated: 2025/12/30 16:40:59 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
	#define PHONE_BOOK_HPP

		#include <iostream>
		#include <string>
		#include <vector>
		#include <cctype>

		// Messages
		#include "../libraries/phone_book_msg.hpp"

		// Class
		#include "../class/phoneBook/PhoneBookClass.hpp"

		int	getValue(std::string prompt, std::string &input);
		bool isEmpty(const std::string& str);
#endif
