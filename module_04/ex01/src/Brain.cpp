/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:51:16 by athirion          #+#    #+#             */
/*   Updated: 2022/10/14 10:10:13 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/*
 ** CONSTRUCTORS
 */

Brain::Brain(void){

    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain const &src) {

    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i ++)
        this->_ideas[i] = src.getIdea(i);
}

/*
 ** DESTRUCTOR
 */

Brain::~Brain(void) {

    std::cout << "Brain destructor called" << std::endl;
}

/*
 ** COPY ASSIGNMENT OPERATOR
 */

Brain &Brain::operator=(const Brain &rhs) {

    std::cout << "Brain copy assignment operator called" << std::endl;
    if (this != &rhs)
		for (int i = 0; i < 100; i ++)
        	this->_ideas[i] = rhs.getIdea(i);
    return (*this);
}

/*
 ** MEMBER FUNCTIONS
 */

void    Brain::cpyBrain(Brain *brain) {

    for (int i = 0; i < 100; i++)
        this->_ideas[i] = brain->getIdea(i);
}

void    Brain::setIdea(std::string idea, unsigned int index) {

	if (index >= 0 && index < 100)
    	this->_ideas[index] = idea;
}

std::string Brain::getIdea(unsigned int index) const {

	if (index >= 0 && index < 100)
    	return (this->_ideas[index]);
	return (NULL);
}
