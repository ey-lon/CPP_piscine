/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:49:57 by abettini          #+#    #+#             */
/*   Updated: 2024/01/22 09:37:29 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

//-------------------------------------------------------------------
//orthodox form

Intern::Intern(void)
{
	std::cout << "Intern default constructor called" << std::endl;
	return ;
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called" << std::endl;
	return ;
}

Intern::Intern(const Intern &src)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = src;
	return ;
}

Intern &Intern::operator=(const Intern &src)
{
	if (this != &src)
		;
	return (*this);
}

//-------------------------------------------------------------------

AForm *Intern::makeForm(const std::string &name, const std::string &target) const
{
	std::string const names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm		*form;

	int j = -1;
	for (int i = 0; i < 3 && j == -1; i++) {
		j = name == names[i] ? i : j;
	}
	switch (j)
	{
		case 0:
			form = new ShrubberyCreationForm(target);
			break;

		case 1:		
			form = new RobotomyRequestForm(target);
			break;

		case 2:
			form = new PresidentialPardonForm(target);
			break;

		default:
			std::cerr << "Error: Unknown form: " << name << std::endl;
			return (NULL);
			break;
	}
	std::cout << "Intern creates " << names[j] << std::endl;
	return (form);
}