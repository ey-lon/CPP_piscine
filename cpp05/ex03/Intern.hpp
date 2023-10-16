/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:42:27 by abettini          #+#    #+#             */
/*   Updated: 2023/10/12 09:28:04 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class	Intern
{
	public:
		Intern(void);
		~Intern(void);
		Intern(const Intern &src);
		Intern &operator=(const Intern &src);

		AForm *makeForm(const std::string &name, const std::string &target);
};

#endif