/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:40:52 by abettini          #+#    #+#             */
/*   Updated: 2023/12/20 15:30:37 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

#define DEF_NAME "PresidentialPardonForm"
#define DEF_SIGN 25
#define DEF_EXEC 5

//---------------------------------------------------
//orthodox form

PresidentialPardonForm::PresidentialPardonForm(void) : AForm(DEF_NAME, DEF_SIGN, DEF_EXEC)
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(DEF_NAME, DEF_SIGN, DEF_EXEC)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	if (this != &src) {
		AForm::operator=(src);
	}
	return ;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this != &src) {
		AForm::operator=(src);
	}
	return (*this);
}

//---------------------------------------------------
//custom constructor

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm(DEF_NAME, DEF_SIGN, DEF_EXEC)
{
	std::cout << "PresidentialPardonForm custom constructor called" << std::endl;
	setTarget(target);
	return ;
}

//---------------------------------------------------

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
