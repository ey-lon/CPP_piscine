/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:13:23 by abettini          #+#    #+#             */
/*   Updated: 2023/12/21 10:08:14 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
	return ;
}

HumanB::~HumanB(void)
{
	return ;
}

void	HumanB::attack(void) const
{
	if (_weapon) {
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	}
	else {
		std::cout << _name << " is unarmed" << std::endl;
	}
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}
