/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:50:15 by abettini          #+#    #+#             */
/*   Updated: 2023/10/11 10:34:09 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

# define LOW_GRADE 150
# define HIGH_GRADE 1

class AForm;
//#include "Form.hpp"

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:

		//---------------------------------------------------
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		//---------------------------------------------------
		Bureaucrat(void);
		~Bureaucrat(void);
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat &operator=(const Bureaucrat &src);

		Bureaucrat(const std::string &name, const int grade);

		const std::string	&getName(void) const;
		int					getGrade(void) const;

		void				incrementGrade(void);
		void				decrementGrade(void);

		void				signForm(AForm &form);
		void				executeForm(AForm const & form);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &src);

#endif