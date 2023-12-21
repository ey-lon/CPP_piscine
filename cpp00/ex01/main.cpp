/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:23:41 by abettini          #+#    #+#             */
/*   Updated: 2023/12/21 10:01:45 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include <iostream>

int main(void)
{
	PhoneBook 	phonebook;
	std::string input;

	while (1)
	{
		std::cout << "Type ADD, SEARCH or EXIT" << std::endl;
		std::getline(std::cin, input);
		if (input == "EXIT")
			break;
		else if (input == "ADD")
			phonebook.add();
		else if (input == "SEARCH")
			phonebook.search();
		else
			std::cerr << "Error" << std::endl;
		if (std::cin.eof())
			break ;
	}
}
