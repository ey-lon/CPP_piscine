/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:00:02 by abettini          #+#    #+#             */
/*   Updated: 2023/10/04 14:43:42 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
	return ;
}

Cat::~Cat(void)
{
	delete (_brain);
	std::cout << "Cat destructor called" << std::endl;
	return ;
}

Cat::Cat(const Cat &src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
	return ;
}

Cat &Cat::operator=(const Cat &src)
{
	if (this != &src)
	{
		Animal::operator=(src);
		//_type = src._type;
		*_brain = *src._brain;
	}
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}

/* 
std::string	Cat::getIdea(int index) const
{
	return (_brain->getIdea(index));
}

void	Cat::setIdea(const std::string &idea, int index)
{
	_brain->setIdea(idea, index);
}
 */
