/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:04:07 by lsuardi           #+#    #+#             */
/*   Updated: 2021/01/16 23:14:31 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

Fixed::Fixed(int intvar) : _raw_bits(intvar << _nb_bits)
{
}

Fixed::Fixed(float floatvar) : _raw_bits(std::roundf(floatvar * (1 << _nb_bits)))
{
}

Fixed::Fixed(const Fixed &src) : _raw_bits(src._raw_bits)
{
}

Fixed::~Fixed(void)
{
}

Fixed&			Fixed::operator++(void)
{
	_raw_bits++;
	return (*this);
}

Fixed			Fixed::operator++(int)
{
	Fixed	tmp(*this);

	++(*this);
	return (tmp);
}

Fixed&			Fixed::operator--(void)
{
	_raw_bits--;
	return (*this);
}

Fixed			Fixed::operator--(int)
{
	Fixed	tmp(*this);

	--(*this);
	return (tmp);
}

Fixed			Fixed::operator+=(Fixed b)
{
	*this = *this + b;
	return (*this);
}

Fixed			Fixed::operator-=(Fixed b)
{
	*this = *this - b;
	return (*this);
}

Fixed			Fixed::operator*=(Fixed b)
{
	*this = *this * b;
	return (*this);
}

Fixed			Fixed::operator/=(Fixed b)
{
	*this = *this / b;
	return (*this);
}

std::ostream&	operator<<(std::ostream &os, Fixed const &src)
{
	os << src.toFloat();
	return (os);
}

Fixed			operator+(Fixed a, Fixed b)
{
	Fixed	c;

	c.setRawBits(a.getRawBits() + b.getRawBits());
	return (c);
}

Fixed			operator-(Fixed a, Fixed b)
{
	Fixed	c;

	c.setRawBits(a.getRawBits() - b.getRawBits());
	return (c);
}

Fixed			operator*(Fixed a, Fixed b)
{
	Fixed	c;

	c.setRawBits((a.getRawBits() * b.getRawBits()) >> a.getNbBits());
	return (c);
}

Fixed			operator/(Fixed a, Fixed b)
{
	Fixed	c;

	c.setRawBits(a.getRawBits() / (b.getRawBits() >> a.getNbBits()));
	return (c);
}

const Fixed&			Fixed::max(Fixed const &a, Fixed const &b)
{
	return ((a >= b) ? a : b);
}

const Fixed&			Fixed::min(Fixed const &a, Fixed const &b)
{
	return ((a <= b) ? a : b);
}
