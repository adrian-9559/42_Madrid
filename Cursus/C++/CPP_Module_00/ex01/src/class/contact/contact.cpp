/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 13:44:35 by adriescr          #+#    #+#             */
/*   Updated: 2026/01/26 17:38:40 by adriescr         ###   ########.fr       */
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
	setDateOfCreation(std::chrono::system_clock::now());
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

void Contact::setDateOfCreation(const std::chrono::system_clock::time_point& date) {
	this->dateOfCreation = date;
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

std::chrono::system_clock::time_point Contact::getDateOfCreation() const {
	return (this->dateOfCreation);
}

std::string Contact::getDateOfCreationAsString() const {
	std::time_t t = std::chrono::system_clock::to_time_t(this->dateOfCreation);
	std::tm* tm_ptr = std::localtime(&t);
	std::ostringstream oss;
	if (tm_ptr)
		oss << std::put_time(tm_ptr, "%F %T");
	else
		oss << std::asctime(std::localtime(&t));
	return (oss.str());
}

std::string Contact::getFullInfo() const {
	return ("First Name: " + getFirstName() + "\n" +
			"Last Name: " + getLastName() + "\n" +
			"Nickname: " + getNickname() + "\n" +
			"Phone Number: " + getPhoneNumber() + "\n" +
			"Darkest Secret: " + getDarkestSecret() + "\n" +
			"Date of Creation: " + getDateOfCreationAsString());
}
