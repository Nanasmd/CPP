/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:07:13 by nasamadi          #+#    #+#             */
/*   Updated: 2023/10/25 16:11:49 by nasamadi         ###   ########.fr       */
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
class Fixed
{
	private:
		int					_value;
		static const int	_bits = 8;
			
	public:
		Fixed();
		Fixed(Fixed &copy);
		~Fixed();

		Fixed &operator=(Fixed const &copy);

		int	getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif