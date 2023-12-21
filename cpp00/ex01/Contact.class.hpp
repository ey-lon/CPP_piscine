/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:15:04 by abettini          #+#    #+#             */
/*   Updated: 2023/12/21 09:50:55 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <iostream>

class Contact
{
	private:
		std::string _first_name;
		std::string _last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string _darkest_secret;

	public:
		Contact();
		~Contact();
		
		void		print_contact(void) const;

		void		set_first_name(const std::string &str);
		void		set_last_name(const std::string &str);
		void		set_nickname(const std::string &str);
		void		set_phone_number(const std::string &str);
		void		set_darkest_secret(const std::string &str);

		const std::string	&get_first_name(void) const;
		const std::string	&get_last_name(void) const;
		const std::string	&get_nickname(void) const;
		const std::string	&get_phone_number(void) const;
		const std::string	&get_darkest_secret(void) const;
};

#endif