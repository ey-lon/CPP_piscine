/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:22:04 by abettini          #+#    #+#             */
/*   Updated: 2023/10/06 09:48:14 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{
	//std::cout << "AMateria default constructor called" << std::endl;
	return ;
}

AMateria::~AMateria(void)
{
	//std::cout << "AMateria destructor called" << std::endl;
	return ;
}

AMateria::AMateria(const AMateria &src)
{
	//std::cout << "AMateria copy constructor called" << std::endl;
	*this = src;
	return ;
}

AMateria &AMateria::operator=(const AMateria &src)
{
	if (this != &src)
	{
		;
	}
	return (*this);
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	//std::cout << "AMateria string constructor called" << std::endl;
	return ;
}

std::string const & AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* uses the materia against " << target.getName() << " *" << std::endl;;
}
