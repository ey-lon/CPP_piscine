/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:09:24 by abettini          #+#    #+#             */
/*   Updated: 2023/11/10 16:02:30 by abettini         ###   ########.fr       */
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
		//_container with csv data;
		std::map<std::string, double> _amp;

	public:
		BitcoinExchange(const std::string &database);
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange(void);

		BitcoinExchange &operator=(const BitcoinExchange &src);

		//funzione che controlla date e valori del file di input e (se corretti) ne mostra i risultati.
		void execute(const std::string &input);
};

#endif
