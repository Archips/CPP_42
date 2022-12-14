
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:44:42 by athirion          #+#    #+#             */
/*   Updated: 2022/10/05 14:38:16 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

/*
 ** CONSTRUCTORS
 */

Fixed::Fixed(void) : _nb(0) {

	/* std::cout << "Default constructor called" << std::endl; */
}


Fixed::Fixed(const int nb) {

	/* std::cout << "Int constructor called" << std::endl; */
	this->_nb = nb * ( 1 << this->_bits) ;
}


Fixed::Fixed(const float nb) {

    /* std::cout << "Float constructor called" << std::endl; */
    this->_nb = roundf(nb * (1 << this->_bits));
}


Fixed::Fixed(const Fixed &fixed) {

	/* std::cout << "Copy constructor called" << std::endl; */
	*this = fixed;
}

/*
 ** DESTRUCTOR
 */

Fixed::~Fixed(void) {

	/* std::cout << "Destructor called" << std::endl; */
}


/*
 ** COPY ASSIGNMENT OPERATOR OVERLOAD
 */

Fixed &Fixed::operator=(const Fixed &rhs) {

	/* std::cout << "Copy assigment operator called" << std::endl; */
	if (this != &rhs) 
		this->_nb = rhs.getRawBits();
	
	return (*this);
}

/*
 ** COMPARISON OPERATORS
 */

bool Fixed::operator>(const Fixed &rhs) const {

	return (this->_nb > rhs._nb);
}


bool Fixed::operator<(const Fixed &rhs) const {

	return (this->_nb < rhs._nb);
}


bool Fixed::operator>=(const Fixed &rhs) const {

	return (this->_nb >= rhs._nb);
}

bool Fixed::operator<=(const Fixed &rhs) const {

	return (this->_nb <= rhs._nb);
}


bool Fixed::operator==(const Fixed &rhs) const {

	return (this->_nb == rhs._nb);
}


bool Fixed::operator!=(const Fixed &rhs) const {

	return (this->_nb != rhs._nb);
}

/*
 ** ARITHMETIC OPERATORS
 */

Fixed Fixed::operator+(Fixed const &rhs) const {

	Fixed temp;

	temp._nb = this->_nb + rhs._nb;
	return (temp);
}


Fixed Fixed::operator-(Fixed const &rhs) const {

	Fixed temp;

	temp._nb = this->_nb - rhs._nb;
	return (temp);
}


Fixed Fixed::operator*(Fixed const &rhs) const {

	Fixed temp;

	temp._nb = this->toFloat() * rhs.toFloat() * (1 << this->_bits);
	return (temp);
}


Fixed Fixed::operator/(Fixed const &rhs) const {

	Fixed temp;

	temp._nb = (this->toFloat() / rhs.toFloat()) * (1 << this->_bits);
	return (temp);
}

/*
 ** INCERMENT/DECREMENT OPERATORS
 */

Fixed Fixed::operator++(void) {

    Fixed temp;

	++ this->_nb;
    temp._nb = this->_nb;
	return (temp);
}


Fixed Fixed::operator++(int) {

    Fixed temp;

    temp._nb = this->_nb;
	this->_nb ++;
    return (temp);
}


Fixed Fixed::operator--(void) {

    Fixed temp;

	-- this->_nb;
    temp._nb = this->_nb;
    return (temp);
}


Fixed Fixed::operator--(int) {

    Fixed temp;

    temp._nb = this->_nb;
	this->_nb --;
    return (temp);
}

/*
 ** MEMBER FUNCTIONS
 */

int	Fixed::getRawBits(void) const {

	return (this->_nb);
}


void Fixed::setRawBits(int const raw) {

	this->_nb = raw;
}

float	Fixed::toFloat(void) const {

	return ((float) this->_nb / (float)(1 << _bits));
}

int		Fixed::toInt(void) const {

	return (this->_nb / (1 << this->_bits));
}


Fixed &Fixed::min(Fixed &a, Fixed &b) {

	if (a._nb < b._nb)
		return (a);
    return (b);
}


Fixed const &Fixed::min(const Fixed &a, const Fixed &b) {

    if (a._nb < b._nb)
        return (a);
    return (b);
}


Fixed &Fixed::max(Fixed &a, Fixed &b) {

	if (a._nb > b._nb)
		return (a);
    return (b);
}

Fixed const &Fixed::max(const Fixed &a, const Fixed &b) {

    if (a._nb > b._nb)
        return (a);
    return (b);
}

/*
 ** OVERLOAD << OPERATOR
 */

std::ostream & operator<<(std::ostream & o, Fixed const & rhs) {

    o << rhs.toFloat();
    
	return (o);
}
