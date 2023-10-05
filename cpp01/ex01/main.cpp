/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:57:46 by abettini          #+#    #+#             */
/*   Updated: 2023/09/13 11:27:05 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int		N = 4;
	Zombie	*zombie_horde;

	zombie_horde = zombieHorde(N, "Bobert");

	for (int i = 0; i < N; i++)
		zombie_horde[i].announce();

	delete[] (zombie_horde);

	return (0);
}