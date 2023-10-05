/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:48:23 by abettini          #+#    #+#             */
/*   Updated: 2023/10/04 14:21:46 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

# define MAX_MATERIAS 4

class	MateriaSource : public IMateriaSource
{
	private:
		AMateria *_materias[MAX_MATERIAS];

	public:
		MateriaSource(void);
		~MateriaSource(void);
		MateriaSource(const MateriaSource &src);
		MateriaSource &operator=(const MateriaSource &src);

		virtual void learnMateria(AMateria*);		
		virtual AMateria* createMateria(std::string const & type);
};

#endif
