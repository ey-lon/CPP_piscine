/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:33:35 by abettini          #+#    #+#             */
/*   Updated: 2024/01/31 12:29:23 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <climits>
#include <cstdlib>
#include <vector>

static void printVector(const std::vector<int> &vector)
{
	if (vector.empty()) {
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

static bool	isOperator(const char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

//---------------------------------------------------------

static void	operation(std::vector<int> &vector, const char op)
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

//---------------------------------------------------------

/*
	operations on integers less than 10
*/
void reversePolishNotation(const std::string &str)
{
	std::vector<int>	vector;
	
	for (int i = 0; str[i]; i++)
	{
		if (std::isspace(str[i])) {
			continue;
		}
		else if (std::isdigit(str[i]) && !std::isdigit(str[i + 1])) {
			vector.push_back(str[i] - '0');
		}
		else if (isOperator(str[i])) {
			operation(vector, str[i]);
		}
		else {
			throw (InvalidInputException());
		}
	}
	printVector(vector);
}
