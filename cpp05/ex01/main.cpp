/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:50:00 by abettini          #+#    #+#             */
/*   Updated: 2023/10/12 13:58:59 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
	//---------------------------------------------------
	std::cout << std::endl << "--- Constructors: --------------" << std::endl;

	Bureaucrat	a("bob", -1);
	Bureaucrat	b(a);

	Form		f1("F1", 10, 15);
	Form		f2("F2", 0, 160);
	Form		f3(f1);

	//std::cout << b.getName() << std::endl;
	//std::cout << b.getGrade() << std::endl;

	b.incrementGrade();
	b.decrementGrade();
	b.decrementGrade();
	b.decrementGrade();
	b.decrementGrade();
	b.incrementGrade();

	//---------------------------------------------------
	std::cout << std::endl << "--- Tests ----------------------" << std::endl;

	std::cout << "f1: " << f1.getSigned() << std::endl;
	b.signForm(f1);
	std::cout << "f1: " << f1.getSigned() << std::endl;

	std::cout << "f1: " << f1.getSigned() << std::endl;
	b.signForm(f1);
	std::cout << "f1: " << f1.getSigned() << std::endl;

	std::cout << "f2: " << f2.getSigned() << std::endl;
	b.signForm(f2);
	std::cout << "f2: " << f2.getSigned() << std::endl;

	std::cout << "f3: " << f3.getSigned() << std::endl;
	b.signForm(f3);
	std::cout << "f3: " << f3.getSigned() << std::endl;

	//---------------------------------------------------
	std::cout << std::endl << "--- Bureaucrats prints: --------" << std::endl;
	std::cout << b << std::endl;
	std::cout << a << std::endl;

	//---------------------------------------------------
	std::cout << std::endl << "--- Forms prints: --------------" << std::endl;
	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;

	//---------------------------------------------------
	std::cout << std::endl << "--- Destructors: ---------------" << std::endl;

	return (0);
}