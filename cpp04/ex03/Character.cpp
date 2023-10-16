/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:47:49 by abettini          #+#    #+#             */
/*   Updated: 2023/10/06 13:50:47 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
	//std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < MAX_MATERIAS; i++)
		_materias[i] = NULL;
	return ;
}

Character::~Character(void)
{
	//std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < MAX_MATERIAS; i++)
		delete (_materias[i]);
	return ;
}

Character::Character(const Character &src)
{
	//std::cout << "Character copy constructor called" << std::endl;
	*this = src;
	return ;
}

Character &Character::operator=(const Character &src)
{
	if (this != &src)
	{
		bool check;
		_name = src._name;
		for (int i = 0; i < MAX_MATERIAS; i++)
			delete (_materias[i]);
		for (int i = 0; i < MAX_MATERIAS; i++)
			_materias[i] = src._materias[i]->clone();
	}
	return (*this);
}

Character::Character(std::string const &name) : _name(name)
{
	//std::cout << "Character string constructor called" << std::endl;
	for (int i = 0; i < MAX_MATERIAS; i++)
		_materias[i] = NULL;
	return ;
}

std::string const & Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	int	i;

	//check if materia is already present in the array
	i = 0;
	while (i < MAX_MATERIAS)
	{
		if (_materias[i] == m)
			return ;
		i++;
	}

	//find a free slot and save the materia
	i = 0;
	while (i < MAX_MATERIAS && _materias[i])
		i++;
	if (i == MAX_MATERIAS)
		return ;
	_materias[i] = m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= MAX_MATERIAS)
		return ;
	_materias[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= MAX_MATERIAS || !_materias[idx])
		return ;
	_materias[idx]->use(target);
}
