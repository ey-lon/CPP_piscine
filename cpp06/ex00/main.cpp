/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:09:20 by abettini          #+#    #+#             */
/*   Updated: 2023/12/28 11:09:17 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		 std::cerr << "Wrong arguments." << std::endl;
		 return (1);
	}

	ScalarConverter::convert(av[1]);

	return (0);
}
