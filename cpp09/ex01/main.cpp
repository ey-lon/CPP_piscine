/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:08:59 by abettini          #+#    #+#             */
/*   Updated: 2023/11/17 17:28:44 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

//=====================================================

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: wrong arguments." << std::endl;
		return (1);
	}

	std::string str(av[1]);
	RPN	calculator;
	try
	{
		calculator.execute(str);
	}
	catch (std::exception)
	{
		std::cerr << "Error: invalid input." << std::endl;
	}

	return (0);
}