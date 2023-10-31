/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:03:32 by nasamadi          #+#    #+#             */
/*   Updated: 2023/10/25 17:50:43 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#define RESET		"\e[0m"
#define PINK		"\e[0;38;5;199m"
#define LILAC		"\e[0;38;5;13m"
#define PURPLE		"\e[0;38;5;93m"
#define BOLD_RED	"\e[1;31m"
#define BLUE		"\e[0;34m"
#define V_CYAN		"\e[0;38;5;44m"
#define GREEN       "\e[0;32m"
#define YELLOW      "\e[0;33m"

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
		
		// Overload
		Fixed &operator=(Fixed const &copy);
		
		// Getters and Setters
		int	getRawBits(void) const;
		void setRawBits(int const raw);
		
		// Member functions
		float	toFloat(void) const;
		int		toInt(void) const;

};

std::ostream &operator<<(std::ostream &out, Fixed const &copy);

#endif
