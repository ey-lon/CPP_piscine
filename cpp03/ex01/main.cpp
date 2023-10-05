/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:15:30 by abettini          #+#    #+#             */
/*   Updated: 2023/09/22 16:58:41 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap	d("Mario");
	ScavTrap	a(d);
	ScavTrap	b;

	b.setName("Luca");

	ScavTrap	c;
	c = b;

	c.setAttackDamage(3);
	a.setAttackDamage(3);

	a.attack(c.getName());
	c.takeDamage(a.getAttackDamage());

	c.beRepaired(2);
	c.attack(a.getName());
	a.takeDamage(c.getAttackDamage());

	c.attack(a.getName());
	a.takeDamage(c.getAttackDamage());

	c.attack(a.getName());
	a.takeDamage(c.getAttackDamage());

	c.attack(a.getName());
	a.takeDamage(c.getAttackDamage());

	c.attack(a.getName());
	a.takeDamage(c.getAttackDamage());

	c.attack(a.getName());
	a.takeDamage(c.getAttackDamage());

	c.guardGate();
	c.beRepaired(2);
	c.beRepaired(2);
	c.beRepaired(2);
	c.beRepaired(2);
	c.beRepaired(2);
	c.attack(a.getName());

	return (0);
}