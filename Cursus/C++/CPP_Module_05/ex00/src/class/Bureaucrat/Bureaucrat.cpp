/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:47:14 by adriescr          #+#    #+#             */
/*   Updated: 2026/04/21 15:12:57 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/**
 * CONSTRUCTORS
 */
Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Bureaucrat parameterized constructor called" << std::endl;
}

/**
 * COPY CONSTRUCTOR
 */

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

/**
 * ASSIGNMENT OPERATOR
 */

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		this->grade = other.grade;
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	return *this;
}

/**
 * DESTRUCTOR
 */

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

/**
 * GETTERS
 */

const std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

/**
 * OTHER METHODS
 */

void Bureaucrat::incrementGrade()
{
	this->grade--;
}

void Bureaucrat::decrementGrade()
{
	this->grade++;
}

/**
 * EXCEPTIONS
 */

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

/**
 * OVERLOADS
 */

std::ostream& operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return out;
}
