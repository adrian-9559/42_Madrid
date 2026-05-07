/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 12:07:55 by adriescr          #+#    #+#             */
/*   Updated: 2026/05/05 12:12:33 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <exception>
# include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool isSigned;
		const int signGrade;
		const int execGrade;
	public:
		AForm();
		AForm(const std::string name, int signGrade, int execGrade);
		AForm(const AForm &other);
		AForm& operator=(const AForm &other);
		virtual ~AForm();

		const std::string getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void beSigned(const Bureaucrat &bureaucrat);

		/* Checks and then calls the concrete action */
		void execute(const Bureaucrat &executor) const;
		virtual void executeAction() const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream &out, const AForm &form);

#endif
