/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:45:23 by abettini          #+#    #+#             */
/*   Updated: 2024/01/29 15:33:51 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <list>
#include <deque>
#include <ctime>

void	PmergeMe(char **av)
{
	std::list<int>		list;
	std::deque<int>		deque;
	fillContainer(list, av);
	fillContainer(deque, av);

	clock_t start;
	clock_t end;

	std::cout << "Before:  ";
	printContainer(list);
	std::cout << std::endl;

	start = clock();
	list = mergeInsertionSort(list);
	end = clock();
	double time1 = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

	start = clock();
	deque = mergeInsertionSort(deque);
	end = clock();
	double time2 = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

	std::cout << "After:   ";
	printContainer(list);
	std::cout << std::endl;

	std::cout << "Time to process a range of " << list.size() << " elements with std::list : " << time1 <<  " us" << std::endl;
	std::cout << "Time to process a range of " << deque.size() << " elements with std::deque : " << time2 <<  " us" << std::endl;
}
