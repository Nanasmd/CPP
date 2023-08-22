/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 02:29:30 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 02:29:39 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed{
private:
	int fp_value;
	static const int bits = 8;

public:
	Fixed();
	Fixed(Fixed const &change);
	~Fixed();

	Fixed &operator=(Fixed const &change);
	int		getRawBits(void) const;
	void	setRawBits(int const raw); 
};


#endif