/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 13:44:35 by adriescr          #+#    #+#             */
/*   Updated: 2026/03/06 16:36:07 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ContactClass.hpp"

Contact::Contact() {}

Contact::Contact(
	const std::string& firstName,
	const std::string& lastName,
	const std::string& nickname,
	const std::string& phoneNumber,
	const std::string& darkestSecret
) {
	setFirstName(firstName);
	setLastName(lastName);
	setNickname(nickname);
	setPhoneNumber(phoneNumber);
	setDarkestSecret(darkestSecret);
}

Contact::~Contact() {}

void Contact::setFirstName(const std::string& firstName) {
	this->firstName = firstName;
}

void Contact::setLastName(const std::string& lastName) {
	this->lastName = lastName;
}

void Contact::setNickname(const std::string& nickname) {
	this->nickname = nickname;
}

void Contact::setPhoneNumber(const std::string& phoneNumber) {
	this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string& darkestSecret) {
	this->darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const {
	return (this->firstName);
}

std::string Contact::getLastName() const {
	return (this->lastName);
}

std::string Contact::getNickname() const {
	return (this->nickname);
}

std::string Contact::getPhoneNumber() const {
	return (this->phoneNumber);
}

std::string Contact::getDarkestSecret() const {
	return (this->darkestSecret);
}

std::string Contact::getFullInfo() const {
	return ("First Name: " + getFirstName() + "\n" +
			"Last Name: " + getLastName() + "\n" +
			"Nickname: " + getNickname() + "\n" +
			"Phone Number: " + getPhoneNumber() + "\n" +
			"Darkest Secret: " + getDarkestSecret() + "\n");
}
