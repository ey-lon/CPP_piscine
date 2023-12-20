/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:11:34 by abettini          #+#    #+#             */
/*   Updated: 2023/12/18 10:31:19 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <climits>
#include <unistd.h>

int	main(void)
{
	//subject main
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
	
	//test with a few numbers
	{
		std::cout << std::endl;
		sleep(0);

		Span sp = Span(5);

		try {
			sp.addRandNumber(6, 30);
		}
		catch(const std::exception& e) {
			std::cerr << "exception caught: Too many numbers." << std::endl;
		}
		
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span:  " << sp.longestSpan() << std::endl;
		std::cout << "span: " << std::endl << sp << std::endl;
	}

	//test with 10000 numbers
	{
		std::cout << std::endl;
		sleep(0);
		
		Span sp = Span(10000);
		try
		{
			sp.addNumber(INT_MAX);
			sp.addNumber(INT_MIN);
			sp.addNumber(20, 10);
			sp.addRandNumber(30, 50);
			sp.addRandNumber(10000);
		}
		catch(const std::exception& e) {
			std::cerr << "exception caught: Too many numbers." << std::endl;
		}
		
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span:  " << sp.longestSpan() << std::endl;
		std::cout << "span: " << std::endl << sp << std::endl;
	}
	return (0);
}