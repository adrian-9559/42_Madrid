/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book_msg.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 13:26:16 by adriescr          #+#    #+#             */
/*   Updated: 2026/02/24 18:21:52 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_MSG_HPP
	#define PHONE_BOOK_MSG_HPP

		#define WELCOME_MESSAGE "Welcome to the Phone Book!"
		#define EXIT_MESSAGE "Exiting the Phone Book. Goodbye!"

		#define MENU_MESSAGE "\n\nMENU:\n\x1B[32mADD. Add Contact\x1B[0m\n\x1B[33mSEARCH. Search Contact\x1B[0m\n\x1B[35mEXIT. Exit\x1B[0m\n\n"

		// Prompt Messages
		#define PROMPT_MESSAGE "Choose an option:\n"
		#define CONTACTS_LIST_HEADER "\nList of all contacts:\n"

		// Error Messages
		#define ERROR_MESSAGE "An error occurred. Please try again."
		#define INVALID_PHONE_NUMBER_MESSAGE "Invalid phone number format. Please try again."
		#define INVALID_OPTION_MESSAGE "Invalid option. Please try again."

		// New contact
		#define NEW_CONTACT_MESSAGE "\x1B[33mNew contact\n\x1B[0m"
		#define NAME_CONTACT_MESSAGE "\x1B[34mEnter first name: \x1B[0m"
		#define LAST_NAME_CONTACT_MESSAGE "\x1B[34mEnter last name: \x1B[0m"
		#define NICKNAME_CONTACT_MESSAGE "\x1B[34mEnter nickname: \x1B[0m"
		#define PHONE_NUMBER_CONTACT_MESSAGE "\x1B[34mEnter phone number: \x1B[0m"
		#define DARKEST_SECRET_CONTACT_MESSAGE "\x1B[34mEnter darkest secret: \x1B[0m"

		// Search contact
		#define SEARCH_CONTACT_MESSAGE "Enter search index: "
		#define SEARCH_CONTACT_NOT_FOUND_MESSAGE "Contact not found."
		#define SEARCH_CONTACT_FOUND_MESSAGE "\nContact:\n\n"

		// Delete contact
		#define DELETE_CONTACT_MESSAGE "Enter delete index: "

		// Confirmation Messages
		#define CONTACT_ADDED_MESSAGE "Contact added successfully."
		#define CONTACT_DELETED_MESSAGE "Contact deleted successfully."
		#define CONTACT_NOT_FOUND_MESSAGE "Contact not found."
		#define CONTACTS_LIST_EMPTY_MESSAGE "List is empty\n"

#endif
