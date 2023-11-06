/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:11:34 by abettini          #+#    #+#             */
/*   Updated: 2023/11/01 17:43:22 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <climits>


void spanPrint(const Span &sp)
{
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

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
		Span sp = Span(10000);

		try
		{
			sp.addNumber(INT_MAX);
			sp.addNumber(INT_MIN);

			sp.addNumber(20, 10);

			sp.addRandNumber(3);
			sp.addRandNumber(10000, 30);


		}
		catch(const std::exception& e){}
		
		//std::cout << sp << std::endl;
	
		spanPrint(sp);
	}
	return (0);
}