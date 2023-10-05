/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:15:30 by abettini          #+#    #+#             */
/*   Updated: 2023/09/26 10:31:32 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	//DiamondTrap	b("Mario");
	//DiamondTrap	a(b);

	DiamondTrap	c("Paolo");
	//c = a;

	c.whoAmI();
	c.attack(c.getName());
	c.takeDamage(c.getAttackDamage());
	c.beRepaired(2);
	c.guardGate();
	c.highFivesGuys();

	return (0);
}