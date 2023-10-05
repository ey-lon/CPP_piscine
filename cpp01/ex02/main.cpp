/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:29:39 by abettini          #+#    #+#             */
/*   Updated: 2023/09/13 13:56:59 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "string    address       = " << &string << std::endl;
	std::cout << "stringPTR address held  = " << stringPTR << std::endl;
	std::cout << "stringREF address held  = " << &stringREF << std::endl;

	std::cout << "string    value         = " << string << std::endl;
	std::cout << "stringPTR value pointed = " << *stringPTR << std::endl;
	std::cout << "stringREF value pointed = " << stringREF << std::endl;

	return (0);
}