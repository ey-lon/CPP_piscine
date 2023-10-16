/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:50:00 by abettini          #+#    #+#             */
/*   Updated: 2023/10/11 17:30:39 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	//---------------------------------------------------
	std::cout << std::endl << "--- Constructors: --------------" << std::endl;

	Bureaucrat	a("Bob", -1);
	Bureaucrat	b(a);
	Bureaucrat	c("Claudio", 170);

	AForm *f1 = new ShrubberyCreationForm("Mario");
	AForm *f2 = new PresidentialPardonForm("Luigi");
	AForm *f3 = new RobotomyRequestForm("Goomba");

	//---------------------------------------------------
	std::cout << std::endl << "--- Tests: ---------------------" << std::endl;

	b.executeForm(*f1);
	b.signForm(*f1);
	b.executeForm(*f1);

	b.executeForm(*f2);
	b.signForm(*f2);
	b.executeForm(*f2);

	b.signForm(*f3);
	b.executeForm(*f3);
	c.executeForm(*f3);

	//---------------------------------------------------
	std::cout << std::endl << "--- Bureaucrats prints: --------" << std::endl;
	std::cout << b << std::endl;
	std::cout << a << std::endl;

	//---------------------------------------------------
	std::cout << std::endl << "--- Forms prints: --------------" << std::endl;
	std::cout << *f1 << std::endl;
	std::cout << *f2 << std::endl;
	std::cout << *f3 << std::endl;

	//---------------------------------------------------
	std::cout << std::endl << "--- Destructors: ---------------" << std::endl;
	delete (f1);
	delete (f2);
	delete (f3);

	return (0);
}