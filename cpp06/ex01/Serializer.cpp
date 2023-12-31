/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:52:32 by abettini          #+#    #+#             */
/*   Updated: 2023/12/28 11:27:58 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
//#include <iostream>

//--------------------------------------------------
//orthodox form

Serializer::Serializer(void)
{
	//std::cout << "Serializer default constructor called" << std::endl;
	return ;
}

Serializer::~Serializer(void)
{
	//std::cout << "Serializer destructor called" << std::endl;
	return ;
}

Serializer::Serializer(const Serializer &src)
{
	//std::cout << "Serializer copy constructor called" << std::endl;
	(void)src;
	return ;
}

Serializer &Serializer::operator=(const Serializer &src)
{
	(void)src;
	return (*this);
}

//--------------------------------------------------

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast <uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast <Data *>(raw));
}
