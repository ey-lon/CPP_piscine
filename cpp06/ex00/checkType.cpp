/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkType.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:00:46 by abettini          #+#    #+#             */
/*   Updated: 2024/04/24 10:07:13 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>
#include <climits>
#include <cstdlib>

//=====================================================
//pseudo

bool	isPseudo(const std::string &s)
{
	return (s == "inf" || s == "+inf" || s == "-inf" || s == "nan" \
		|| s == "inff" || s == "+inff" || s == "-inff" || s == "nanf");
}

//=====================================================
//char

static bool	isChar(const std::string &s)
{
	if (s.length() == 1) {
		if (std::isdigit(s[0])) {
			return (false);
		}
	}
	else if (s.length() == 3) {
		if (s[0] != '\'' || s[2] != '\'') {
			return (false);
		}
	}
	else {
		return (false);
	}
	return (true);
}

//=====================================================
//int	//2147483647

static bool	isInt(const std::string &s)
{
	size_t i = 0;
	if (s[i] == '+' || s[i] == '-') {
		i++;
	}
	if (!s[i]) {
		return (false);
	}
	for (; s[i]; i++) {
		if (!std::isdigit(s[i])) {
			return (false);
		}
	}
	long int tmp = std::strtol(s.c_str(), NULL, 10);
	return (tmp >= INT_MIN && tmp <= INT_MAX);
}

//=====================================================
//float

static bool	isFloat(const std::string &s)
{
	size_t i = 0;
	if (s[i] == '+' || s[i] == '-') {
		i++;
	}
	if (!std::isdigit(s[i])) {
		return (false);
	}
	size_t	dotPos = s.find('.');
	if (dotPos == std::string::npos || !std::isdigit(s[dotPos + 1])) {
		return (false);
	}
	size_t	fPos = s.find('f');
	if (fPos == std::string::npos || s[fPos + 1] != '\0') {
		return (false);
	}
	for (; i < fPos; i++) {
		if (i != dotPos && !std::isdigit(s[i])) {
			return (false);
		}
	}
	float	tmp = std::strtof(s.c_str(), NULL);
	return (!isinff(tmp));
}

//=====================================================
//double

static bool	isDouble(const std::string &s)
{
	size_t	i = 0;

	if (s[i] == '+' || s[i] == '-') {
		i++;
	}
	if (!std::isdigit(s[i])) {
		return (false);
	}
	size_t	dotPos = s.find('.');
	if (dotPos == std::string::npos) {
		return (false);
	}
	if (!std::isdigit(s[dotPos + 1])) {
		return (false);
	}
	for (; s[i]; i++) {
		if (i != dotPos && !std::isdigit(s[i])) {
			return (false);
		}
	}
	double	tmp = std::strtod(s.c_str(), NULL);
	return (!std::isinf(tmp));
}

//=====================================================

int	checkType(const std::string &s)
{
	int type = -1;

	if (isPseudo(s)) {
		type = 0;
	}
	else if (isChar(s)) {
		type = 1;
	}
	else if (isInt(s)) {
		type = 2;
	}
	else if (isFloat(s)) {
		type = 3;
	}
	else if (isDouble(s)) {
		type = 4;
	}
	return (type);
}