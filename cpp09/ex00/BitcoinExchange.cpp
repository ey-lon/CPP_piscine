/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:09:54 by abettini          #+#    #+#             */
/*   Updated: 2023/11/10 11:59:10 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	return ;
}

BitcoinExchange::BitcoinExchange(const std::string &database)
{
	/* 
	
	fill container based on database (csv file).

	if csv file has errors:
	- throw exception and end program  <--- ???
	- don't accept faulty lines        <--- ???
	??????
	
	*/

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
	if (this == &src)
		return (*this);

	/*

	copy container
	!!!
	
	*/

	return (*this);
}

//------------------------------------------------------------------------------

void BitcoinExchange::execute(const std::string &input)
{	
	/*
	
	open input file.
	throw exception if cannot open.

	read file.
	handle every line, even with errors:
	- give result if line is correct.
	- print error if not.
	
	*/
	
	;
}