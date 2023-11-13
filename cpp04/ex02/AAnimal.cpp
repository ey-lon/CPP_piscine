/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:39:14 by abettini          #+#    #+#             */
/*   Updated: 2023/11/10 14:30:43 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("default")
{
	std::cout << "AAnimal default constructor called" << std::endl;
	return ;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor called" << std::endl;
	return ;
}

AAnimal::AAnimal(const AAnimal &src) : _type("default")
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = src;
	return ;
}

AAnimal &AAnimal::operator=(const AAnimal &src)
{
	if (this != &src)
		;
	return (*this);
}

std::string	AAnimal::getType(void) const
{
	return (_type);
}

/*
void	AAnimal::makeSound(void) const
{
	std::cout << "Generic animal sound!" << std::endl;
}
*/
