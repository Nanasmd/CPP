/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:12:18 by nasamadi          #+#    #+#             */
/*   Updated: 2023/10/25 17:57:01 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		// Variables
		int					_value;
		static const int	_bits = 8;
			
	public:
		// Constructors
		Fixed();
		Fixed(Fixed const &copy);
		Fixed(int const value);
		Fixed(float const value);
		~Fixed();
		
		// Overload arithmetic operators
		Fixed &operator=(Fixed const &copy);
		Fixed operator+(Fixed const &copy);
		Fixed operator-(Fixed const &copy);
		Fixed operator*(Fixed const &copy);
		Fixed operator/(Fixed const &copy);

		// Overload comparison operators
		bool operator>(Fixed const &copy) const;
		bool operator>=(Fixed const &copy) const;
		bool operator<(Fixed const &copy) const;
		bool operator<=(Fixed const &copy) const;
		bool operator==(Fixed const &copy) const;
		bool operator!=(Fixed const &copy) const;
		
		// Overload increment and decrement operators
		Fixed operator++(void);
		Fixed operator--(void);
		Fixed operator++(int a);
		Fixed operator--(int a);

		// Min and Max member functions
		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static Fixed const &min(Fixed const &a, Fixed const &b);
		static Fixed const &max(Fixed const &a, Fixed const &b);
		
		// Getters and Setters
		int	getRawBits(void) const;
		void setRawBits(int const raw);
		
		// Convert functions
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, Fixed const &copy);

#endif
