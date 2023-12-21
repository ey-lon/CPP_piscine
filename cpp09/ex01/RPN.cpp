/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:33:35 by abettini          #+#    #+#             */
/*   Updated: 2023/12/21 11:59:51 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <climits>
#include <cstdlib>
#include <vector>

//=====================================================
//utils

static bool	isDigit(const std::string &s)
{
	return (s.length() == 1 && std::isdigit(s[0]));
}

static int	strLenMod(const char *s, const std::string &del)
{
	int i = 0;
	while (s[i] && del.find(s[i]) == std::string::npos) {
		i++;
	}
	return (i);
}

//---------------------------------------------------------

static void printVector(const std::vector<int> &vector)
{
	if (!vector.size()) {
		return;
	}
	for (std::vector<int>::const_iterator it = vector.begin(); it != vector.end(); ++it)
	{
		std::cout << *it;
		if (it != --(vector.end())) {
			std::cout << " ";
		}
	}
	std::cout << std::endl;
}

//---------------------------------------------------------

static void	operation(std::vector<int> &vector, char op)
{
	if (vector.size() < 2) {
		throw (ImpossibleComputationException());
	}

	int b = vector.back();
	vector.pop_back();
	int a = vector.back();
	vector.pop_back();
	switch (op)
	{
		case '+':
			vector.push_back(a + b);
			break ;
		case '-':
			vector.push_back(a - b);
			break ;
		case '*':
			vector.push_back(a * b);
			break ;
		case '/':
			if (!b) {
				throw (ImpossibleDivisionException());
			}
			vector.push_back(a / b);
			break ;
	}
}

void reversePolishNotation(const std::string &str)
{
	std::string			token;
	std::vector<int>	vector;
	
	int i = 0;
	int x = 0;
	while (1)
	{
		//spaces
		while (str[i] == ' ') {
			i++;
		}
		if (!str[i]) {
			break;
		}
		//length
		x = strLenMod(&str[i], " +-/*");
		if (!x) {
			x++;
		}
		//token
		token = str.substr(i, x);
		if (token == "+" || token == "-" || token == "/" || token == "*") {
			operation(vector, token[0]);
		}
		else if (isDigit(token)) {
			vector.push_back(std::atoi(token.c_str()));
		}
		else {
			throw (InvalidInputException());
		}
		
		i += x;
	}
	printVector(vector);
}
