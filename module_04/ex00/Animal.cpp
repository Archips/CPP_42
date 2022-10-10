#include "Animal.hpp"

/*
 ** CONSTRUCTORS
 */

Animal::Animal(void) {

    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) {

    std::cout << "Animal of type " << type << " constructor called" << std::endl;
    this->_type = type;
}

Animal::Animal(Animal const &src) {

    std::cout << "Animal copy constructor called" << std::endl;
    *this = src;
}

/*
 ** DESTRUCTOR
 */

Animal::~Animal(void) {

    std::cout << "Animal destructor called" << std::endl;
}

/*
 ** COPY ASSIGNMENT OPERATOR
 */

Animal &Animal::operator=(const Animal &rhs) {

    std::cout << "Animal copy assignment operator called" << std::endl;
    this->_type = rhs._type;
    return (*this);
}

/*
 ** MEMBER FUNCTIONS
 */

void    Animal::setType(std::string type) {

    this->_type = type;
}

std::string Animal::getType(void) const{

    return (this->_type);
}

void    Animal::makeSound(void) const{

    std::cout << "<<< Default animal sound >>>" << std::endl;
}