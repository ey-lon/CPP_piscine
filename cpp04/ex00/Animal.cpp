/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:39:14 by abettini          #+#    #+#             */
/*   Updated: 2023/11/10 12:26:48 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("default")
{
	std::cout << "Animal default constructor called" << std::endl;
	return ;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
	return ;
}

Animal::Animal(const Animal &src) : _type("default")
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
	return ;
}

Animal &Animal::operator=(const Animal &src)
{
	if (this != &src)
		;
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "Generic animal sound!" << std::endl;
}
