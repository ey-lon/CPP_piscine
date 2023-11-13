/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:00:02 by abettini          #+#    #+#             */
/*   Updated: 2023/11/10 12:48:54 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	_type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
	return ;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
	return ;
}

WrongCat::WrongCat(const WrongCat &src)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	_type = "WrongCat";
	*this = src;
	return ;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
	if (this != &src)
		;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}
