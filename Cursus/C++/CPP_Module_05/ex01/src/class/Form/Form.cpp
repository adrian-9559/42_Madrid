/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:17:36 by adriescr          #+#    #+#             */
/*   Updated: 2026/05/05 11:36:59 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "../Bureaucrat/Bureaucrat.hpp"

/* CONSTRUCTORS */
Form::Form() : name("Default"), isSigned(false), signGrade(150), execGrade(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string name, int signGrade, int execGrade) : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form parameterized constructor called" << std::endl;
}

Form::Form(const Form &other) : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form &other)
{
	if (this != &other)
		this->isSigned = other.isSigned;
	std::cout << "Form copy assignment operator called" << std::endl;
	return *this;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

/* GETTERS */
const std::string Form::getName() const
{
	return this->name;
}

bool Form::getIsSigned() const
{
	return this->isSigned;
}

int Form::getSignGrade() const
{
	return this->signGrade;
}

int Form::getExecGrade() const
{
	return this->execGrade;
}

/* METHODS */
void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->signGrade)
		this->isSigned = true;
	else
		throw Form::GradeTooLowException();
}

/* EXCEPTIONS */
const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

/* OVERLOADS */
std::ostream& operator<<(std::ostream &out, const Form &form)
{
	out << "Form " << form.getName() << ", signed: " << (form.getIsSigned() ? "yes" : "no")
		<< ", grade to sign: " << form.getSignGrade() << ", grade to execute: " << form.getExecGrade();
	return out;
}

