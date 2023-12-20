/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:14:53 by abettini          #+#    #+#             */
/*   Updated: 2023/12/20 15:13:28 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

//-------------------------------------------------------------------
//orthodox form

Form::Form(void) : _name("defaultForm"), _signed(false), _minGradeToSign(LOW_GRADE), _minGradeToExecute(LOW_GRADE)
{
	std::cout << "Form default constructor called" << std::endl;
	return ;
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
	return ;
}

Form::Form(const Form &src) : _name(src._name), _signed(src._signed), _minGradeToSign(src._minGradeToSign), _minGradeToExecute(src._minGradeToExecute)
{
	std::cout << "Form copy constructor called" << std::endl;
	return ;
}

Form &Form::operator=(const Form &src)
{
	if (this != &src)
		_signed = src._signed;
	return (*this);
}

//-------------------------------------------------------------------
//custom constructor

int	Form::_handleGrade(const int grade)
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

Form::Form(const std::string name, const int minGradeToSign, const int minGradeToExecute) : \
 _name(name), _signed(false), \
 _minGradeToSign(_handleGrade(minGradeToSign)), \
 _minGradeToExecute(_handleGrade(minGradeToExecute))
{
	std::cout << "Form custom constructor called" << std::endl;
	return ;
}

//-------------------------------------------------------------------
//getters

std::string	Form::getName(void) const
{
	return (_name);
}

bool	Form::getSigned(void) const
{
	return (_signed);
}

int	Form::getMinGradeToSign(void) const
{
	return (_minGradeToSign);
}

int	Form::getMinGradeToExecute(void) const
{
	return (_minGradeToExecute);
}

//-------------------------------------------------------------------

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (_signed)
		throw (std::exception());
	if (bureaucrat.getGrade() > _minGradeToSign)
		throw (GradeTooLowException());
	else
		_signed = true;
}

//===================================================================
//Operator

std::ostream &operator<<(std::ostream &os, const Form &src)
{
	os << "form " << src.getName() \
		<< ", grade required to be signed = " << src.getMinGradeToSign() \
		<< ", grade required to be executed = " << src.getMinGradeToExecute() \
		<< ", signed = " << src.getSigned() << ".";
	return (os);
}

//===================================================================
//Exceptions

const char *Form::GradeTooLowException::what() const throw()
{
	return ("GradeTooLowException");
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("GradeTooHighException");
}
