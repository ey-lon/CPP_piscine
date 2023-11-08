/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:59:08 by abettini          #+#    #+#             */
/*   Updated: 2023/11/07 15:36:06 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <iostream>

//------------------------------------------------------------------------------
//orthodox form

template <typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>()
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
MutantStack<T>::MutantStack(const MutantStack<T> &src) : std::stack<T>(src)
{
	//std::cout << "MutantStack copy constructor called" << std::endl;
	return ;
}
template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &src)
{
	//std::cout << "MutantStack assignment operator called" << std::endl;
	if (this == &src)
		return (*this);
	std::stack<T>::operator=(src);
	return (*this);
}

//------------------------------------------------------------------------------

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void)
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void)
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin(void) const
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end(void) const
{
	return (this->c.end());
}

//------------------------------------------------------------------------------

template <typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rbegin(void)
{
	return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rend(void)
{
	return (this->c.rend());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rbegin(void) const
{
	return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rend(void) const
{
	return (this->c.rend());
}
