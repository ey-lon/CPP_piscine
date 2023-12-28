/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:54:59 by abettini          #+#    #+#             */
/*   Updated: 2023/12/28 11:31:27 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ITER_HPP
# define ITER_HPP

template <typename T, typename L, typename R>
void	iter(T* array, L length, R function)
{
	for (L i = 0; i < length; i++) {
		function(array[i]);
	}
}

#endif