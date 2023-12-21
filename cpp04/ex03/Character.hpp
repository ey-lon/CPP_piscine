/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:47:46 by abettini          #+#    #+#             */
/*   Updated: 2023/12/21 10:50:01 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

# define MAX_MATERIAS 4

class	Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria	*_materias[MAX_MATERIAS];

	public:
		Character(void);
		Character(std::string const &name);
		~Character(void);
		Character(const Character &src);
		Character &operator=(const Character &src);

		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};

#endif
