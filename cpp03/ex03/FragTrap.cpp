/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:19:50 by abettini          #+#    #+#             */
/*   Updated: 2024/04/24 10:34:05 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	this->setHitPoints(_defaultHitPoints);
	this->setEnergyPoints(_defaultEnergyPoints);
	this->setAttackDamage(_defaultAttackDamage);
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap String constructor called" << std::endl;
	this->setHitPoints(_defaultHitPoints);
	this->setEnergyPoints(_defaultEnergyPoints);
	this->setAttackDamage(_defaultAttackDamage);
	return ;
}

FragTrap::FragTrap(const FragTrap &src)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = src;
	return ;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	if (this != &src) {
		this->setName(src.getName());
		this->setHitPoints(src.getEnergyPoints());
		this->setEnergyPoints(src.getEnergyPoints());
		this->setAttackDamage(src.getAttackDamage());
	}
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap Destructor called" << std::endl;
	return ;
}

//--------------------

void	FragTrap::highFivesGuys(void)
{
	if (this->getHitPoints() == 0) {
		std::cout << "FragTrap " << this->getName() << " is dead!" << std::endl;
	}
	else if (this->getEnergyPoints() == 0) {
		std::cout << "FragTrap " << this->getName() << " doesn't have enough energy points to high five!" << std::endl;
	}
	else {
		std::cout << "FragTrap " << this->getName() << " high fives!" << std::endl;
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
}

//--------------------
