/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 21:37:56 by maleca            #+#    #+#             */
/*   Updated: 2026/06/29 00:27:17 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int					_rawBits;
		static const int	_fractionnalBits;
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& other);
		Fixed &operator=(const Fixed &other);
		~Fixed();

		int	getRawBits() const;
		void	setRawBits(const int raw);
		float	tofloat( void ) const;
		int	toInt( void ) const;
	};

	std::ostream &operator<<(std::ostream &os, const Fixed &other);

#endif