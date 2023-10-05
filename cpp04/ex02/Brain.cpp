/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:05:19 by abettini          #+#    #+#             */
/*   Updated: 2023/10/04 14:33:54 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
	return ;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
	return ;
}

Brain::Brain(const Brain &src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
	return ;
}

Brain &Brain::operator=(const Brain &src)
{
	if (this != &src)
	{
		for (int i = 0; i < MAX_BRAIN_SIZE; i++)
			_ideas[i] = src._ideas[i];
	}
	return (*this);
}

/* 
std::string	Brain::getIdea(int index) const
{
	if (index < 0 || index > MAX_BRAIN_SIZE - 1)
		return ("");
	return (_ideas[index]);
}

void	Brain::setIdea(const std::string &idea, int index)
{
	if (index < 0 || index > MAX_BRAIN_SIZE - 1)
		return ;
	_ideas[index] = idea;
}
*/
