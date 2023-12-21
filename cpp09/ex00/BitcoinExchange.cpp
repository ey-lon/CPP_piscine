/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:09:54 by abettini          #+#    #+#             */
/*   Updated: 2023/12/21 11:56:24 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <cmath>

//====================================================
//utils

static unsigned int	countStrChars(const std::string &str, const std::string &chars)
{
	unsigned int count = 0;
	for (unsigned int i = 0; i < str.size(); i++)
		if (chars.find(str[i]) != std::string::npos)
			count++;
	return (count);
}

static char	charAfter(const std::string &s, char c)
{
	size_t i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (s[i] ? s[i + 1] : s[i]);
	
}


//=====================================================
//int

static bool	isInt(const std::string &s)
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
	return (tmp >= INT_MIN && tmp <= INT_MAX);
}

//=====================================================
//double

static bool	isDouble(const std::string &s)
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

//-----------------------------------------------------
//date

static bool isOnlyDigit(const std::string &s)
{
	for (size_t i = 0; s[i]; i++) {
		if (!std::isdigit(s[i])) {
			return (false);
		}
	}
	return (true);
}

static bool isLeapYear(int year)
{
	if (year % 400 == 0)
		return (true);
	if (year % 100 == 0)
		return (false);
	if (year % 4 == 0)
		return (true);
	return (false);
}

static bool isValidDateFormat(const std::string& date) //YYYY-MM-DD
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);

	std::string yearStr = date.substr(0, 4);
	std::string monthStr = date.substr(5, 2);
	std::string dayStr = date.substr(8);

	if (!isOnlyDigit(yearStr) || !isOnlyDigit(monthStr) || !isOnlyDigit(dayStr))
		return (false);

	int year = std::atoi(yearStr.c_str());
	int month = std::atoi(monthStr.c_str());
	int day = std::atoi(dayStr.c_str());

	//--- year --------------------------
	if (year < 0 || year > 9999)
		return (false);
	//--- month -------------------------
	if (month < 1 || month > 12)
		return (false);
	//--- day ---------------------------
	if (day < 1 || day > 31)
		return (false);
	if (day < 29)
		return (true);
	if (month == 2) //february
	{
		if (day > 29)
			return (false);
		else if (!isLeapYear(year))
			return (false);
		else
			return (true);
	}
	if (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
		return (false);

	return (true);
}

//-----------------------------------------------------

static double getResult(const std::map<std::string, double> &map, const std::string &date, const double &value)
{
	if (!map.size()) {
		return (0);
	}
	if (date > (--map.end())->first) {
		return (value * (--map.end())->second);
	}
	for(std::map<std::string, double>::const_iterator it = map.begin(); it != map.end(); it++)
	{
		if (date == it->first) {
			return (value * it->second);
		}
		if (date < it->first) {
			if (it != map.begin())
			{
				it--;
				return (value * it->second);
			}
			else
				return (0);
		}
	}
	return (value * (--map.end())->second);
}

static bool handleInputLine(const std::string& line, const std::map<std::string, double> &map)
{
	if (line.size() < 14 || !std::isspace(line[10]) || !std::isspace(line[12]) || line[11] != '|') {
		std::cerr << "Error: bad input => " << line << std::endl;
		return (false);
	}

	//--- date -----
	std::string date = line.substr(0, 10);
	if (!isValidDateFormat(date)) {
		std::cerr << "Error: bad input => " << line << std::endl;
		return (false);
	}
	
	//--- value ----
	std::string value = line.substr(13);
	if (!isInt(value) && !isDouble(value)) {
		std::cerr << "Error: not a valid number." << std::endl;
		return (false);
	}
	
	double valueDouble = std::strtod(value.c_str(), NULL);
	if (valueDouble < 0) {
		std::cerr << "Error: not a positive number." << std::endl;
		return (false);
	}
	if (valueDouble > 1000) {
		std::cerr << "Error: too large a number." << std::endl;
		return (false);
	}

	//use the map to calculate the result
	double result = getResult(map, date, valueDouble);
	std::cout << date << " => " << value << " => " << result << std::endl;
	return (true);
}

static bool handleInputFile(std::ifstream &inputFile, const std::map<std::string, double> &map)
{
	std::string line;
	bool		name_field = false;

	while (!inputFile.eof())
	{
		std::getline(inputFile, line);
		if (line == "") {
			;
		}
		else if (!name_field) {
			name_field = true;
			if (line != "date | value") {
				handleInputLine(line, map);
			}
		}
		else {
			handleInputLine(line, map);
		}
	}
	return (true);
}

//-----------------------------------------------------

static bool	handleDataBaseLine(std::string &line, std::map<std::string, double> &map)
{
	size_t i = line.find(',');
	if (i == std::string::npos)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return (false);
	}

	//--- date -----
	std::string date = line.substr(0, i);
	if (!isValidDateFormat(date)) {	
		std::cerr << "Error: bad input => " << line << std::endl;
		return (false);	
	}
	
	//--- value ----
	std::string value = line.substr(i + 1);
	if (!isInt(value) && !isDouble(value)) {
		std::cerr << "Error: not a valid number." << std::endl;
		return (false);
	}
	
	double valueDouble = std::strtod(value.c_str(), NULL);
	if (valueDouble < 0) {
		std::cerr << "Error: not a positive number." << std::endl;
		return (false);
	}

	//add date and value to the map
	map.insert(std::make_pair(date, valueDouble));
	return (true);	
}

static bool handleDataBaseFile(std::ifstream &dataBase, std::map<std::string, double> &map)
{
	std::string line;
	bool		name_field = false;

	while (!dataBase.eof())
	{
		std::getline(dataBase, line);
		if (line == "") {
			;
		}
		else if (!name_field) {
			name_field = true;
			if (line != "date,exchange_rate") {
				handleDataBaseLine(line, map);
			}
		}
		else {
			handleDataBaseLine(line, map);
		}
	}
	return (true);
}

//=====================================================

BitcoinExchange::BitcoinExchange()
{
	return ;
}

BitcoinExchange::BitcoinExchange(const std::string &database)
{
	//fill container based on database (csv file).

	std::ifstream	dataBaseIF(database.c_str());
	if (!dataBaseIF)
	{
		std::cerr << "Error: could not open file: " << database << std::endl;
		throw (std::exception());
	}

	handleDataBaseFile(dataBaseIF, _map);
	dataBaseIF.close();
	return ;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
	return ;
}

BitcoinExchange::~BitcoinExchange(void)
{
	return ;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this != &src)
	{
		this->_map = src._map;
	}

	return (*this);
}

//------------------------------------------------------------------------------

void BitcoinExchange::execute(const std::string &input) const
{	
	/*
	open input file -> throw exception if cannot open.
	read file -> handle every line (even with errors):
	- print result if line is correct.
	- print error if line is incorrect.
	*/

	std::ifstream	fileIn(input.c_str());
	if (!fileIn)
	{
		std::cerr << "Error: could not open file: " << input << std::endl;
		throw (std::exception());
	}
	
	handleInputFile(fileIn, _map);
	fileIn.close();
}
