/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copilot <copilot@example.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 12:00:00 by copilot           #+#    #+#             */
/*   Updated: 2026/05/05 12:00:00 by copilot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/class/Bureaucrat/Bureaucrat.hpp"
#include "./src/class/AForm/AForm.hpp"
#include "./src/class/ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "./src/class/RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "./src/class/PresidentialPardonForm/PresidentialPardonForm.hpp"
#include "./src/class/Intern/Intern.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));

	Bureaucrat alice("Alice", 1);
	Bureaucrat bob("Bob", 150);

	ShrubberyCreationForm shrub("home");
	RobotomyRequestForm robot("Marvin");
	PresidentialPardonForm pardon("Ford");

	std::cout << "--- Signing tests ---" << std::endl;
	bob.signForm(shrub);
	alice.signForm(shrub);

	std::cout << "\n--- Execution tests ---" << std::endl;
	alice.executeForm(shrub);

	std::cout << "\n--- Robotomy tests ---" << std::endl;
	alice.signForm(robot);
	alice.executeForm(robot);
	alice.executeForm(robot);

	std::cout << "\n--- Presidential tests ---" << std::endl;
	Bureaucrat signer("Signer", 25);
	Bureaucrat executor("Executor", 5);
	signer.signForm(pardon);
	executor.executeForm(pardon);

	std::cout << "\n--- Execute unsigned form (should fail) ---" << std::endl;
	RobotomyRequestForm unsig("Nobody");
	alice.executeForm(unsig);

	std::cout << "\n--- Intern tests ---" << std::endl;
	Intern someIntern;
	AForm *form;

	form = someIntern.makeForm("shrubbery creation", "garden");
	if (form)
	{
		alice.signForm(*form);
		alice.executeForm(*form);
		delete form;
	}

	form = someIntern.makeForm("robotomy request", "Bender");
	if (form)
	{
		alice.signForm(*form);
		alice.executeForm(*form);
		alice.executeForm(*form);
		delete form;
	}

	form = someIntern.makeForm("presidential pardon", "Arthur");
	if (form)
	{
		alice.signForm(*form);
		alice.executeForm(*form);
		delete form;
	}

	form = someIntern.makeForm("not a real form", "Nobody");
	if (form)
		delete form;

	return 0;
}

