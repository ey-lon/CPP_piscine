/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:47:57 by abettini          #+#    #+#             */
/*   Updated: 2023/10/04 11:54:46 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void)
{
	//std::cout << "Ice default constructor called" << std::endl;
	_type = "ice";
	return ;
}

Ice::~Ice(void)
{
	//std::cout << "Ice destructor called" << std::endl;
	return ;
}

Ice::Ice(const Ice &src)
{
	//std::cout << "Ice copy constructor called" << std::endl;
	*this = src;
	return ;
}

Ice &Ice::operator=(const Ice &src)
{
	if (this != &src)
	{
		AMateria::operator=(src);
	}
	return (*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}
