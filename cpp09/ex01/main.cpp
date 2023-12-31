/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:08:59 by abettini          #+#    #+#             */
/*   Updated: 2023/11/20 16:54:58 by abettini         ###   ########.fr       */
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
	try
	{
		reversePolishNotation(str);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: "<< e.what() << std::endl;
	}

	return (0);
}