/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:50:00 by abettini          #+#    #+#             */
/*   Updated: 2023/10/12 13:34:40 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	//---------------------------------------------------
	std::cout << std::endl << "--- Constructors: --------------" << std::endl;

	Bureaucrat a("bob", -1);
	Bureaucrat b(a);

	//---------------------------------------------------
	std::cout << std::endl << "--- Tests: ---------------------" << std::endl;

	std::cout << b.getName() << std::endl;
	std::cout << b.getGrade() << std::endl;

	b.incrementGrade();
	b.decrementGrade();
	b.decrementGrade();
	b.decrementGrade();
	b.decrementGrade();
	b.incrementGrade();

	//---------------------------------------------------
	std::cout << std::endl << "--- Bureaucrats prints: --------" << std::endl;

	std::cout << b << std::endl;
	std::cout << a << std::endl;

	//---------------------------------------------------
	std::cout << std::endl << "--- Destructors: ---------------" << std::endl;

	return (0);
}
