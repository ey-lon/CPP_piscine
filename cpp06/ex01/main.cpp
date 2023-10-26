/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:30:45 by abettini          #+#    #+#             */
/*   Updated: 2023/10/23 11:06:30 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main(void)
{
	{
		Data data;

		data.nbr = 42;

		uintptr_t raw = Serializer::serialize(&data);
		Data *ptr = Serializer::deserialize(raw);

		std::cout << "    original address = " << &data << std::endl;
		std::cout << "  serialized address = " << raw << std::endl;
		std::cout << "deserialized address = " << ptr << std::endl;
	}

	{
		Data *data = 0;

		uintptr_t raw = Serializer::serialize(data);
		Data *ptr = Serializer::deserialize(raw);

		std::cout << "    original address = " << data << std::endl;
		std::cout << "  serialized address = " << raw << std::endl;
		std::cout << "deserialized address = " << ptr << std::endl;
	}

	return (0);
}
