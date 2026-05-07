/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 18:26:38 by adriescr          #+#    #+#             */
/*   Updated: 2026/05/07 18:26:39 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		this->target = other.target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream ofs((this->target + "_shrubbery").c_str());
	if (!ofs)
		return;
	ofs << "	   _-_-\n";
	ofs << "	/~~	 ~~\\\n";
	ofs << " /~~  /  \\  \\  ~~\\\n";
	ofs << "{			   }\n";
	ofs << " \\  _-	 -_  /\n";
	ofs << "   ~  \\ //  ~\n";
	ofs << "	  | |\n";
	ofs << "	  | |\n";
	ofs << "	  ~ ~\n";
	ofs.close();
}
