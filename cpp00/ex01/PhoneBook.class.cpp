/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:21:31 by abettini          #+#    #+#             */
/*   Updated: 2023/09/18 09:35:00 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void)
{
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

//==============================================================================

//------------------------------------------------------------------------------

int	ft_check_str(std::string str, int (*f)(int))
{
	int	check;
	int	i;
	int	len;

	if (str == "")
		return (1);
	if (!f)
		return (0);
	check = 0;
	len = str.length();
	i = 0;
	while (i < len && !check)
	{
		if (!(*f)(str[i]))
			check = 1;
		i++;
	}
	return (check);
}

std::string	ft_prompt(std::string msg, int (*f)(int))
{
	int			check;
	std::string	input;

	check = 1;
	while (check)
	{
		if (std::cin.eof())
			break ;
		std::cout << msg << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
			break ;
		check = ft_check_str(input, f);
		if (check)
			std::cerr << "Error" << std::endl;
	}
	return (input);
}

//------------------------------------------------------------------------------
//rotate_contacts

void	PhoneBook::rotate_contacts(void)
{
	Contact temp;
	int	max_cont;
	int i;

	max_cont = 8;
	i = 0;
	temp = this->contacts[0];
	while ((i + 1) < max_cont)
	{
		this->contacts[i] = this->contacts[(i + 1)];
		i++;
	}
	this->contacts[i] = temp;
}

//------------------------------------------------------------------------------
//ADD

void	PhoneBook::add(void)
{
	int	i;
	int	max_cont;

	max_cont = 8;
	if (this->contacts[max_cont - 1].get_first_name() != "")
	{
		this->rotate_contacts();
		i = max_cont - 1;
	}
	else
	{
		i = 0;
		while (this->contacts[i].get_first_name() != "" && i < (max_cont - 1))
			i++;
	}
	this->contacts[i].set_first_name(ft_prompt("Insert first name", std::isalpha));
	this->contacts[i].set_last_name(ft_prompt("Insert last name", std::isalpha));
	this->contacts[i].set_nickname(ft_prompt("Insert nickname", NULL));
	this->contacts[i].set_phone_number(ft_prompt("Insert phone number", std::isdigit));
	this->contacts[i].set_darkest_secret(ft_prompt("Insert darkest secret", NULL));
}

//==============================================================================

//------------------------------------------------------------------------------
//print_contacts

static void	ft_print_trunc(std::string str, int max)
{
	if (str.length() > (size_t)max)
		std::cout << str.substr(0, max - 1) << ".";
	else
		std::cout << std::setw(max) << str;
}

void	PhoneBook::print_contacts(void)
{
	int	i;
	int max;
	int max_cont;

	max = 10;
	max_cont = 8;
	i = 0;
	while (i < max_cont && this->contacts[i].get_first_name() != "")
	{
		std::cout << "|";
		std::cout << std::setw(max) << (i + 1);
		std::cout << "|";
		ft_print_trunc(this->contacts[i].get_first_name(), max);
		std::cout << "|";
		ft_print_trunc(this->contacts[i].get_last_name(), max);
		std::cout << "|";
		ft_print_trunc(this->contacts[i].get_nickname(), max);
		std::cout << "|";
		std::cout << std::endl;
		i++;
	}

}

//------------------------------------------------------------------------------

static int		ft_get_index(Contact *contacts)
{
	int	max_cont;
	int index;

	max_cont = 8;
	index = -1;
	while (index == -1)
	{
		index = std::atoi(ft_prompt("Insert index", std::isdigit).c_str()) - 1;
		if (std::cin.eof())
			break ;
		if (index < 0 || index >= max_cont || contacts[index].get_first_name() == "")
		{
			index = -1;
			std::cerr << "Error" << std::endl;
		}
	}
	return (index);
}

//------------------------------------------------------------------------------
//SEARCH

void	PhoneBook::search(void)
{
	int	index;
	
	if (this->contacts[0].get_first_name() == "")
	{
		std::cerr << "Error: Empty PhoneBook" << std::endl;
	}
	else
	{
		this->print_contacts();
		index = ft_get_index(this->contacts);
		if (std::cin.eof())
			return ;
		this->contacts[index].print_contact();
	}
}
