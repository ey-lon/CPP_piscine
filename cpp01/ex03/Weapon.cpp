/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:59:58 by abettini          #+#    #+#             */
/*   Updated: 2023/09/18 14:50:43 by abettini         ###   ########.fr       */
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

const std::string	&Weapon::getType(void)
{
	const std::string &ref = _type;

	return (ref);
}

void	Weapon::setType(const char *type)
{
	if (type)
		_type = type;
	else
		_type = "";
}
