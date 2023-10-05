/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:19:50 by abettini          #+#    #+#             */
/*   Updated: 2023/09/25 16:30:45 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap Default constructor called" << std::endl;

	//this->setName("");
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap String constructor called" << std::endl;

	//this->setName(name);
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);

	return ;
}

FragTrap::FragTrap(const FragTrap &src) :ClapTrap(src)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	return ;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	if (this != &src)
	{
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
	if (this->getHitPoints() <= 0)
		std::cout << "FragTrap " << this->getName() << " is dead!" << std::endl;
	else if (this->getEnergyPoints() <= 0)
		std::cout << "FragTrap " << this->getName() << " doesn't have enough energy points to high five!" << std::endl;
	else
	{
		std::cout << "FragTrap " << this->getName() << " high fives!" << std::endl;
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
}

//--------------------
