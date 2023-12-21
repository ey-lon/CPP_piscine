/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:52:32 by abettini          #+#    #+#             */
/*   Updated: 2023/12/21 10:27:22 by abettini         ###   ########.fr       */
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
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::Fixed(int n)
{
	std::cout << "Int constructor called" << std::endl;
	_fixedPointNumber = n << _fractionBits;
	return ;
}

Fixed::Fixed(float n)
{
	std::cout << "Float constructor called" << std::endl;
	_fixedPointNumber = roundf(n * (1 << _fractionBits));
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src) {
		this->_fixedPointNumber = src.getRawBits();
	}
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
