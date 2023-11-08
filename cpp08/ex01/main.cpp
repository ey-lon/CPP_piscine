/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:11:34 by abettini          #+#    #+#             */
/*   Updated: 2023/11/07 09:45:23 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <climits>

int	main(void)
{
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	
	{
		std::cout << std::endl;

		Span sp = Span(5);

		try
		{
			sp.addRandNumber(6, 30);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Too many numbers." << std::endl;
		}
		
		std::cout << sp << std::endl;
	
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	{
		std::cout << std::endl;
		
		Span sp = Span(10000);
		try
		{
			sp.addNumber(INT_MAX);
			sp.addNumber(INT_MIN);
			sp.addNumber(20, 10);
			sp.addRandNumber(3, 50);
			sp.addRandNumber(10000);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Too many numbers." << std::endl;
		}
		
		std::cout << sp << std::endl;

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	return (0);
}