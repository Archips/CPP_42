/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:02:20 by athirion          #+#    #+#             */
/*   Updated: 2022/10/17 10:31:35 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*
 ** CONSTRUCTORS
 */

Form::Form(void): _name("Undefined"), _signed(false), _signedGrade(150), _execGrade(150) {

	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int signedGrade, int execGrade):
    _name(name), _signed(false), _signedGrade(signedGrade), _execGrade(execGrade) {

	std::cout << "Form of " << name << " constructor called" << std::endl;
	if (signedGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	else if (signedGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &src): _name(src._name), _signedGrade(src._signedGrade), _execGrade(src._execGrade) {

	std::cout << "Form copy constructor called" << std::endl;
}

/*
 ** DESTRUCTOR
 */

Form::~Form(void) {

	std::cout << "Form destructor called" << std::endl;
}

/*
 ** COPY ASSIGNMENT OPERATOR
 */

Form	&Form::operator=(const Form &rhs) {

	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_signed = rhs._signed;
	return (*this);
}

/*
 ** MEMBER FUNCTIONS
 */

std::string Form::getName(void) const {

    return(this->_name);
}

bool        Form::getSigned(void) const {

    return (this->_signed);
}

int         Form::getSignedGrade(void) const {

    return (this->_signedGrade);
}

int         Form::getExecGrade() const {

    return (this->_execGrade);
}

void        Form::beSigned(const Bureaucrat &bureaucrat) {

    if (bureaucrat.getGrade() <= this->getSignedGrade()) {
        this->_signed = true;
    }
    else {
        throw Form::GradeTooLowException();
    }
}

void		Form::checkForm(Bureaucrat const & executor) const {

    if (!this->_signed)
        throw Form::UnsignedForm();
    if (executor.getGrade() > this->_execGrade || executor.getGrade() > this->_signedGrade) {
        throw Form::GradeTooLowException();
    }
}

/*
 ** OVERLOAD << OPERATOR
 */

std::ostream &operator<<(std::ostream & o, Form const &rhs) {

	o << rhs.getName() << "'s form information :" << std::endl \
		<< "Signed ? " << rhs.getSigned() << std::endl \
		<< "Signed grade: " << rhs.getSignedGrade() << std::endl \
		<< "Exec grade: " << rhs.getExecGrade() << std::endl;
	return (o);
}
