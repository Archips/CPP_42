/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:51:25 by athirion          #+#    #+#             */
/*   Updated: 2022/10/14 10:15:06 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*
 ** CONSTRUCTORS
 */

Cat::Cat(void) {

    std::cout << "Cat default constructor called" << std::endl;
    this->_type = "Cat";
    this->_brain = new Brain();
}

Cat::Cat(Cat const &src) {

    std::cout << "Cat copy constructor called" << std::endl;
    this->_type = src._type;
    this->_brain = new Brain();
    this->_brain->cpyBrain(src._brain);
}

/*
 ** DESTRUCTOR
 */

Cat::~Cat(void) {

    std::cout << "Cat destructor called" << std::endl;
    delete this->_brain;
}

/*
 ** COPY ASSIGNMENT OPERATOR
 */

Cat &Cat::operator=(const Cat &rhs) {

    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &rhs) {
		this->_type = rhs._type;
    	this->_brain->cpyBrain(rhs._brain);
	}    
	return (*this);
}

/*
 ** MEMBER FUNCTION
 */

void        Cat::setIdea(std::string idea, unsigned int index) {
	
	if (index >= 0 && index < 100)
    	this->_brain->setIdea(idea, index);
}

std::string Cat::getIdea(unsigned int index) const {

	if (index >= 0 && index < 100)
    	return (this->_brain->getIdea(index));
	return (NULL);
}

void        Cat::makeSound(void) const{

    std::cout << "<<< MEOOOOOOOOOOOOW >>>" << std::endl;
}
