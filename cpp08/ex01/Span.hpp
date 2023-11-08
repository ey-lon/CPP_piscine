/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:12:16 by abettini          #+#    #+#             */
/*   Updated: 2023/11/06 14:17:12 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>

class Span
{
	private:
		std::vector<int>	_vector;
		unsigned int		_maxSize;
		Span(void);

	public:		
		Span(unsigned int N);
		Span(const Span &src);
		Span &operator=(const Span &src);
		~Span(void);

		const int	&operator[](int index) const;

		void				addNumber(int nbr);
		void				addNumber(int n, int nbr);
		void				addRandNumber(int n);
		void				addRandNumber(int n, int max);
		unsigned int		shortestSpan(void) const;
		unsigned int		longestSpan(void) const;
		
		unsigned int		size(void) const;
};

std::ostream &operator<<(std::ostream &os, Span &src); 

#endif