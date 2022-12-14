/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:11:59 by athirion          #+#    #+#             */
/*   Updated: 2022/10/15 16:12:55 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
 ** CONSTRUCTORS
 */

Bureaucrat::Bureaucrat(void): _name("Undefined"), _grade(150) {

	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name) {

	std::cout << "Bureaucrat '" << name << "' constructor called" << std::endl;

	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src._name) {

	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = src;
}

/*
 ** DESTRUCTOR
 */

Bureaucrat::~Bureaucrat(void) {
	
	std::cout << "Bureaucrat destructor called" << std::endl;
}

/*
 ** COPY ASSIGNMENT OPERATOR
 */

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &rhs) {

	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->_grade = rhs._grade;
	}
	return (*this);
}

/*
 ** MEMBER FUNCTIONS
 */
	
std::string	Bureaucrat::getName(void) const {

	return (this->_name);
}

int			Bureaucrat::getGrade(void) const {

	return (this->_grade);
}

void		Bureaucrat::incrementGrade(void) {

	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
    this->_grade --;
}

void		Bureaucrat::decrementGrade(void) {

	if (this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
    this->_grade ++;
}

void        Bureaucrat::signForm(Form &form) const {

        try {
            form.beSigned(*this);
            std::cout << this->_name << " signed " << form.getName() << std::endl;
        }
        catch (const std::exception &e) {
            std::cout << this->_name << " couldn't sign " << form.getName()  << " because " << e.what() << std::endl;
        }
}

void        Bureaucrat::executeForm(Form const &form) {

        if (form.execute(*this))
            std::cout << this->_name << " executed " << form.getName() << std::endl;
        else
            std::cout << this->_name << " couldn't execute " << form.getName() << " form" << std::endl;
}

/*
 ** OVERLOAD << OPERATOR
 */

std::ostream & operator<<(std::ostream & o, Bureaucrat const &rhs) {

	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << std::endl;
	return (o);
}
