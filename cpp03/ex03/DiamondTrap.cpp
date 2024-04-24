/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:07:33 by abettini          #+#    #+#             */
/*   Updated: 2024/04/24 10:33:50 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), _name("")
{
	std::cout << "DiamondTrap Default constructor called" << std::endl;
	_hitPoints = FragTrap::_defaultHitPoints;
	_energyPoints = ScavTrap::_defaultEnergyPoints;
	_attackDamage = FragTrap::_defaultAttackDamage;
	return ;
};

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), _name(name)
{
	std::cout << "DiamondTrap String constructor called" << std::endl;
	_hitPoints = FragTrap::_defaultHitPoints;
	_energyPoints = ScavTrap::_defaultEnergyPoints;
	_attackDamage = FragTrap::_defaultAttackDamage;
	return ;
};

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	*this = src;
	return ;
};

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
	return ;
};

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
	if (this != &src) {
		this->_name = src._name;
		this->setName(src.getName());
		this->setHitPoints(src.getEnergyPoints());
		this->setEnergyPoints(src.getEnergyPoints());
		this->setAttackDamage(src.getAttackDamage());
	}
	return (*this);
}

void	DiamondTrap::whoAmI(void) const
{
	std::cout << "DiamondTrap name: " << this->_name << ", ClapTrap name: " << this->ClapTrap::_name << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}
