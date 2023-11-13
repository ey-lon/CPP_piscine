/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:08:40 by abettini          #+#    #+#             */
/*   Updated: 2023/11/10 11:07:56 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <cmath>
//#include <cstdlib>

#define DB_FNAME "data.csv"
#define SPACES " \t\n\v\f\r"

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

//=====================================================
//utils

unsigned int	countStrChars(const std::string &str, const std::string &chars)
{
	unsigned int count = 0;
	for (unsigned int i = 0; i < str.size(); i++)
		if (chars.find(str[i]) != std::string::npos)
			count++;

	return (count);
}

unsigned int maxConsecutiveChars(const std::string &str, const std::string &chars)
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
}

char	charAfter(const std::string &s, char c)
{
	size_t i = 0;

	while (s[i] && s[i] != c)
		i++;
	return (s[i] ? s[i + 1] : s[i]);
	
}

//=====================================================
//int	//2147483647

bool	isInt(const std::string &s)
{
	size_t i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;

	if (!s[i])
		return (false);

	if (s.length() - i > 10)
		return (false);

	for (; s[i]; i++)
		if (!std::isdigit(s[i]))
			return (false);

	long int tmp = std::strtol(s.c_str(), NULL, 10);
	if (tmp < INT_MIN || tmp > INT_MAX)
		return (false);

	return (true);
}

//=====================================================
//double

bool	isDouble(const std::string &s)
{
	size_t i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;

	if (!std::isdigit(s[i]))
		return (false);

	if (countStrChars(s, ".") != 1)
		return (false);

	if (!std::isdigit(charAfter(s, '.')))
		return (false);

	for (; s[i]; i++)
		if (!std::isdigit(s[i]) && s[i] != '.')
			return (false);

	double	tmp = std::strtod(s.c_str(), NULL);
	if (std::isinf(tmp))
		return (false);

	return (true);
}

bool isValidValueFormat(const std::string& value)
{
	if (!isInt(value) && !isDouble(value))
	{
		std::cerr << "Error: not a valid number." << std::endl;
		return (false);
	}
	double valueDouble;
	valueDouble = std::strtod(value.c_str(), NULL);
	if (valueDouble < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return (false);
	}
	if (valueDouble > 1000)
	{
		std::cerr << "Error: too large number." << std::endl;
		return (false);
	}
	return (true);
}

bool isValidDateFormat(const std::string& date)
{
	int year, month, day;
	if (countStrChars(date, "-") != 2)
		return (false);
	if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
		return (false);
	if (month < 1 || month > 12)
		return (false);
	if (day < 1 || day > 31)
		return (false);
	return (true);
}

bool handleInputLine(const std::string& line)
{
	if (countStrChars(line, SPACES) != 2 || maxConsecutiveChars(line, SPACES) > 1)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return (false);
	}

    std::istringstream lineStream(line);
    std::string date, value, separator;
	lineStream >> date >> separator >> value;

	if (separator != "|" || !isValidDateFormat(date))
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return (false);
	}

	if (!isValidValueFormat(value))
	{
		return (false);
	}

    std::cout << date << " => " << value << " => " << "result" << std::endl;
    return (true);
}

bool handleInput(std::ifstream &inputFile)
{
	std::string line;
	std::getline(inputFile, line);
	if (line != "date | value")
		return (false);

    while (std::getline(inputFile, line))
	{
        handleInputLine(line);
    }
	return (true);
}

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
	
	handleInput(fileIn);


	dataBaseIF.close();
	fileIn.close();
	
	return (0);
}