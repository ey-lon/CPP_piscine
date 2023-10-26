/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:13:16 by abettini          #+#    #+#             */
/*   Updated: 2023/10/16 16:07:02 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include "Contact.class.hpp"
#include <cstdlib>
#include <iomanip>

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();

		void add(void);
		void search(void);

	private:
		Contact contacts[8];
		void	print_contacts();
		void	rotate_contacts();
};

#endif