/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:41:30 by abettini          #+#    #+#             */
/*   Updated: 2023/12/20 15:35:50 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

#define DEF_NAME "RobotomyRequestForm"
#define DEF_SIGN 72
#define DEF_EXEC 45

//---------------------------------------------------
//orthodox form

RobotomyRequestForm::RobotomyRequestForm(void) : AForm(DEF_NAME, DEF_SIGN, DEF_EXEC)
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(DEF_NAME, DEF_SIGN, DEF_EXEC)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	if (this != &src) {
		AForm::operator=(src);
	}
	return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src) {
		AForm::operator=(src);
	}
	return (*this);
}

//---------------------------------------------------
//custom constructor

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm(DEF_NAME, DEF_SIGN, DEF_EXEC)
{
	std::cout << "RobotomyRequestForm custom constructor called" << std::endl;
	setTarget(target);
	return ;
}

//---------------------------------------------------

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);

	std::cout << "* drilling noises *" << std::endl;

	srand((unsigned)time(NULL));
	bool n = rand() % 2;
	
	if (n)
		std::cout << getTarget() << " has been robotomized." << std::endl;
	else
		std::cout << "The robotomy failed." << std::endl;
}
