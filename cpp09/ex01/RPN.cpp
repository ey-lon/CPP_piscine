/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:33:35 by abettini          #+#    #+#             */
/*   Updated: 2023/11/17 18:00:19 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <climits>
#include <cstdlib>
#include <stdexcept>

RPN::RPN(void)
{
	return;
}

RPN::~RPN(void)
{
	return;
}

RPN::RPN(const RPN &src)
{
	*this = src;
	return;
}

RPN &RPN::operator=(const RPN &src)
{
	if (this == &src)
		;

	return (*this);
}

//=====================================================
//utils

static bool	isInt(const std::string &s)
{
	size_t i = 0;
/* 	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (false); */
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

static int	strLenMod(const char *s, const std::string &del)
{
	int i = 0;
	while (s[i] && del.find(s[i]) == std::string::npos)
		i++;
	return (i);
}

//---------------------------------------------------------

static void printList(const std::list<int> &list)
{
	if (!list.size())
		return;

	for (std::list<int>::const_iterator it = list.begin(); it != list.end(); ++it)
	{
		std::cout << *it;
		if (it != --(list.end()))
			std::cout << " ";
	}
	std::cout << std::endl;
}

//---------------------------------------------------------

static void	operation(std::list<int> &list, char op)
{
	if (list.size() < 2) {
		throw (std::exception());
	}

	int b = list.back();
	list.pop_back();
	int a = list.back();
	list.pop_back();
	int res;
	if (op == '+')
		res = a + b;
	if (op == '-')
		res = a - b;
	if (op == '/')
		res = a / b;
	if (op == '*')
		res = a * b;
	list.push_back(res);
}

void RPN::execute(const std::string &str) const
{
	std::string token;
	std::list<int>	list;
	
	int i = 0;
	int x = 0;
	while (1)
	{
		//spaces
		while (str[i] == ' ')
			i++;
		if (!str[i])
			break;

		//length
		x = strLenMod(&(str.c_str()[i]), " +-/*");
		if (!x)
			x++;

		//token
		token = str.substr(i, x);
		if (token == "+" || token == "-" || token == "/" || token == "*") {
			operation(list, token[0]);
		}
		else if(isInt(token)) {
			list.push_back(std::atoi(token.c_str()));
		}
		else {
			throw (std::exception());
		}
		
		i += x;
	}
	printList(list);
}
