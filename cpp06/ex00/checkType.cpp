/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkType.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:00:46 by abettini          #+#    #+#             */
/*   Updated: 2024/01/18 11:52:03 by abettini         ###   ########.fr       */
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

	for (size_t i = 0; s[i]; i++) {
		if (s[i] == c) {
			count++;
		}
	}
	
	return (count);
}

static char	charAfter(const std::string &s, char c)
{
	size_t i = 0;

	while (s[i] != c) {
		i++;
	}
	return (s[i + 1]);
}

//=====================================================
//special

bool	isPseudo(const std::string &s)
{
	if (s.length() > 5) {
		return (false);
	}
	else if (s == "inf" || s == "+inf" || s == "-inf" || s == "nan" \
		|| s == "inff" || s == "+inff" || s == "-inff" || s == "nanf") {
		return (true);
	}
	else {
		return (false);
	}
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
	if (countChar(s, '.') != 1 || countChar(s, 'f') != 1) {
		return (false);
	}
	if (!std::isdigit(charAfter(s, '.')) || charAfter(s, 'f')) {
		return (false);
	}
	for (; s[i]; i++) {
		if (!std::isdigit(s[i]) && s[i] != '.' && s[i] != 'f') {
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
	size_t i = 0;
	if (s[i] == '+' || s[i] == '-') {
		i++;
	}
	if (!std::isdigit(s[i])) {
		return (false);
	}
	if (countChar(s, '.') != 1) {
		return (false);
	}
	if (!std::isdigit(charAfter(s, '.'))) {
		return (false);
	}
	for (; s[i]; i++) {
		if (!std::isdigit(s[i]) && s[i] != '.') {
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