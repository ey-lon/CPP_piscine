/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:03:04 by abettini          #+#    #+#             */
/*   Updated: 2023/10/04 14:31:59 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

#define MAX_BRAIN_SIZE 100

class	Brain
{
	private:
		std::string	_ideas[MAX_BRAIN_SIZE];

	public:
		Brain(void);
		virtual ~Brain(void);
		Brain(const Brain &src);
		Brain &operator=(const Brain &src);

		//std::string	getIdea(int index) const;
		//void		setIdea(const std::string &idea, int index);
};

#endif