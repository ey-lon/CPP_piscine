/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:41:33 by abettini          #+#    #+#             */
/*   Updated: 2023/11/17 11:00:51 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

#define DEF_NAME "ShrubberyCreationForm"
#define DEF_SIGN 145
#define DEF_EXEC 137

//---------------------------------------------------
//orthodox form

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm(DEF_NAME, DEF_SIGN, DEF_EXEC)
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(DEF_NAME, DEF_SIGN, DEF_EXEC)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	if (this != &src)
		AForm::operator=(src);
	return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src)
		AForm::operator=(src);
	return (*this);
}

//---------------------------------------------------
//custom constructor

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm(DEF_NAME, DEF_SIGN, DEF_EXEC)
{
	std::cout << "ShrubberyCreationForm custom constructor called" << std::endl;
	setTarget(target);
	return ;
}

//---------------------------------------------------

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);

	//fileOut ----------
	std::string fileOutStr = getTarget() + "_shrubbery";
	std::ofstream fileOut(fileOutStr.c_str());
	if (!fileOut)
	{
		std::cerr << "Error: Couldn't open file" << std::endl;
		return ;
	}

	//Execution --------
	fileOut << TREES;
	fileOut.close();
}
