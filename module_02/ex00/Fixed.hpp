/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:39:30 by athirion          #+#    #+#             */
/*   Updated: 2022/09/07 09:04:40 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {

	public:

		Fixed(void);
		Fixed(Fixed const &src);
		~Fixed(void);

		Fixed & operator=(Fixed const &rhs);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);	


	private:

		int					_nb;
		static const int	_bits = 8;
	

};

#endif
