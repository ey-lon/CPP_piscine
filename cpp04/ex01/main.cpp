/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:53:24 by abettini          #+#    #+#             */
/*   Updated: 2023/10/03 15:15:06 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		delete j;//should not create a leak
		delete i;
	}

	{
		Cat a;
		Cat b;
		b = a;
	}
	
	{
		int				arr_size = 10;
		const Animal	*animals[arr_size];

		for (int i = 0; i < arr_size / 2; i++)
			animals[i] = new Dog();
		
		for (int i = arr_size / 2; i < arr_size; i++)
			animals[i] = new Cat();

		for (int i = 0; i < arr_size; i++)
			animals[i]->makeSound();

		for (int i = 0; i < arr_size; i++)
			delete (animals[i]);
	}

	return (0);
}
