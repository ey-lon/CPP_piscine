/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkType.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:00:46 by abettini          #+#    #+#             */
/*   Updated: 2023/10/25 10:12:22 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>
#include <climits>
#include <cstdlib>

//=====================================================
//utils

static int	countChar(const std::string &s, char c)
{
	int	count = 0;

	for (size_t i = 0; s[i]; i++)
		if (s[i] == c)
			count ++;
	
	return (count);
}

static char	charAfter(const std::string &s, char c)
{
	size_t i = 0;

	while (s[i] != c)
		i++;
	return (s[i + 1]);
}

//=====================================================
//special

bool	isSpecial(const std::string &s)
{
	//std::cout << "0 [special]" << std::endl;

	if (s == "inf" || s == "+inf" || s == "-inf" || s == "nan" \
		|| s == "inff" || s == "+inff" || s == "-inff" || s == "nanf")
		return (true);

	return (false);
}

//=====================================================
//char

static bool	isChar(const std::string &s)
{
	//std::cout << "1 [char]" << std::endl;
	if (s.length() == 1)
	{
		if (s[0] < 32 || s[0] > 126)
			return (false);
		if (std::isdigit(s[0]))
			return (false);
	}
	else if (s.length() == 3)
	{
		if (s[0] != '\'' || s[2] != '\'')
			return (false);
		if (s[1] < 32 || s[1] > 126)
			return (false);
	}
	else
		return (false);

	return (true);
}

//=====================================================
//int	//2147483647

static bool	isInt(const std::string &s)
{
	//std::cout << "2 [int]" << std::endl;
	size_t i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;

	if (!s[i])
		return (false);

	if (s.length() - i > 10)
		return (false);

	for (; s[i]; i++)
		if (!std::isdigit(s[i]))
			return (false);

	long int tmp = std::strtol(s.c_str(), NULL, 10);
	if (tmp < INT_MIN || tmp > INT_MAX)
		return (false);

	return (true);
}

//=====================================================
//float

static bool	isFloat(const std::string &s)
{
	//std::cout << "3 [float]" << std::endl;

	//if (s == "+inff" || s == "-inff" || s == "nanf")
	//	return (true);

	size_t i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;

	if (!std::isdigit(s[i]))
		return (false);

	if (countChar(s, '.') != 1 || countChar(s, 'f') != 1)
		return (false);

	if (!std::isdigit(charAfter(s, '.')) || charAfter(s, 'f'))
		return (false);

	for (; s[i]; i++)
		if (!std::isdigit(s[i]) && s[i] != '.' && s[i] != 'f')
			return (false);

	float	tmp = std::strtof(s.c_str(), NULL);
	if (isinff(tmp))
		return (false);

	return (true);
}

//=====================================================
//double

static bool	isDouble(const std::string &s)
{
	//std::cout << "4 [double]" << std::endl;

	//if (s == "+inf" || s == "-inf" || s == "nan")
	//	return (true);

	size_t i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;

	if (!std::isdigit(s[i]))
		return (false);

	if (countChar(s, '.') != 1)
		return (false);

	if (!std::isdigit(charAfter(s, '.')))
		return (false);

	for (; s[i]; i++)
		if (!std::isdigit(s[i]) && s[i] != '.')
			return (false);

	double	tmp = std::strtod(s.c_str(), NULL);
	if (std::isinf(tmp))
		return (false);

	return (true);
}

//=====================================================

int	checkType(const std::string &s)
{
	int type;

	type = -1;
	if (isSpecial(s))
		type = 0;
	else if (isChar(s))
		type = 1;
	else if (isInt(s))
		type = 2;
	else if (isFloat(s))
		type = 3;
	else if (isDouble(s))
		type = 4;

	return (type);
}