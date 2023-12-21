/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:14:58 by abettini          #+#    #+#             */
/*   Updated: 2023/12/21 10:54:22 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_minGradeToSign;
		const int			_minGradeToExecute;

		int	_handleGrade(const int grade) const;

	public:
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		Form(void);
		~Form(void);
		Form(const Form &src);
		Form &operator=(const Form &src);

		Form(const std::string name, const int minGradeToSign, const int minGradeToExecute);

		void	beSigned(Bureaucrat &bureaucrat);

		std::string	getName(void) const;
		bool		getSigned(void) const;
		int			getMinGradeToSign(void) const;
		int			getMinGradeToExecute(void) const;
};

std::ostream &operator<<(std::ostream &os, const Form &src);

#endif