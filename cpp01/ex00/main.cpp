/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:57:46 by abettini          #+#    #+#             */
/*   Updated: 2023/09/13 10:26:57 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie z1("Paolo");
	z1.announce();
	
	Zombie *z2;
	z2 = newZombie("Marco");
	z2->announce();
	delete (z2);

	randomChump("Luca");

	return (0);
}