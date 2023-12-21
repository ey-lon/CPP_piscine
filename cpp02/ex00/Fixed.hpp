/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:38:11 by abettini          #+#    #+#             */
/*   Updated: 2023/12/21 10:18:11 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed
{
	private:
		int					_fixedPointNumber;
		static const int	_fractionBits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed &src);
		~Fixed(void);
		Fixed &operator=(const Fixed &src);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif