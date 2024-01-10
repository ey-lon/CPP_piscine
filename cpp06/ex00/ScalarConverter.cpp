/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:59:11 by abettini          #+#    #+#             */
/*   Updated: 2024/01/10 13:51:41 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <climits>
#include <cstdlib>
#include <iomanip>
#include <cmath>

//-------------------------------------------------------------------
//orthodox form

ScalarConverter::ScalarConverter(void)
{
	//std::cout << "ScalarConverter default constructor called" << std::endl;
	return ;
}

ScalarConverter::~ScalarConverter(void)
{
	//std::cout << "ScalarConverter destructor called" << std::endl;
	return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	//std::cout << "ScalarConverter copy constructor called" << std::endl;
	(void)src;
	return ;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	(void)src;
	return (*this);
}

//-------------------------------------------------------------------

static void dealPseudo(const std::string &s)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::string tmp = s;
	if (tmp[0] == '+') {
		tmp = tmp.substr(1);
	}
	if (tmp == "inff" || tmp == "-inff" || tmp == "nanf") {
		tmp[s.length() - 1] = '\0';
	}
	std::cout << "float: " << tmp << "f" << std::endl;
	std::cout << "double: " << tmp << std::endl;
}

static void	dealChar(const std::string &s)
{
	char	n;

	if (s.length() == 1) {
		n = static_cast <char> (s[0]);
	}
	else /* if (s.length() == 3) */ {
		n = static_cast <char> (s[1]);
	}
	if (n < 32 || n > 126) {
		std::cout << "char: Non displayable" << std::endl;
	}
	else {
		std::cout << "char: '" << (n) << "'" << std::endl;
	}
	std::cout << "int: " << static_cast <int> (n) << std::endl;
	std::cout << "float: " << static_cast <float> (n) << ".0f" << std::endl;
	std::cout << "double: " << static_cast <double> (n) << ".0" << std::endl;
}

static void	dealInt(const std::string &s)
{
	int	n;

	n = static_cast <int> (std::atoi(s.c_str()));

	if (n < CHAR_MIN || n > CHAR_MAX) {
		std::cout << "char: impossible" << std::endl;
	}
	else if (n < 32 || n > 126) {
		std::cout << "char: Non displayable" << std::endl;
	}
	else {
		std::cout << "char: '" << static_cast <char> (n) << "'" << std::endl;
	}
	std::cout << "int: " << (n) << std::endl;
	std::cout << "float: " << std::setprecision((int)s.length()) << static_cast <float> (n) << ".0f" << std::endl;
	std::cout << "double: " << std::setprecision((int)s.length()) << static_cast <double> (n) << ".0" << std::endl;
}

static void	dealFloat(const std::string &s)
{
	float	n;

	n = static_cast <float> (std::strtof(s.c_str(), NULL));

	//--- char ---------------
	if (n < CHAR_MIN || n > CHAR_MAX) {
		std::cout << "char: impossible" << std::endl;
	}
	else if (n < 32 || n > 126) {
		std::cout << "char: Non displayable" << std::endl;
	}
	else {
		std::cout << "char: '" << static_cast <char> (n) << "'" << std::endl;
	}
	//--- int ----------------	
	if (static_cast <long>(n) < INT_MIN || static_cast <long>(n) > INT_MAX) {
		std::cout << "int: impossible" << std::endl;
	}
	else {
		std::cout << "int: " << static_cast <int> (n) << std::endl;
	}
	//--- float --------------
	if (n == floorf(n)) {
		std::cout << "float: " << std::setprecision((int)s.length() - 2) << (n) << ".0f" << std::endl;
	}
	else {
		std::cout << "float: " << std::setprecision((int)s.length() - 2) << (n) << "f" << std::endl;
	}
	//--- double -------------
	double nd = static_cast <double> (n);
	if (nd == floor(nd)) {
		std::cout << "double: " << std::setprecision((int)s.length() - 2) << nd << ".0"<< std::endl;
	}
	else {
		std::cout << "double: " << std::setprecision((int)s.length() - 2) << nd << std::endl;
	}
}

static void	dealDouble(const std::string &s)
{
	double	n;

	n = static_cast <double> (std::strtod(s.c_str(), NULL));

	//--- char ---------------
	if (n < CHAR_MIN || n > CHAR_MAX) {
		std::cout << "char: impossible" << std::endl;
	}
	else if (n < 32 || n > 126) {
		std::cout << "char: Non displayable" << std::endl;
	}
	else {
		std::cout << "char: '" << static_cast <char> (n) << "'" << std::endl;
	}
	//--- int ----------------
	if (n < INT_MIN || n > INT_MAX) {
		std::cout << "int: impossible" << std::endl;
	}
	else {
		std::cout << "int: " << static_cast <int> (n) << std::endl;
	}
	//--- float --------------
	float nf = static_cast <float> (n);
	if (isinff(nf)) {
		std::cout << "float: impossible" << std::endl;
	}
	else if (nf == floorf(nf)) {
		std::cout << "float: " << std::setprecision((int)s.length() - 1) << nf << ".0f" << std::endl;
	}
	else {
		std::cout << "float: " << std::setprecision((int)s.length() - 1) << nf << "f" << std::endl;
	}
	//--- double -------------
	if (n == floor(n)) {
		std::cout << "double: " << std::setprecision((int)s.length() - 1) << (n) << ".0" << std::endl;
	}
	else {
		std::cout << "double: " << std::setprecision((int)s.length() - 1) << (n) << std::endl;
	}
}

int	checkType(const std::string &s);

void	ScalarConverter::convert(const std::string &literal)
{
	switch (checkType(literal))
	{
		case 0:
			dealPseudo(literal);
			break;
		case 1:
			dealChar(literal);
			break;
		case 2:
			dealInt(literal);
			break;
		case 3:
			dealFloat(literal);
			break;
		case 4:
			dealDouble(literal);
			break;
		default:
			std::cerr << "Error" << std::endl;
			break;
	}
}
