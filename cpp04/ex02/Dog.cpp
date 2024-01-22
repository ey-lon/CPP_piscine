/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:47:09 by abettini          #+#    #+#             */
/*   Updated: 2024/01/22 09:34:13 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog default constructor called" << std::endl;
	_type = "Dog";
	_brain = new Brain();
	return ;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete (_brain);
	return ;
}

Dog::Dog(const Dog &src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	_type = "Dog";
	_brain = new Brain();
	*this = src;
	return ;
}

Dog &Dog::operator=(const Dog &src)
{
	if (this != &src) {
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
