/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookClass.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 13:50:04 by adriescr          #+#    #+#             */
/*   Updated: 2026/02/24 18:10:00 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_CLASS_HPP
	#define PHONE_BOOK_CLASS_HPP

		#include "../contact/ContactClass.hpp"

		#include <iostream>
		#include <string>
		#include <vector>
		#include <chrono>

		#define MAX_CONTACTS 8

		class PhoneBook {
			public:
				PhoneBook();
				~PhoneBook();

				bool isValidPhoneNumber(const std::string& number);

				void addContact(const Contact& contact);
				void add();
				int allContacts();
				void searchContact();
				void deleteContact();

			private:
				Contact	contacts[8];
				int	nextIndex;
				int	count;
		};
#endif
