/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:43:46 by abettini          #+#    #+#             */
/*   Updated: 2023/10/26 15:36:11 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array(void)
{
	//std::cout << "Array default constructor called" << std::endl;
	_size = 0;
	_array = new T[0]();
	return ;
}

template <typename T>
Array<T>::~Array(void)
{
	//std::cout << "Array destructor called" << std::endl;
	delete [] (_array);
	return ;
}

template <typename T>
Array<T>::Array(const Array<T> &src)
{
	//std::cout << "Array copy constructor called" << std::endl;
	_size = 0;
	_array = new T[src._size];
	if (!_array)
		return  ;
	_size = src._size;
	for (unsigned int i = 0; i < src._size; i++)
		_array[i] = src._array[i];
	return ;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &src)
{
	//std::cout << "Array assignment operator called" << std::endl;
	if (this == &src)
		return (*this);
	delete [] (_array);
	_size = 0;
	_array = new T[src._size];
	if (!_array)
		return (*this);
	_size = src._size;
	for (unsigned int i = 0; i < src._size; i++)
		_array[i] = src._array[i];
	return (*this);
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	//std::cout << "Array custom constructor called" << std::endl;
	_size = 0;
	_array = new T[n]();
	if (!_array)
		return ;
	_size = n;
	return ;
}

template <typename T>
T	&Array<T>::operator[](int index)
{
	//std::cerr << "array index "<< index <<" is before the beginning of the array" << std::endl;
	if (index < 0)
		throw (std::exception());

	//std::cerr << "array index "<< index <<" is after the end of the array" << std::endl;
	if ((unsigned int)index >= _size)
		throw (std::exception());

	return (_array[index]);
}

template <typename T>
const unsigned int	&Array<T>::size(void) const
{
	return (_size);
}
