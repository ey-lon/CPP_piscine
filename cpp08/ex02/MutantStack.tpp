/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:59:08 by abettini          #+#    #+#             */
/*   Updated: 2023/11/06 12:02:59 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <iostream>

//------------------------------------------------------------------------------
//orthodox form

template <typename T>
MutantStack<T>::MutantStack(void)
{
	//std::cout << "MutantStack default constructor called" << std::endl;
	return ;
}
template <typename T>
MutantStack<T>::~MutantStack(void)
{
	//std::cout << "MutantStack destructor called" << std::endl;
	return ;
}
template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &src)
{
	//std::cout << "MutantStack copy constructor called" << std::endl;
	*this = src;
	return ;
}
template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &src)
{
	//std::cout << "MutantStack copy assignment operator called" << std::endl;
	if (this == &src)
		return (*this);
	std::stack<T>::operator=(src);
	return (*this);
}

//------------------------------------------------------------------------------

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void)
{
	return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void)
{
	return (std::stack<T>::c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin(void) const
{
	return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end(void) const
{
	return (std::stack<T>::c.end());
}
