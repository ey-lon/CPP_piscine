/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:14:58 by abettini          #+#    #+#             */
/*   Updated: 2023/12/21 10:55:09 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string		_name;
		bool					_signed;
		const int				_minGradeToSign;
		const int				_minGradeToExecute;
		std::string				_target;

		int	_handleGrade(const int grade) const;

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
		AForm(void);
		virtual ~AForm(void);
		AForm(const AForm &src);
		AForm &operator=(const AForm &src);

		AForm(const std::string name, const int minGradeToSign, const int minGradeToExecute);

		std::string		getName(void) const;
		bool			getSigned(void) const;
		int				getMinGradeToSign(void) const;
		int				getMinGradeToExecute(void) const;
		std::string		getTarget(void) const;

		void			setTarget(const std::string &target);

		void			beSigned(Bureaucrat &bureaucrat);
		virtual void	execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &src);

#endif