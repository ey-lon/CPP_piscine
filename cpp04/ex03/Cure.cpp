/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:47:43 by abettini          #+#    #+#             */
/*   Updated: 2023/10/06 09:48:26 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void)
{
	//std::cout << "Cure default constructor called" << std::endl;
	_type = "cure";
	return ;
}

Cure::~Cure(void)
{
	//std::cout << "Cure destructor called" << std::endl;
	return ;
}

Cure::Cure(const Cure &src)
{
	//std::cout << "Cure copy constructor called" << std::endl;
	*this = src;
	return ;
}

Cure &Cure::operator=(const Cure &src)
{
	if (this != &src)
	{
		AMateria::operator=(src);
	}
	return (*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}
