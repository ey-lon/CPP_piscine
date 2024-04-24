/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:19:50 by abettini          #+#    #+#             */
/*   Updated: 2024/04/24 10:34:48 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
	this->setHitPoints(this->_defaultHitPoints);
	this->setEnergyPoints(this->_defaultEnergyPoints);
	this->setAttackDamage(this->_defaultAttackDamage);
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap String constructor called" << std::endl;
	this->setHitPoints(this->_defaultHitPoints);
	this->setEnergyPoints(this->_defaultEnergyPoints);
	this->setAttackDamage(this->_defaultAttackDamage);
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &src)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = src;
	return ;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	if (this != &src) {
		this->setName(src.getName());
		this->setHitPoints(src.getEnergyPoints());
		this->setEnergyPoints(src.getEnergyPoints());
		this->setAttackDamage(src.getAttackDamage());
	}
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Destructor called" << std::endl;
	return ;
}

//--------------------

void ScavTrap::guardGate(void)
{
	if (this->getHitPoints() == 0) {
		std::cout << "ScavTrap " << this->getName() << " is dead!" << std::endl;
	}
	else if(this->getEnergyPoints() == 0) {
		std::cout << "ScavTrap " << this->getName() << " doesn't have enough energy points to go in Gate keeper mode!" << std::endl;
	}
	else {
		std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode!" << std::endl;
	}
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->getHitPoints() == 0) {
		std::cout << "ScavTrap " << this->getName() << " is dead!" << std::endl;
	}
	else if (this->getEnergyPoints() == 0) {
		std::cout << "ScavTrap " << this->getName() << " doesn't have enough energy points to attack " << target << "!" << std::endl;
	}
	else {
		std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
}

//--------------------
