/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:49:12 by abettini          #+#    #+#             */
/*   Updated: 2023/11/07 15:51:47 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include <iostream>
#include <list>

int main()
{
	{
		std::cout << std::endl << "--- MutantStack --------------------" << std::endl << std::endl;
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
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
		std::cout << std::endl << "--- list ---------------------------" << std::endl << std::endl;
		std::list<int> mlist;

		mlist.push_back(5);
		mlist.push_back(17);

		std::cout << *(--mlist.end()) << std::endl;

		mlist.pop_back();

		std::cout << mlist.size() << std::endl;

		mlist.push_back(3);
		mlist.push_back(5);
		mlist.push_back(737);
		mlist.push_back(0);

		std::list<int>::iterator it = mlist.begin();
		std::list<int>::iterator ite = mlist.end();
		
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mlist);
	}

	{
		std::cout << std::endl << "--- other tests --------------------" << std::endl << std::endl;
		MutantStack<int> *mstackptr = new MutantStack<int>;
		MutantStack<int> &mstack = *mstackptr;
		mstack.push(11);
		mstack.push(27);
		mstack.push(39);
		mstack.push(46);
		mstack.push(52);
		mstack.push(63);

		std::cout << "mstack:            ";
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
		
		std::cout << "first/begin:       " << *(mstack.begin()) << std::endl;
		std::cout << "last (= &end - 1): " << *(mstack.end() - 1) << std::endl;
		std::cout << "top (= last):      " << mstack.top() << std::endl;
		std::cout << "size:              " << mstack.size() << std::endl;
		std::cout << std::endl;

		MutantStack<int> const mstackcpy(mstack);
		std::cout << "mstackcpy (const): ";
		for (MutantStack<int>::const_iterator it = mstackcpy.begin(); it != mstackcpy.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "first/begin:       " << *(mstackcpy.begin()) << std::endl;
		std::cout << "last (= &end - 1): " << *(mstackcpy.end() - 1) << std::endl;
		std::cout << "top (= last):      " << mstackcpy.top() << std::endl;
		std::cout << "size:              " << mstackcpy.size() << std::endl;
		std::cout << std::endl << "------------------------------------" << std::endl << std::endl;

		delete mstackptr;
	}

	return (0);
}