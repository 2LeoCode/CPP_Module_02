/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:04:12 by lsuardi           #+#    #+#             */
/*   Updated: 2021/01/16 17:40:21 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:

	Fixed(void);
	Fixed(const Fixed &src);
	~Fixed(void);

	void				operator=(Fixed &src);

	int					getRawBits(void) const;
	void				setRawBits(int const raw);

	private:

	int					_raw_bits;
	const static int	_nb_bits = 8;
};

#endif
