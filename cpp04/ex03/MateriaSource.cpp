/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:54:35 by abettini          #+#    #+#             */
/*   Updated: 2023/10/06 13:50:20 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	//std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < MAX_MATERIAS; i++)
		_materias[i] = NULL;
	return ;
}

MateriaSource::~MateriaSource(void)
{
	//std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < MAX_MATERIAS; i++)
		delete (_materias[i]);
	return ;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	//std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = src;
	return ;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
	if (this != &src)
	{
		bool check;
		for (int i = 0; i < MAX_MATERIAS; i++)
				delete (_materias[i]);
		for (int i = 0; i < MAX_MATERIAS; i++)
			_materias[i] = src._materias[i]->clone();
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
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
		
AMateria* MateriaSource::createMateria(std::string const & type)
{
	int	i = 0;

	while (i < MAX_MATERIAS)
	{
		if (_materias[i] && _materias[i]->getType() == type)
			return (_materias[i]->clone());
		i++;
	}
	return (0);
}
