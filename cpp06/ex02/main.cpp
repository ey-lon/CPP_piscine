/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:30:45 by abettini          #+#    #+#             */
/*   Updated: 2023/10/23 13:50:00 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
	Base *ptr;
	
	ptr = generate();
	if (!ptr)
		return (1);

	identify(ptr);
	identify(*ptr);

	delete (ptr);

	return (0);
}
