/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:14:53 by abettini          #+#    #+#             */
/*   Updated: 2023/12/20 15:14:24 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

//-------------------------------------------------------------------
//orthodox form

AForm::AForm(void) : _name("defaultAForm"), _signed(false), _minGradeToSign(LOW_GRADE), _minGradeToExecute(LOW_GRADE)
{
	std::cout << "AForm default constructor called" << std::endl;
	return ;
}

AForm::~AForm(void)
{
	std::cout << "AForm destructor called" << std::endl;
	return ;
}

AForm::AForm(const AForm &src) : _name(src._name), _signed(src._signed), _minGradeToSign(src._minGradeToSign), _minGradeToExecute(src._minGradeToExecute)
{
	std::cout << "AForm copy constructor called" << std::endl;
	return ;
}

AForm &AForm::operator=(const AForm &src)
{
	if (this != &src)
	{
		_target = src._target;
		_signed = src._signed;
	}
	return (*this);
}

//-------------------------------------------------------------------
//custom constructor

int	AForm::_handleGrade(const int grade)
{
	int	ret;

	try
	{
		if (grade < HIGH_GRADE) {
			throw (GradeTooHighException());
		}
		else if (grade > LOW_GRADE) {
			throw (GradeTooLowException());
		}
		else {
			ret = grade;
		}
	}
	catch(GradeTooHighException &e)
	{
		ret = HIGH_GRADE;
		std::cerr << e.what() << std::endl;
	}
	catch(GradeTooLowException &e)
	{
		ret = LOW_GRADE;
		std::cerr << e.what() << std::endl;
	}
	return (ret);
}

AForm::AForm(const std::string name, const int minGradeToSign, const int minGradeToExecute) : \
 _name(name), _signed(false), \
 _minGradeToSign(_handleGrade(minGradeToSign)), \
 _minGradeToExecute(_handleGrade(minGradeToExecute))
{
	std::cout << "AForm custom constructor called" << std::endl;
	return ;
}

//-------------------------------------------------------------------
//getters

std::string	AForm::getName(void) const
{
	return (_name);
}

bool	AForm::getSigned(void) const
{
	return (_signed);
}

int	AForm::getMinGradeToSign(void) const
{
	return (_minGradeToSign);
}

int	AForm::getMinGradeToExecute(void) const
{
	return (_minGradeToExecute);
}

std::string	AForm::getTarget(void) const
{
	return (_target);
}

//-------------------------------------------------------------------
//setters

void	AForm::setTarget(const std::string &target)
{
	_target = target;
}

//-------------------------------------------------------------------

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (_signed)
		throw (std::exception());
	if (bureaucrat.getGrade() > _minGradeToSign)
		throw (GradeTooLowException());
	else
		_signed = true;
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (!getSigned())
		throw (std::exception());
	if (executor.getGrade() > getMinGradeToExecute())
		throw (GradeTooLowException());
}

//===================================================================
//Operator

std::ostream &operator<<(std::ostream &os, const AForm &src)
{
	os << "form " << src.getName() \
		<< ", grade required to be signed = " << src.getMinGradeToSign() \
		<< ", grade required to be executed = " << src.getMinGradeToExecute() \
		<< ", signed = " << src.getSigned() << ".";
	return (os);
}

//===================================================================
//Exceptions

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("GradeTooLowException");
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("GradeTooHighException");
}
