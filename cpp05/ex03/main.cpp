/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:50:00 by abettini          #+#    #+#             */
/*   Updated: 2023/12/20 15:44:11 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{
	//---------------------------------------------------
	std::cout << std::endl << "--- Constructors: --------------" << std::endl;

	Bureaucrat	a("Bob", -1);
	Bureaucrat	b(a);
	Bureaucrat	c("Claudio", 170);

	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	//---------------------------------------------------
	std::cout << std::endl << "--- Tests: ---------------------" << std::endl;
	
	b.executeForm(*rrf);
	b.signForm(*rrf);
	b.executeForm(*rrf);
	c.executeForm(*rrf);

	//---------------------------------------------------
	std::cout << std::endl << "--- Bureaucrats prints: --------" << std::endl;
	std::cout << b << std::endl;
	std::cout << a << std::endl;

	//---------------------------------------------------
	std::cout << std::endl << "--- Forms prints: --------------" << std::endl;
	std::cout << *rrf << std::endl;

	//---------------------------------------------------
	std::cout << std::endl << "--- Destructors: ---------------" << std::endl;
	delete (rrf);

	return (0);
}