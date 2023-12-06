/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:09:03 by abettini          #+#    #+#             */
/*   Updated: 2023/11/22 17:47:06 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <climits>
#include <cstring>

static bool	isPositiveInt(char *s)
{
	size_t i = 0;
 	if (s[i] == '+') {
		i++;
	}
	if (!s[i]) {
		return (false);
	}
	if (strlen(s) - i > 10) {
		return (false);
	}
	for (; s[i]; i++) {
		if (!std::isdigit(s[i])) {
			return (false);
		}
	}
	
	long int tmp = std::strtol(s, NULL, 10);
	return (tmp >= 0 && tmp <= INT_MAX);
}

static bool checkArgs(char **args)
{
	for (int i = 0; args[i]; i++) {
		if (!isPositiveInt(args[i])) {
			return (false);
		}
	}
	return (true);
}

int main(int ac, char **av)
{
	if (ac < 3) {
		std::cout << "Error: invalid arguments." << std::endl;
		return (1);
	}
	av++;
	if (!checkArgs(av)) {
		std::cout << "Error: invalid input." << std::endl;
		return (1);
	}
	
	PmergeMe(av);

	return (0);
}
