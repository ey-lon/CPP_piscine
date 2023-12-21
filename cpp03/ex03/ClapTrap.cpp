/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:26:54 by abettini          #+#    #+#             */
/*   Updated: 2023/12/21 10:42:10 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap String constructor called" << std::endl;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap Destructor called" << std::endl;
	return ;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	if (this != &src)
	{
		_name = src._name;
		_hitPoints = src._hitPoints;
		_energyPoints = src._energyPoints;
		_attackDamage = src._attackDamage;
	}
	return (*this);
}

//------------------------

void	ClapTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
	}
	else if (_energyPoints <= 0) {
		std::cout << "ClapTrap " << _name << " doesn't have enough energy points to attack " << target << "!" << std::endl;
	}
	else {
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints -= 1;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0) {
		_hitPoints = (unsigned int)_hitPoints > amount ? _hitPoints -= amount : 0;
		std::cout << "ClapTrap " << _name << " received " << amount << " points of damage!" << std::endl;
	}
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " doesn't have any health points left!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
	}
	else if (_energyPoints <= 0) {
		std::cout << "ClapTrap " << _name << " doesn't have enough energy points to repair itself!" << std::endl;
	}
	else {
		std::cout << "ClapTrap " << _name << " repaired itself, gaining " << amount << " health points!" << std::endl;
		_hitPoints += amount;
		_energyPoints -= 1;
	}
}

//------------------------

std::string	ClapTrap::getName(void) const
{
	return (_name);
}

int	ClapTrap::getHitPoints(void) const
{
	return (_hitPoints);
}

int	ClapTrap::getEnergyPoints(void) const
{
	return (_energyPoints);
}

int	ClapTrap::getAttackDamage(void) const
{
	return (_attackDamage);
}

//------------------------

void	ClapTrap::setName(const std::string name)
{
	_name = name;
}

void	ClapTrap::setHitPoints(const unsigned int hitPoints)
{
	_hitPoints = hitPoints;
}

void	ClapTrap::setEnergyPoints(const unsigned int energyPoints)
{
	_energyPoints = energyPoints;
}

void	ClapTrap::setAttackDamage(const unsigned int attackDamage)
{
	_attackDamage = attackDamage;
}

//------------------------