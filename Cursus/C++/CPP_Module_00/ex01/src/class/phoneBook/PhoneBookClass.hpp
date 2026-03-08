/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookClass.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 13:50:04 by adriescr          #+#    #+#             */
/*   Updated: 2026/03/06 16:47:42 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_CLASS_HPP
	#define PHONE_BOOK_CLASS_HPP

		#include "../contact/ContactClass.hpp"

		#include <iostream>
		#include <string>
		#include <limits>
		#include <vector>

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
