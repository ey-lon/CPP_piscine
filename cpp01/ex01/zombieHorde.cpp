/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:35:36 by abettini          #+#    #+#             */
/*   Updated: 2023/09/13 11:24:45 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *zombie_horde;

	zombie_horde = new Zombie[N];

	for (int i = 0; i < N; i++)
		zombie_horde[i].set_name(name);
	
	return (zombie_horde);
}