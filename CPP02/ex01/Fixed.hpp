/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 02:31:39 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 02:31:49 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>
class Fixed{
private:
	int fp_value;
	static const int bits = 8;

public:
	Fixed();
	Fixed(Fixed const &change);
	Fixed(float const value);
	Fixed(int const value);
	~Fixed();

	Fixed &operator=(Fixed const &change);
	int		getRawBits(void) const;
	void	setRawBits(int const raw); 

	float toFloat(void) const;
	int	toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);
#endif