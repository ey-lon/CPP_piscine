/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:38:45 by abettini          #+#    #+#             */
/*   Updated: 2024/05/22 10:42:30 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ARRAY_HPP
# define ARRAY_HPP


template <typename T>
class Array
{
	private:
		T*				_array;
		unsigned int	_size;
	public:
		Array(void);
		~Array(void);
		Array(const Array &src);
		Array &operator=(const Array &src);

		Array(unsigned int n);
		
		T		&operator[](unsigned int index); 
		const T	&operator[](unsigned int index) const;

		const unsigned int &size(void) const;
};

#include "Array.tpp"

#endif
