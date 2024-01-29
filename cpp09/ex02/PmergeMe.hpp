/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:45:37 by abettini          #+#    #+#             */
/*   Updated: 2024/01/29 12:41:49 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <cstdlib>

template <typename T>
static T	insertionSort(T& container)
{
	if (container.size() < 2) {
		return (container);
	}

	typename T::value_type	n;
	typename T::iterator	itN;
	typename T::iterator	itNPrev;

	for (typename T::iterator it = container.begin(); it != container.end(); ++it) {
		n = *it;
        itN = it;
        while (itN != container.begin()) {
			itNPrev = itN;
			--itNPrev;
			if (*itNPrev <= n) {
				break ;
			}
			*itN = *itNPrev;
			--itN;
        }
        *itN = n;
    }
	return (container);
}

template <typename T>
T	merge(T &contA, T &contB)
{
	T contC;

	while (!contA.empty() && !contB.empty()) {
		if (contA.front() > contB.front()) {
			contC.push_back(contB.front());
			contB.pop_front();
		}
		else {
			contC.push_back(contA.front());
			contA.pop_front();
		}
	}
	while (!contA.empty()) {
		contC.push_back(contA.front());
		contA.pop_front();
	}
	while (!contB.empty()) {
		contC.push_back(contB.front());
		contB.pop_front();
	}
	return (contC);
}

template <typename T>
T	mergeSort(T &container)
{
	size_t n = 10;
	if (container.size() <= n)
	{
		insertionSort(container);
		return (container);
	}

	typename T::iterator	mid = container.begin();
	std::advance(mid, container.size() / 2);

	T	contA(container.begin(), mid);
	T	contB(mid, container.end());

	contA = mergeSort(contA);
	contB = mergeSort(contB);

	return (merge(contA, contB));
} 

template <typename T>
void	fillContainer(T &container, char **av)
{
	for (int i = 0; av[i]; i++) {
		container.push_back(std::atoi(av[i]));
	}
	return ;
}

template <typename T>
void printContainer(const T &container)
{
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
		std::cout << *it;
		if (it != --container.end()) {
			std::cout << " ";
		}
	}
}

void	PmergeMe(char **av);

#endif