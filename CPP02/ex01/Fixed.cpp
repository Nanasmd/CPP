/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 02:31:23 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 02:31:32 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed()
{
	this->fp_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &change)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fp_value = change.getRawBits();
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fp_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->fp_value = raw;
	std::cout << "setRawBits member function called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &change)
{
	std::cout << "Assignation operator called" << std::endl;
	this->fp_value = change.getRawBits();
	return (*this);
}

Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called" << std::endl;
	this->fp_value = roundf(value * (1 << Fixed::bits));
}

Fixed::Fixed(int const value)
{
	std::cout << "Int constructor called" << std::endl;
	this->fp_value = (value << Fixed::bits);	
}

std::ostream &operator<<(std::ostream &os, Fixed const &value)
{
	os << value.toFloat();
	return (os);
}

float Fixed::toFloat(void) const
{
	return ((float)this->fp_value / (float)(1 << Fixed::bits));
}

int Fixed::toInt(void) const
{
	return (this->fp_value >> Fixed::bits);
}