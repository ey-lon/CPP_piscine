/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:48:56 by abettini          #+#    #+#             */
/*   Updated: 2023/11/01 18:02:24 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <stdexcept>
#include <algorithm>
#include <numeric>

//------------------------------------------------------------------

Span::Span(void)
{
	//std::cout << "Span default constructor called" << std::endl;
	_maxSize = 0;
	return ;
}

Span::Span(unsigned int N)
{
	//std::cout << "Span custom constructor called" << std::endl;
	_maxSize = N;
	return ;
}

Span::Span(const Span &src)
{
	//std::cout << "Span copy constructor called" << std::endl;
	*this = src;
	return ;
}

Span &Span::operator=(const Span &src)
{
	//std::cout << "Span assignment operator called" << std::endl;
	if (this == &src)
		return (*this);
	_vector = src._vector;
	_maxSize = src._maxSize;
	return (*this);
}

Span::~Span(void)
{
	//std::cout << Span destructor called << std::endl;
	return ;
}

//------------------------------------------------------------------

void	Span::addNumber(int nbr)
{
	if (_vector.size() == _maxSize)
		throw (std::exception());
	_vector.push_back(nbr);
}

void	Span::addNumber(int n, int nbr)
{
	for (int i = 0; i < n; i++)
		addNumber(nbr);
}

void	Span::addRandNumber(int n)
{
	srand((unsigned int)time(NULL));
	int nbr;
	for (int i = 0; i < n; i++)
	{
		nbr = rand();
		addNumber(nbr);
	}
}

void	Span::addRandNumber(int n, int max)
{
	srand((unsigned int)time(NULL));
	int nbr;
	for (int i = 0; i < n; i++)
	{
		nbr = rand() % (max + 1);
		addNumber(nbr);
	}
}

//------------------------------------------------------------------

unsigned int	Span::shortestSpan(void) const
{
	if (_vector.size() < 2)
		throw (std::exception());

	//sort the vector
	std::vector<int> tmpVec(_vector);
	std::sort(tmpVec.begin(), tmpVec.end());

	//find the differences
	std::vector<unsigned int> diffVec(_vector.size() - 1);
	std::adjacent_difference(tmpVec.begin(), tmpVec.end(), diffVec.begin());

	//return the smallest difference
	return (*std::min_element(diffVec.begin(), diffVec.end()));
}

unsigned int	Span::longestSpan(void) const
{
	if (_vector.size() < 2)
		throw (std::exception());

	//return the difference between the greatest and the smallest number of the vector
	return ((long)*std::max_element(_vector.begin(), _vector.end()) - (long)*std::min_element(_vector.begin(), _vector.end()));
}

//------------------------------------------------------------------

unsigned int	Span::size(void) const
{
	return (_vector.size());
}

//------------------------------------------------------------------

const int	&Span::operator[](int index) const
{
	if (index < 0)
		throw (std::exception());
	if ((unsigned int)index >= size())
		throw (std::exception());
	return (_vector[index]);
} 

//------------------------------------------------------------------

std::ostream &operator<<(std::ostream &os, Span &src)
{
	for (unsigned int i = 0; i < src.size(); i++)
	{
		os << src[i];
		os << (i == src.size() - 1 ? "." : ", ");
	}
	return (os);
}

//------------------------------------------------------------------

/*

static unsigned int	absDiff(long a, long b)
{
	return (std::abs(a - b));
}

int	Span::min(void) const
{
	if (_vector.size() < 1)
		throw (std::exception());

	int tmp = _vector[0];
	for (unsigned int i = 0; i < _vector.size(); i++)
		tmp = _vector[i] < tmp ? _vector[i] : tmp;
	return (tmp);
}

int	Span::max(void) const
{
	if (_vector.size() < 1)
		throw (std::exception());

	int tmp = _vector[0];
	for (unsigned int i = 0; i < _vector.size(); i++)
		tmp = _vector[i] > tmp ? _vector[i] : tmp;
	return (tmp);
}

//------------------------------------------------------------------

std::vector<int>::iterator Span::begin(void)
{
	return (_vector.begin());
}

std::vector<int>::iterator Span::end(void)
{
	return (_vector.end());
}

//------------------------------------------------------------------

const unsigned int	&Span::maxSize(void) const
{
	return (_maxSize);
}

*/
