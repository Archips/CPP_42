/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:56:32 by athirion          #+#    #+#             */
/*   Updated: 2022/10/11 18:34:35 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/*
 ** CONSTRUCTORS
 */

Cure::Cure(std::string const &name): AMateria(type) {

    std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(Cure const &src){

    std::cout << "Cure copy constructor called" << std::endl;
    *this = src;
}

/*
 ** DESTRUCTOR
 */

Cure::~Cure(void) {

    std::cout << "Cure destructor called" << std::endl;
}

/*
 ** COPY ASSIGNMENT OPERATOR
 */

Cure & Cure::operator=(const Cure &rhs) {

    std::cout << "Cure copy assignment operator called" << std::endl;
    if (this != &rhs)
		this->_type = rhs._type;
    return (*this);
}

/*
 ** MEMBER FUNCTIONS
 */

std::string const &getType() const {

    return (this->_type);
}

AMateria &Cure::clone(void) {
    AMateria &ptr = new Cure(this->_type);
    return (ptr);
}

void    Cure::use(ICharacter &target) {

    std::cout << "* heals " << target << "'s wounds *" << std::endl;
}
