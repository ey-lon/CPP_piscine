/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:37:54 by abettini          #+#    #+#             */
/*   Updated: 2023/09/22 11:12:06 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main( void )
{
	const Point a(0, 0);
	const Point b(20, 0);
	const Point c(10, 10);
	const Point point(7, 5);

	//std::cout << bsp(Point(0, 0), Point(10, 0), Point(5, 10), Point(35,40)) << std::endl;

	std::cout << "A = (" << a.getX() << ", " << a.getY() << ")" << std::endl;
	std::cout << "B = (" << b.getX() << ", " << b.getY() << ")" << std::endl;
	std::cout << "C = (" << c.getX() << ", " << c.getY() << ")" << std::endl;
	std::cout << "P = (" << point.getX() << ", " << point.getY() << ")" << std::endl;

	if (bsp(a, b, c, point))
		std::cout << "The point P is inside the triangle ABC" << std::endl;
	else
		std::cout << "The point P is outside the triangle ABC" << std::endl;

	return (0);
}
