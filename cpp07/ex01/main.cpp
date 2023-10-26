/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:55:23 by abettini          #+#    #+#             */
/*   Updated: 2023/10/26 17:40:25 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>


/*
//-----------------------------------------
//function templates for testing

template <typename T>
void	increment(T &x) {
	x++;
}

template <typename T>
void	decrement(T &x) {
	x--;
}

template <typename T>
void	square(T &x) {
	x *= x;
}

template <typename T>
bool	isEven(T &x) {
	if (x % 2)
	{
		std::cout << x << " is odd" << std::endl;
		return (false);
	}
	std::cout << x << " is even" << std::endl;
	return (false);
}

template <typename T>
void	print(T &x) {
	std::cout << x << std::endl;
}

//-----------------------------------------

int	main(void)
{
	{
		int a[] = {1, 2, 3, 8, -6};
		int len = sizeof(a) / sizeof(int);

		std::cout << "--- print int ----------" << std::endl;
		::iter(a, len, ::print<int>);

		std::cout << "--- increment int ------" << std::endl;
		::iter(a, len, ::increment<int>);
		::iter(a, len, ::print<int>);

		std::cout << "--- isEven int ---------" << std::endl;
		::iter(a, len, ::isEven<int>);

		std::cout << "--- square int ---------" << std::endl;
		::iter(a, len, ::square<int>);
		::iter(a, len, ::print<int>);
	}

	{
		char a[] = {'a', 'b', '4', '@', 'a'};
		int len = sizeof(a) / sizeof(char);

		std::cout << "--- print char ---------" << std::endl;
		::iter(a, len, ::print<char>);

		std::cout << "--- increment char -----" << std::endl;
		::iter(a, len, ::increment<char>);
		::iter(a, len, ::print<char>);

		std::cout << "--- decrement char -----" << std::endl;
		::iter(a, len, ::decrement<char>);
		::iter(a, len, ::print<char>);
	}

	{
		std::string a[] = {"ciao", "come", "va?"};
		int len = sizeof(a) / sizeof(std::string);

		std::cout << "--- print string -------" << std::endl;
		::iter(a, len, ::print<std::string>);
	}

	return (0);
}
*/

class Awesome
{
	public:
		Awesome( void ) : _n( 42 ) { return; }
		int get( void ) const { return this->_n; }
	private:
		int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
	o << rhs.get();
	return o;
}

template< typename T >
void print( T& x )
{
	std::cout << x << std::endl;
	return;
}

int main() {
	int tab[] = { 0, 1, 2, 3, 4 };
	Awesome tab2[5];

	iter( tab, 5, print<const int> );
	iter( tab2, 5, print<Awesome> );

  return 0;
}