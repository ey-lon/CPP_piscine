/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:49:12 by abettini          #+#    #+#             */
/*   Updated: 2023/11/06 12:45:52 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include <iostream>

int main()
{
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	{
		MutantStack<int> *mstackptr = new MutantStack<int>;
		MutantStack<int> &mstack = *mstackptr;
		mstack.push(11);
		mstack.push(27);
		mstack.push(39);

		std::cout << std::endl;
		std::cout << "first/begin        " << *(mstack.begin()) << std::endl;
		std::cout << "last (= &end - 1)  " << *(mstack.end() - 1) << std::endl;
		std::cout << "top (= last)       " << mstack.top() << std::endl;
		std::cout << "size               " << mstack.size() << std::endl;

		MutantStack<int> const mstackcpy(mstack);

		std::cout << std::endl;
		std::cout << "first/begin        " << *(mstackcpy.begin()) << std::endl;
		std::cout << "last (= &end - 1)  " << *(mstackcpy.end() - 1) << std::endl;
		std::cout << "top (= last)       " << mstackcpy.top() << std::endl;
		std::cout << "size               " << mstackcpy.size() << std::endl;
		std::cout << std::endl;

		delete mstackptr;
	}

	return (0);
}