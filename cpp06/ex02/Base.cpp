/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:24:55 by abettini          #+#    #+#             */
/*   Updated: 2023/12/28 11:29:32 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <stdexcept>
#include <iostream>
#include <cstdlib>

Base * generate(void)
{
	srand((unsigned)time(NULL));
	char n = rand() % 3;

	switch (n)
	{
		case 0:
			return (new A);
			break ;
		case 1:
			return (new B);
			break ;
		default:
			return (new C);
			break ;
	}
}

void identify(Base* p)
{
	if (dynamic_cast <A*> (p)) {
		std::cout << "A*" << std::endl;
	}
	else if (dynamic_cast <B*> (p)) {
		std::cout << "B*" << std::endl;
	}
	else if (dynamic_cast <C*> (p)) {
		std::cout << "C*" << std::endl;
	}
	else {
		std::cout << "Base*" << std::endl;
	}
}

void identify(Base& p)
{
	try 
	{
		Base &ref = dynamic_cast <A&> (p);
		std::cout << "A&" << std::endl;
		(void)ref;
		return ;
	}
	catch (std::exception &e) {};
	try
	{
		Base &ref = dynamic_cast <B&> (p);
		std::cout << "B&" << std::endl;
		(void)ref;
		return ;
	}
	catch (std::exception &e) {};
	try
	{
		Base &ref = dynamic_cast <C&> (p);
		std::cout << "C&" << std::endl;
		(void)ref;
		return ;
	}
	catch (std::exception &e) {};
	std::cout << "Base&" << std::endl;
}