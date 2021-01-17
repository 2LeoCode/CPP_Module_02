/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:04:12 by lsuardi           #+#    #+#             */
/*   Updated: 2021/01/16 23:09:18 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>
# include <iomanip>
# include <cctype>

class Fixed
{
	public:

	Fixed(int intvar = 0);
	Fixed(float floatvar);
	Fixed(const Fixed &src);
	~Fixed(void);

	inline void				operator=(Fixed const &src)
	{
		_raw_bits = src._raw_bits;
	}
	Fixed&					operator++(void);
	Fixed					operator++(int);
	Fixed&					operator--(void);
	Fixed					operator--(int);
	Fixed					operator+=(Fixed b);
	Fixed					operator-=(Fixed b);
	Fixed					operator*=(Fixed b);
	Fixed					operator/=(Fixed b);

	static const Fixed&		max(Fixed const &a, Fixed const &b);
	static const Fixed&		min(Fixed const &a, Fixed const &b);
	inline float			toFloat(void) const
	{
		return (_raw_bits / (float)(1 << _nb_bits));
	}
	inline int				toInt(void) const
	{
		return (_raw_bits >> _nb_bits);
	}
	inline int				getRawBits(void) const
	{
		return (_raw_bits);
	}
	inline void				setRawBits(int const raw)
	{
		_raw_bits = raw;
	}
	inline int				getNbBits(void) const
	{
		return (_nb_bits);
	}


	private:

	int32_t					_raw_bits;
	const static int		_nb_bits = 8;
};

std::ostream&				operator<<(std::ostream &os, Fixed const &src);

inline bool					operator<(Fixed const &a, Fixed const &b)
{
	return (a.getRawBits() < b.getRawBits());
}
inline bool					operator>(Fixed const &a, Fixed const &b)
{
	return (a.getRawBits() > b.getRawBits());
}
inline bool					operator==(Fixed const &a, Fixed const &b)
{
	return (a.getRawBits() == b.getRawBits());
}
inline bool					operator!=(Fixed const &a, Fixed const &b)
{
	return (a.getRawBits() != b.getRawBits());
}
inline bool					operator<=(Fixed const &a, Fixed const &b)
{
	return (a.getRawBits() <= b.getRawBits());
}
inline bool					operator>=(Fixed const &a, Fixed const &b)
{
	return (a.getRawBits() >= b.getRawBits());
}
Fixed						operator+(Fixed a, Fixed b);
Fixed						operator-(Fixed a, Fixed b);
Fixed						operator*(Fixed a, Fixed b);
Fixed						operator/(Fixed a, Fixed b);

#endif
