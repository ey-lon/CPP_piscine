/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:38:29 by abettini          #+#    #+#             */
/*   Updated: 2023/10/24 11:53:51 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template < typename T >
const T min(const T &a, const T &b)
{
	return (a < b ? a : b);
}

template < typename T >
const T max(const T &a,const  T &b)
{
	return (a > b ? a : b);
}

template < typename T >
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

#endif
