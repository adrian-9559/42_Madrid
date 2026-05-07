/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copilot <copilot@example.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 12:00:00 by copilot           #+#    #+#             */
/*   Updated: 2026/05/05 12:00:00 by copilot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "../Bureaucrat/Bureaucrat.hpp"

/* CONSTRUCTORS */
AForm::AForm() : name("Default"), isSigned(false), signGrade(150), execGrade(150)
{
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string name, int signGrade, int execGrade) : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw AForm::GradeTooHighException();
    else if (signGrade > 150 || execGrade > 150)
        throw AForm::GradeTooLowException();
    std::cout << "AForm parameterized constructor called" << std::endl;
}

AForm::AForm(const AForm &other) : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade)
{
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm &other)
{
    if (this != &other)
        this->isSigned = other.isSigned;
    std::cout << "AForm copy assignment operator called" << std::endl;
    return *this;
}

AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}

/* GETTERS */
const std::string AForm::getName() const
{
    return this->name;
}

bool AForm::getIsSigned() const
{
    return this->isSigned;
}

int AForm::getSignGrade() const
{
    return this->signGrade;
}

int AForm::getExecGrade() const
{
    return this->execGrade;
}

/* METHODS */
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= this->signGrade)
        this->isSigned = true;
    else
        throw AForm::GradeTooLowException();
}

void AForm::execute(const Bureaucrat &executor) const
{
    if (!this->isSigned)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->execGrade)
        throw AForm::GradeTooLowException();
    this->executeAction();
}

/* EXCEPTIONS */
const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form not signed";
}

/* OVERLOADS */
std::ostream& operator<<(std::ostream &out, const AForm &form)
{
    out << "Form " << form.getName() << ", signed: " << (form.getIsSigned() ? "yes" : "no")
        << ", grade to sign: " << form.getSignGrade() << ", grade to execute: " << form.getExecGrade();
    return out;
}
