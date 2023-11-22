/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:09:24 by abettini          #+#    #+#             */
/*   Updated: 2023/11/17 12:35:23 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

class BitcoinExchange
{
	private:
		BitcoinExchange(void);
		std::map<std::string, double> _map; //container with csv data;

	public:
		BitcoinExchange(const std::string &database);
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange(void);

		BitcoinExchange &operator=(const BitcoinExchange &src);

		void execute(const std::string &input);
};

#endif