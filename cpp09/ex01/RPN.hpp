/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:33:46 by abettini          #+#    #+#             */
/*   Updated: 2023/11/17 17:29:37 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef RPN_HPP
# define RPN_HPP

#include <list>
#include <iostream>

class RPN
{
	public:
		RPN(void);
		~RPN(void);
		RPN(const RPN &src);
		RPN &operator=(const RPN &src);

		void execute(const std::string &str) const;
};

#endif