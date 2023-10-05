/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:35:52 by abettini          #+#    #+#             */
/*   Updated: 2023/10/04 14:43:28 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class	Animal
{
	protected:
		std::string _type;
	
	public:
		Animal(void);
		virtual ~Animal(void);
		Animal(const Animal &src);
		Animal &operator=(const Animal &src);

		std::string		getType(void) const;
		virtual void	makeSound(void) const;
};

#endif