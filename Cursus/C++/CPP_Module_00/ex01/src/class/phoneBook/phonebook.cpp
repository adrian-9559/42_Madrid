/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:59:43 by adriescr          #+#    #+#             */
/*   Updated: 2026/03/06 16:53:43 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBookClass.hpp"
#include "../../libraries/phone_book.hpp"

PhoneBook::PhoneBook() : nextIndex(0), count(0) {}

PhoneBook::~PhoneBook() {}

/**
 * ENGLISH: Validates a phone number based on the following criteria:
 * - The number must contain at least one digit.
 * - The number can only contain digits, spaces, dashes, parentheses, and plus signs.
 *
 * SPANISH: Valida un número de teléfono basado en los siguientes criterios:
 * - El número debe contener al menos un dígito.
 * - El número solo puede contener dígitos, espacios, guiones, paréntesis y signos de más.
 *
 * @param number The phone number to validate. / El número de teléfono a validar.
 * @return true if the phone number is valid, false otherwise. / true si el número de teléfono es válido, false en caso contrario.
 */
bool PhoneBook::isValidPhoneNumber(const std::string& number)
{
	bool hasDigit;

	hasDigit = false;
	if (number.empty())
		return (hasDigit);
	for (std::size_t i = 0; i < number.size(); ++i)
	{
		unsigned char ch = static_cast<unsigned char>(number[i]);
		if (std::isdigit(ch))
		{
			hasDigit = true;
			continue;
		}
		if (ch == ' ' || ch == '-' || ch == '+' || ch == '(' || ch == ')')
			continue;
		return (false);
	}
	return (hasDigit);
}

/**
 * ENGLISH: Adds a contact to the phone book. If the phone book is full, it overwrites the oldest contact.
 * - Maximum contacts: 8.
 * SPNISH: Agrega un contacto a la agenda telefónica. Si la agenda está llena, sobrescribe el contacto más antiguo.
 * - Maximo de contactos: 8.
 *
 * @param contact The contact to add. / El contacto a agregar.
 */
void PhoneBook::addContact(const Contact& contact)
{
	Contact c = contact;

	contacts[nextIndex] = c;
	nextIndex = (nextIndex + 1) % MAX_CONTACTS;
	if (count < MAX_CONTACTS)
		++count;

	std::cout << CONTACT_ADDED_MESSAGE << std::endl;
}

void PhoneBook::add()
{
	Contact newContact;
	std::string	tmp;
	int			status;

	do {
		status = getValue(NAME_CONTACT_MESSAGE, tmp);
		if (status < 0)
		{
			std::cout << std::endl;
			return;
		}
	} while (status == 0);
	newContact.setFirstName(tmp);
	tmp.clear();

	do {
		status = getValue(LAST_NAME_CONTACT_MESSAGE, tmp);
		if (status < 0)
		{
			std::cout << std::endl;
			return;
		}
	} while (status == 0);
	newContact.setLastName(tmp);
	tmp.clear();

	do {
		status = getValue(NICKNAME_CONTACT_MESSAGE, tmp);
		if (status < 0)
		{
			std::cout << std::endl;
			return;
		}
	} while (status == 0);
	newContact.setNickname(tmp);
	tmp.clear();

	do {
		status = getValue(PHONE_NUMBER_CONTACT_MESSAGE, tmp);
		if (status < 0)
		{
			std::cout << std::endl;
			return;
		}
		if (status == 0)
			continue;
		if (isEmpty(tmp))
			continue;
		if (!isValidPhoneNumber(tmp))
		{
			std::cerr << INVALID_PHONE_NUMBER_MESSAGE << std::endl;
			tmp.clear();
			continue;
		}
		break;
	} while (true);
	newContact.setPhoneNumber(tmp);
	tmp.clear();

	do {
		status = getValue(DARKEST_SECRET_CONTACT_MESSAGE, tmp);
		if (status < 0)
		{
			std::cout << std::endl;
			return;
		}
	} while (status == 0);
	newContact.setDarkestSecret(tmp);
	tmp.clear();
	addContact(newContact);
}

static std::string truncateField(const std::string& field)
{
	if (field.length() > 10)
		return (field.substr(0, 9) + ".");
	return (std::string(10 - field.length(), ' ') + field);
}

int PhoneBook::allContacts()
{
	bool any;

	std::cout << CONTACTS_LIST_HEADER;
	std::cout << "|··········|··········|··········|··········|" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "|··········|··········|··········|··········|" << std::endl;
	any = false;
	for (int i = 0; i < 8; ++i)
	{
		if (contacts[i].getFirstName().empty())
			continue;
		std::cout << "|" << std::setw(10) << std::right << (i + 1) << "|";
		std::cout << truncateField(contacts[i].getFirstName()) << "|";
		std::cout << truncateField(contacts[i].getLastName()) << "|";
		std::cout << truncateField(contacts[i].getNickname()) << "|";
		std::cout << "\n|··········|··········|··········|··········|" << std::endl;
		any = true;
	}
	if (!any)
	{
		std::cout << CONTACTS_LIST_EMPTY_MESSAGE << std::endl;
		return (0);
	}
	return (1);
}

void PhoneBook::searchContact()
{
	int	index;

	if (const_cast<PhoneBook*>(this)->allContacts() == 0)
		return;
	std::cout << SEARCH_CONTACT_MESSAGE;
	std::cin >> index;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	index -= 1;
	if (index < 0 || index >= MAX_CONTACTS || contacts[index].getFirstName().empty())
	{
		std::cerr << INVALID_OPTION_MESSAGE << std::endl;
		return;
	}
	std::cout << SEARCH_CONTACT_FOUND_MESSAGE;
	std::cout << contacts[index].getFullInfo() << std::endl;
}

void PhoneBook::deleteContact()
{
	int	index;

	if (const_cast<PhoneBook*>(this)->allContacts() == 0)
		return;
	std::cout << DELETE_CONTACT_MESSAGE;
	std::cin >> index;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	index -= 1;
	if (index < 0 || index >= MAX_CONTACTS || contacts[index].getFirstName().empty())
	{
		std::cerr << INVALID_OPTION_MESSAGE << std::endl;
		return;
	}
	contacts[index] = Contact();
	std::cout << CONTACT_DELETED_MESSAGE << std::endl;
}
