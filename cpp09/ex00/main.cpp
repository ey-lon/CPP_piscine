/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:08:40 by abettini          #+#    #+#             */
/*   Updated: 2023/11/17 11:20:32 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#define DB_FNAME "data.csv"

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

//-----------------------------------------------------
//unused functions

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

/* static unsigned int maxConsecutiveChars(const std::string &str, const std::string &chars)
{
	unsigned int count = 0;
	unsigned int max = 0;
	for (unsigned int i = 0; i < str.size(); i++)
	{
		if (chars.find(str[i]) != std::string::npos)
			count++;
		else
		{
			max = count > max ? count : max;
			count = 0;
		}
	}
	max = count > max ? count : max;
	return (max);
} */