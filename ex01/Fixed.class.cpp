/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:04:07 by lsuardi           #+#    #+#             */
/*   Updated: 2021/01/16 20:27:54 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

Fixed::Fixed(void) : _raw_bits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int intvar) : _raw_bits(intvar << _nb_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float floatvar) : _raw_bits(std::roundf(floatvar * (1 << _nb_bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) : _raw_bits(src._raw_bits)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

void					Fixed::operator=(Fixed const &src)
{
	std::cout << "Assignation operator called" << std::endl;
	_raw_bits = src._raw_bits;
}

std::ostream&			operator<<(std::ostream &os, Fixed const &src)
{
	os << src.toFloat();
	return (os);
}
