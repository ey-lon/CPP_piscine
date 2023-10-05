/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:35:52 by abettini          #+#    #+#             */
/*   Updated: 2023/10/04 14:44:54 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class	AAnimal
{
	protected:
		std::string _type;
	
	public:
		AAnimal(void);
		virtual ~AAnimal(void);
		AAnimal(const AAnimal &src);
		AAnimal &operator=(const AAnimal &src);

		std::string		getType(void) const;
		virtual void	makeSound(void) const = 0;
};

#endif