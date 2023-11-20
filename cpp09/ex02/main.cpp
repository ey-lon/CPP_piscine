/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:09:03 by abettini          #+#    #+#             */
/*   Updated: 2023/11/20 18:02:45 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <climits>
#include <cstdlib>
#include <ctime>

#include <list>
#include <deque>

static bool	isPositiveInt(const std::string &s)
{
	size_t i = 0;
 	if (s[i] == '+') {
		i++;
	}
	if (!s[i]) {
		return (false);
	}
	if (s.length() - i > 10) {
		return (false);
	}
	for (; s[i]; i++) {
		if (!std::isdigit(s[i])) {
			return (false);
		}
	}
	long int tmp = std::strtol(s.c_str(), NULL, 10);
	return (tmp >= INT_MIN && tmp <= INT_MAX);
}

static bool checkArgs(char **args)
{
	for (int i = 0; args[i]; i++) {
		if (!isPositiveInt(args[i])) {
			return (false);
		}
	}
	return (true);
}

template <typename T>
T	merge(T &contA, T &contB)
{
	T contC;

	while (contA.size() > 0 && contB.size() > 0)
	{
		if (contA.front() > contB.front())
		{
			contC.push_back(contB.front());
			contB.pop_front();
		}
		else
		{
			contC.push_back(contA.front());
			contA.pop_front();
		}
	}
	while (contA.size())
	{
		contC.push_back(contA.front());
		contA.pop_front();
	}
	while (contB.size())
	{
		contC.push_back(contB.front());
		contB.pop_front();
	}
	return (contC);
}

template <typename T>
T	mergeSort(T &container)
{
	if (container.size() == 1)
		return (container);

	typename T::iterator	begin;
	typename T::iterator	end;
	
	//contA ---
	begin = container.begin();
	end = begin;
	for (size_t i = 0; i < (container.size() / 2); i++)
		end++;
	T	contA(begin, end);

	//contB ---
	begin = end;
	end = container.end();
	T	contB(begin, end);

	contA = mergeSort(contA);
	contB = mergeSort(contB);

	return (merge(contA, contB));
}

template <typename T>
void	fillContainer(T &container, char **args)
{
	for (int i = 0; args[i]; i++) {
		container.push_back(std::atoi(args[i]));
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

template <typename T>
void	printArray(const T &array, int size)
{
	for(int i = 0; i < size; i++) {
		std::cout << array[i];
		if (i + 1 < size) {
			std::cout << " ";
		}
	}
}

int main(int ac, char **av)
{
	if (ac < 3) {
		std::cerr << "Error: invalid arguments." << std::endl;
		return (1);
	}
	av++;
	if (!checkArgs(av)) {
		std::cerr << "Error: invalid input." << std::endl;
		return (1);
	}
	ac--;
	
	std::list<int>		list;
	std::deque<int>		deque;
	fillContainer(list, av);
	fillContainer(deque, av);

	//take start time;
	//
	list = mergeSort<std::list<int> >(list);
	//take end time;
	//
	//take start time;
	//
	deque = mergeSort<std::deque<int> >(deque);
	//take end time;
	//
	
	std::cout << "Before:  ";
	printArray(av, ac);
	std::cout << std::endl;

	std::cout << "After:   ";
	printContainer(list);
	std::cout << std::endl;

	std::cout << "Time to process a range of " << list.size() << " elements with std::list : "<< "[time]" <<  " us" << std::endl;
	std::cout << "Time to process a range of " << deque.size() << " elements with std::deque : "<< "[time]" <<  " us" << std::endl;

	return (0);
}