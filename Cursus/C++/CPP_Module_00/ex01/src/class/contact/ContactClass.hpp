/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactClass.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 13:39:14 by adriescr          #+#    #+#             */
/*   Updated: 2026/03/06 16:37:22 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
	#define CONTACT_CLASS_HPP

		#include <iostream>
		#include <sstream>
		#include <iomanip>

		class Contact {
			public:
				Contact();
				Contact(
					const std::string& firstName,
					const std::string& lastName,
					const std::string& nickname,
					const std::string& phoneNumber,
					const std::string& darkestSecret
				);
				~Contact();

				void setFirstName(const std::string& firstName);
				void setLastName(const std::string& lastName);
				void setNickname(const std::string& nickname);
				void setPhoneNumber(const std::string& phoneNumber);
				void setDarkestSecret(const std::string& darkestSecret);

				std::string getFirstName() const;
				std::string getLastName() const;
				std::string getNickname() const;
				std::string getPhoneNumber() const;
				std::string getDarkestSecret() const;
				std::string getFullInfo() const;

			private:
				std::string firstName;
				std::string lastName;
				std::string nickname;
				std::string phoneNumber;
				std::string darkestSecret;
		};

#endif
