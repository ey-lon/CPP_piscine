/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:22:32 by abettini          #+#    #+#             */
/*   Updated: 2023/11/17 14:58:40 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(void)
{
	_first_name.erase();
	_last_name.erase();
	_nickname.erase();
	_phone_number.erase();
	_darkest_secret.erase();
	return;
}

Contact::~Contact(void)
{
	return;
}

//------------------------------------------------------------------------------

void	Contact::print_contact(void)
{
	std::cout << "FIRST NAME:" << std::endl;
	std::cout << _first_name << std::endl;
	std::cout << "LAST NAME:" << std::endl;
	std::cout << _last_name << std::endl;
	std::cout << "NICKNAME:" << std::endl;
	std::cout << _nickname << std::endl;
	std::cout << "PHONE NUMBER:" << std::endl;
	std::cout << _phone_number << std::endl;
	std::cout << "DARKEST SECRET:" << std::endl;
	std::cout << _darkest_secret << std::endl;
}

//------------------------------------------------------------------------------

void	Contact::set_first_name(const std::string &str)
{
	_first_name = str;
}

void	Contact::set_last_name(const std::string &str)
{
	_last_name = str;
}

void	Contact::set_nickname(const std::string &str)
{
	_nickname = str;
}

void	Contact::set_phone_number(const std::string &str)
{
	_phone_number = str;
}

void	Contact::set_darkest_secret(const std::string &str)
{
	_darkest_secret = str;
}

//------------------------------------------------------------------------------

const std::string &Contact::get_first_name(void) const
{
	return (_first_name);
}

const std::string &Contact::get_last_name(void) const
{
	return (_last_name);
}

const std::string &Contact::get_nickname(void) const
{
	return (_nickname);
}

const std::string &Contact::get_phone_number(void) const
{
	return (_phone_number);
}

const std::string &Contact::get_darkest_secret(void) const
{
	return (_darkest_secret);
}