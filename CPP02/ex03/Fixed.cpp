/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 02:34:20 by nasamadi          #+#    #+#             */
/*   Updated: 2023/08/18 02:34:30 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->fp_value = 0;
}

Fixed::~Fixed(){}

Fixed::Fixed(Fixed const &change)
{
	this->fp_value = change.getRawBits();
}

int	Fixed::getRawBits(void) const
{
	return (this->fp_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->fp_value = raw;
}

Fixed &Fixed::operator=(Fixed const &change)
{
	this->fp_value = change.getRawBits();
	return (*this);
}

Fixed::Fixed(float const value)
{
	this->fp_value = roundf(value * (1 << Fixed::bits));
}

Fixed::Fixed(int const value)
{
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

bool Fixed::operator>(Fixed const &comp) const
{
	return (this->getRawBits() > comp.getRawBits());
}

bool Fixed::operator>=(Fixed const &comp) const
{
	return (this->getRawBits() >= comp.getRawBits());
}

bool Fixed::operator<(Fixed const &comp) const
{
	return (this->getRawBits() < comp.getRawBits());
}

bool Fixed::operator<=(Fixed const &comp) const
{
	return (this->getRawBits() <= comp.getRawBits());
}

bool Fixed::operator==(Fixed const &comp) const
{
	return (this->getRawBits() == comp.getRawBits());
}

bool Fixed::operator!=(Fixed const &comp) const
{
	return (this->getRawBits() != comp.getRawBits());
}

Fixed Fixed::operator+(Fixed const &value)
{
	Fixed res(*this);
	res.setRawBits(this->getRawBits() + value.getRawBits());
	return (res);
}

Fixed Fixed::operator-(Fixed const &value)
{
	Fixed res(*this);
	res.setRawBits(this->getRawBits() - value.getRawBits());
	return (res);
}

Fixed Fixed::operator*(Fixed const &value)
{
	Fixed res(*this);
	long val1 = ((long)this->getRawBits());
	long val2 = ((long)value.getRawBits());
	res.setRawBits((val1 * val2) / (1 << Fixed::bits));
	return (res);
}

Fixed Fixed::operator/(Fixed const &value)
{
	Fixed res(*this);
	long val1 = ((long)this->getRawBits());
	long val2 = ((long)value.getRawBits());
	res.setRawBits((val1 * (1 << Fixed::bits)) / val2);
	return (res);
}

Fixed Fixed::operator++()
{
	this->fp_value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed val(*this);
	operator++();
	return (val);
}

Fixed Fixed::operator--()
{
	this->fp_value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed val(*this);
	operator--();
	return (val);
}

Fixed const &Fixed::min(Fixed const &x, Fixed const &y)
{
	if (x > y)
		return (y);
	return (x);
}

Fixed &Fixed::min(Fixed &x, Fixed &y)
{
	if (x > y)
		return (y);
	return (x);
}

Fixed const &min(Fixed const &x, Fixed const &y)
{
	return (Fixed::min(x, y));
}

Fixed &min(Fixed &x, Fixed &y)
{
	return (Fixed::min(x, y));
}

Fixed const &Fixed::max(Fixed const &x, Fixed const &y)
{
	if (x > y)
		return (x);
	return (y);
}

Fixed &Fixed::max(Fixed &x, Fixed &y)
{
	if (x > y)
		return (x);
	return (y);
}

Fixed const &max(Fixed const &x, Fixed const &y)
{
	return (Fixed::max(x, y));
}

Fixed &max(Fixed &x, Fixed &y)
{
	return (Fixed::max(x, y));
}