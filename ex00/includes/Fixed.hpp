/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 21:37:56 by maleca            #+#    #+#             */
/*   Updated: 2026/06/14 22:04:02 by maleca           ###   ########.fr       */
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
		Fixed(const Fixed& other);
		Fixed &operator=(const Fixed &other);
		~Fixed();

		int		getRawBits();
		void	setRawBits(const int raw);
};

#endif