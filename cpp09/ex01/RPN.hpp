/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:33:46 by abettini          #+#    #+#             */
/*   Updated: 2024/01/31 12:09:49 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef RPN_HPP
# define RPN_HPP

#include <stdexcept>
#include <iostream>

void reversePolishNotation(const std::string &str);

class ImpossibleDivisionException : public std::exception
{
	public:
		virtual const char *what() const throw() { return ("cannot divide by 0."); }
};

class ImpossibleComputationException : public std::exception
{
	public:
		virtual const char *what() const throw() { return ("cannot compute."); }
};

class InvalidInputException : public std::exception
{
	public:
		virtual const char *what() const throw() { return ("invalid input."); }
};

#endif