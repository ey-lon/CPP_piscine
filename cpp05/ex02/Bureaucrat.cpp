/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:50:11 by abettini          #+#    #+#             */
/*   Updated: 2023/10/12 09:37:20 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

//-------------------------------------------------------------------
//orthodox form

Bureaucrat::Bureaucrat(void) : _name("defaultBureaucrat"), _grade(LOW_GRADE)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	return ;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this != &src)
	{
		_grade = src._grade;
	}
	return (*this);
}

//-------------------------------------------------------------------
//custom constructor

Bureaucrat::Bureaucrat(const std::string &name, const int grade) : _name(name)
{
	std::cout << "Bureaucrat custom constructor called" << std::endl;
	try
	{
		if (grade < HIGH_GRADE)
			throw (GradeTooHighException());
		else if (grade > LOW_GRADE)
			throw (GradeTooLowException());
		else
			_grade = grade;
	}
	catch(GradeTooHighException &e)
	{
		_grade = HIGH_GRADE;
		std::cerr << e.what() << std::endl;
	}
	catch(GradeTooLowException &e)
	{
		_grade = LOW_GRADE;
		std::cerr << e.what() << std::endl;
	}
	return ;
}

//-------------------------------------------------------------------
//getters

const std::string	&Bureaucrat::getName(void) const
{
	return (_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

//-------------------------------------------------------------------

void	Bureaucrat::incrementGrade(void)
{
	try
	{
		if (_grade == HIGH_GRADE)
			throw (GradeTooHighException());
		else
			_grade--;
	}
	catch (GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	Bureaucrat::decrementGrade(void)
{
	try
	{
		if (_grade == LOW_GRADE)
			throw (GradeTooLowException());
		else
			_grade++;
	}
	catch (GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cerr << _name << " couldn’t sign " << form.getName() << " because their grade isn't high enough." << std::endl;
		return;
	}
	catch (std::exception)
	{
		std::cerr << form.getName() << " is already signed." << std::endl;	
		return ;
	}
	std::cout << _name << " signed " << form.getName() << "." << std::endl;
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
	}
	catch (AForm::GradeTooLowException)
	{
		std::cerr << _name << " couldn’t execute " << form.getName() << " because their grade isn't high enough." << std::endl;
		return;
	}
	catch (std::exception)
	{
		std::cerr << form.getName() << " isn't signed." << std::endl;	
		return ;
	}
	std::cout << _name << " executed " << form.getName() << "." << std::endl;
}

//===================================================================
//Operator

std::ostream &operator<<(std::ostream &os, const Bureaucrat &src)
{
	os << src.getName() << ", bureaucrat grade " << src.getGrade();
	return (os);
}

//===================================================================
//Exceptions

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("GradeTooLowException");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("GradeTooHighException");
}
