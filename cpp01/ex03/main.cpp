/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:28:02 by abettini          #+#    #+#             */
/*   Updated: 2023/09/18 15:12:28 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	Weapon	weapon("sword");
	HumanA	hA("Carl", weapon);
	HumanB	hB("Kevin");

	hA.attack();
	hB.attack();

	weapon.setType("hammer");

	hB.setWeapon(weapon);

	hA.attack();
	hB.attack();

	return (0);
}
