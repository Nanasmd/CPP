/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 02:34:35 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 02:34:45 by nasamadi         ###   ########.fr       */
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

	bool operator<(Fixed const &comp) const;
	bool operator<=(Fixed const &comp) const;
	bool operator>(Fixed const &comp) const;
	bool operator>=(Fixed const &comp) const;
	bool operator==(Fixed const &comp) const;
	bool operator!=(Fixed const &comp) const;

	Fixed operator+(Fixed const &value);
	Fixed operator-(Fixed const &value);
	Fixed operator*(Fixed const &value);
	Fixed operator/(Fixed const &value);
	Fixed operator++(int); //postfix
	Fixed operator++(); // prefix
	Fixed operator--(int);
	Fixed operator--();
	
	static Fixed const &min(Fixed const &x, Fixed const &y);
	static Fixed const &max(Fixed const &x, Fixed const &y);
	static Fixed &min(Fixed &x, Fixed &y);
	static Fixed &max(Fixed &x, Fixed &y);
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);
Fixed const &min(Fixed const &x, Fixed const &y);
Fixed const &max(Fixed const &x, Fixed const &y);
Fixed &min(Fixed &x, Fixed &y);
Fixed &max(Fixed &x, Fixed &y);
#endif