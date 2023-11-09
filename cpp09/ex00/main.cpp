/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:08:40 by abettini          #+#    #+#             */
/*   Updated: 2023/11/08 15:48:31 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

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

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: wrong arguments." << std::endl;
		return (1);
	}

	//Database (csv format)-----
	std::string		dataBaseStr(DB_FNAME);
	std::ifstream	dataBaseIF(dataBaseStr.c_str());
	if (!dataBaseIF)
	{
		std::cerr << "Error: could not open file: " << dataBaseStr << std::endl;
		return (1);
	}

	//Infile--------------------
	std::string		fileInStr(av[1]);
	std::ifstream	fileIn(fileInStr.c_str());
	if (!fileIn)
	{
		std::cerr << "Error: could not open file: " << fileInStr << std::endl;
		return (1);
	}
	
	dataBaseIF.close();
	fileIn.close();
	
	return (0);
}