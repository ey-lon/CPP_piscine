/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:59:31 by abettini          #+#    #+#             */
/*   Updated: 2023/10/04 14:33:32 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class	Cat : public AAnimal
{
	private:
		Brain *_brain;
	public:
		Cat(void);
		~Cat(void);
		Cat(const Cat &src);
		Cat &operator=(const Cat &src);

		virtual void	makeSound(void) const;

		//std::string	getIdea(int index) const;
		//void		setIdea(const std::string &idea, int index);
};

#endif