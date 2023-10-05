/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:43:51 by abettini          #+#    #+#             */
/*   Updated: 2023/10/04 14:32:40 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal
{
	private:
		Brain *_brain;
	public:
		Dog(void);
		~Dog(void);
		Dog(const Dog &src);
		Dog &operator=(const Dog &src);

		virtual void	makeSound(void) const;

		//std::string	getIdea(int index) const;
		//void		setIdea(const std::string &idea, int index);
};

#endif