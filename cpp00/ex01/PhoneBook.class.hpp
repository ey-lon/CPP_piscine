/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:13:16 by abettini          #+#    #+#             */
/*   Updated: 2023/12/21 09:55:51 by abettini         ###   ########.fr       */
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
	private:
		Contact contacts[8];

		void	print_contacts() const;
		void	rotate_contacts();

	public:
		PhoneBook();
		~PhoneBook();

		void add(void);
		void search(void) const;
};

#endif