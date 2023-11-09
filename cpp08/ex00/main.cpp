/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:06:53 by abettini          #+#    #+#             */
/*   Updated: 2023/11/08 10:37:46 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main(void)
{
	int n = 12;

	//vector -----------------------------------------------------------------
	std::cout << "--- vector -----" << std::endl;

	std::vector<int>	v(5, 42);

	for (unsigned long i = 0; i < v.size(); i++) //print vector
		std::cout << v[i] << " ";
	std::cout << std::endl;
	std::cout << "easyfind: " << easyfind(v, n) << std::endl; //print find
	std::cout << std::endl;

	v[3] = n; //add n_to_find to vector

	for (unsigned long i = 0; i < v.size(); i++) //print vector
		std::cout << v[i] << " ";
	std::cout << std::endl;
	
	std::cout << "easyfind: " << easyfind(v, 12) << std::endl; //print find
	std::cout << std::endl;

	//list -------------------------------------------------------------------
	std::cout << "--- list -------" << std::endl;

	std::list<int>		l;

	l.push_back(1);
	l.push_back(-2);
	l.push_back(9);
	l.push_back(19);

	for (std::list<int>::const_iterator it = l.begin(); it != l.end(); ++it) //print list
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "easyfind: " << easyfind(l, n) << std::endl; //print find
	std::cout << std::endl;

	l.push_back(n); //add n_to_find to list

	for (std::list<int>::const_iterator it = l.begin(); it != l.end(); ++it) //print list
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "easyfind: " << easyfind(l, n) << std::endl; //print find

	return (0);
}