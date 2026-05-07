/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 18:25:34 by adriescr          #+#    #+#             */
/*   Updated: 2026/05/07 18:25:36 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "../ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "../RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "../PresidentialPardonForm/PresidentialPardonForm.hpp"
#include <iostream>

/* Helpers: factory functions */
static AForm* createShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

/* CONSTRUCTORS / DESTRUCTOR */
Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
	(void)other;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern &other)
{
	(void)other;
	std::cout << "Intern copy assignment operator called" << std::endl;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

/* makeForm: maps a human-readable name to a factory function */
AForm* Intern::makeForm(const std::string &formName, const std::string &target) const
{
	const std::string names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (*creators[])(const std::string &) = {&createShrubbery, &createRobotomy, &createPresidential};

	for (size_t i = 0; i < (sizeof(names) / sizeof(names[0])); ++i)
	{
		if (formName == names[i])
		{
			AForm *form = creators[i](target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return form;
		}
	}
	std::cout << "Intern: unknown form '" << formName << "'" << std::endl;
	return NULL;
}
