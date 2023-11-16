/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:08:40 by abettini          #+#    #+#             */
/*   Updated: 2023/11/16 11:33:55 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#define DB_FNAME "data.csv"

/* int fileCheck(const std::string &str, const std::string ext)
{
	if (str.size() <= ext.size())
		return (1);

	int start = str.size() - ext.size();
	int length = str.size() - start;
	if (str.substr(start, length) != ext)
		return (1);

	return (0);
} */

//-----------------------------------------------------

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: wrong arguments." << std::endl;
		return (1);
	}

	try
	{
		BitcoinExchange bce(DB_FNAME);
		
		bce.execute(av[1]);
	}
	catch (std::exception) {}

	return (0);
}