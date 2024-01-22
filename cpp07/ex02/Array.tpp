/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:43:46 by abettini          #+#    #+#             */
/*   Updated: 2024/01/22 09:54:53 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array(void)
{
	//std::cout << "Array default constructor called" << std::endl;
	_array = new T[0];
	_size = 0;
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
	_array = new T[0];
	_size = 0;
	*this = src;
	return ;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &src)
{
	//std::cout << "Array assignment operator called" << std::endl;
	if (this != &src) {
		delete [] (_array);
		_array = new T[src._size];
		_size = src._size;
		for (unsigned int i = 0; i < src._size; i++) {
			_array[i] = src._array[i];
		}
	}
	return (*this);
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	//std::cout << "Array custom constructor called" << std::endl;
	_array = new T[n]();
	_size = n;
	return ;
}

template <typename T>
T	&Array<T>::operator[](int index)
{
	if (index < 0) {
		//std::cerr << "array index ["<< index <<"] is too small" << std::endl;
		throw (std::exception());
	}
	if ((unsigned int)index >= _size) {
		//std::cerr << "array index ["<< index <<"] is too big" << std::endl;
		throw (std::exception());
	}
	return (_array[index]);
}

template <typename T>
const T	&Array<T>::operator[](int index) const
{
	if (index < 0) {
		//std::cerr << "array index ["<< index <<"] is too small" << std::endl;
		throw (std::exception());
	}
	if ((unsigned int)index >= _size) {
		//std::cerr << "array index ["<< index <<"] is too big" << std::endl;
		throw (std::exception());
	}
	return (_array[index]);
}

template <typename T>
const unsigned int	&Array<T>::size(void) const
{
	return (_size);
}
