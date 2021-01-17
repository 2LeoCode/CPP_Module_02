/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:04:12 by lsuardi           #+#    #+#             */
/*   Updated: 2021/01/16 21:21:02 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>
# include <iomanip>

class Fixed
{
	public:

	Fixed(void);
	Fixed(int intvar);
	Fixed(float floatvar);
	Fixed(const Fixed &src);
	~Fixed(void);

	void					operator=(Fixed const &src);

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

std::ostream&			operator<<(std::ostream &os, Fixed const &src);

#endif
