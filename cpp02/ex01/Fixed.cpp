/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:52:32 by abettini          #+#    #+#             */
/*   Updated: 2023/09/21 15:15:16 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointNumber(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

Fixed::Fixed(int n)
{
	_fixedPointNumber = n << _fractionBits;
	std::cout << "Int constructor called" << std::endl;
	return ;
}

Fixed::Fixed(float n)
{
	_fixedPointNumber = roundf(n * (1 << _fractionBits));
	std::cout << "Float constructor called" << std::endl;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	if (this != &src)
		this->_fixedPointNumber = src.getRawBits();
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPointNumber);
}

void Fixed::setRawBits( int const raw )
{
	_fixedPointNumber = raw;
}

float Fixed::toFloat( void ) const
{
	float	n;

	n = _fixedPointNumber;
	n = n / (1 << _fractionBits);
	return (n); 
}

int Fixed::toInt( void ) const
{
	int	n;

	n = _fixedPointNumber >> _fractionBits;
	return (n);
}

//

std::ostream &operator<<(std::ostream &os, const Fixed &src)
{
	os << src.toFloat();
	return (os);
}
