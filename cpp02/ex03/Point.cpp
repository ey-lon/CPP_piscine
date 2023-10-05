/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:39:24 by abettini          #+#    #+#             */
/*   Updated: 2023/09/21 10:23:20 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
	return ;
}

Point::Point(const Point &src) : _x(src.getX()), _y(src.getY())
{
	//*this = src;
	return ;
}

Point::Point(float x, float y) : _x(Fixed(x)), _y(Fixed(y))
{
	return ;
}

Point::~Point(void)
{
	return ;
}

//--------------------

const Fixed	Point::getX(void) const
{
	return (_x);
}

const Fixed	Point::getY(void) const
{
	return (_y);
}

//--------------------

Point &Point::operator=(const Point &src)
{
	if (this != &src)
	{
		//(Fixed)_x = src.getX();
		//(Fixed)_y = src.getY();
		;
	}
	return (*this);
}
