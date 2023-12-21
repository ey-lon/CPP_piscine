/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:59:58 by abettini          #+#    #+#             */
/*   Updated: 2023/12/21 10:10:01 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"

Weapon::Weapon(const char *type)
{
	if (type)
		_type = type;
	else
		_type = "";
	return ;
}

Weapon::~Weapon(void)
{
	return ;
}

const std::string	&Weapon::getType(void) const
{
	return (_type);
}

void	Weapon::setType(const char *type)
{
	if (type) {
		_type = type;
	}
	else {
		_type = "";
	}
}
