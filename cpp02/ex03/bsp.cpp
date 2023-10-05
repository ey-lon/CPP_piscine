/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:38:38 by abettini          #+#    #+#             */
/*   Updated: 2023/09/21 12:13:47 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	absFixed(const Fixed n)
{
	Fixed res;

	res = n;
	if (res < 0)
		res = res * -1;
	return (res);
}

// Function to check if a point p lies on the line formed by points p1 and p2.
bool isPointOnLine(const Point& p, const Point& p1, const Point& p2)
{
	// Check if the cross product of vectors p1p and p1p2 is approximately zero.
	Fixed crossProduct = (p.getX() - p1.getX()) * (p2.getY() - p1.getY()) - (p.getY() - p1.getY()) * (p2.getX() - p1.getX());

	return (absFixed(crossProduct) == 0); // You can adjust the epsilon value as needed.
}

// Function to check if a point p lies within the segment defined by points p1 and p2.
bool isPointInSegment(const Point& p, const Point& p1, const Point& p2)
{
	// Check if the point is on the line formed by the segment.
	if (!isPointOnLine(p, p1, p2))
		return (false);

	// Check if the point is within the range of the segment's endpoints.
	Fixed minX = Fixed::min(p1.getX(), p2.getX());
	Fixed maxX = Fixed::max(p1.getX(), p2.getX());
	Fixed minY = Fixed::min(p1.getY(), p2.getY());
	Fixed maxY = Fixed::max(p1.getY(), p2.getY());

	return (p.getX() >= minX && p.getX() <= maxX && p.getY() >= minY && p.getY() <= maxY);
}

Fixed area(Point p1, Point p2, Point p3)
{
	return (absFixed(\
		(p1.getX() * (p2.getY() - p3.getY()) + \
		p2.getX() * (p3.getY() - p1.getY()) + \
		p3.getX() * (p1.getY() - p2.getY())) / \
		2.0f));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (isPointInSegment(point, a, b) || isPointInSegment(point, b, c) || isPointInSegment(point, a, c))
		return (false);

	/* Calculate area of triangle ABC */
	Fixed A = area (a, b, c);

	/* Calculate area of triangle PBC */ 
	Fixed A1 = area (point, b, c);

	/* Calculate area of triangle PAC */ 
	Fixed A2 = area (a, point, c);

	/* Calculate area of triangle PAB */  
	Fixed A3 = area (a, b, point);

	/* Check if sum of A1, A2 and A3 is same as A */
	return (A == A1 + A2 + A3);
}
