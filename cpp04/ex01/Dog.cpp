/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:47:09 by abettini          #+#    #+#             */
/*   Updated: 2023/10/04 14:43:52 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	_type = "Dog";
	_brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
	return ;
}

Dog::~Dog(void)
{
	delete (_brain);
	std::cout << "Dog destructor called" << std::endl;
	return ;
}

Dog::Dog(const Dog &src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
	return ;
}

Dog &Dog::operator=(const Dog &src)
{
	if (this != &src)
	{
		Animal::operator=(src);
		//_type = src._type;
		*_brain = *src._brain;
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof!" << std::endl;
}

/* 
std::string	Dog::getIdea(int index) const
{
	return (_brain->getIdea(index));
}

void	Dog::setIdea(const std::string &idea, int index)
{
	_brain->setIdea(idea, index);
}
 */
