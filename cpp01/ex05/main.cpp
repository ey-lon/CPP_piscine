/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:12:00 by abettini          #+#    #+#             */
/*   Updated: 2023/09/18 11:52:53 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl a;

	a.complain("WARNING");
	std::cout << std::endl;

	a.complain("boh");
	std::cout << std::endl;

	a.complain("DEBUG");
	std::cout << std::endl;

	a.complain("ERROR");
	std::cout << std::endl;

	a.complain("aaa");
	std::cout << std::endl;

	a.complain("INFO");
	std::cout << std::endl;

	return (0);
}