/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:09:14 by athirion          #+#    #+#             */
/*   Updated: 2022/10/17 14:09:15 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*
 ** CONSTRUCTORS
 */

RobotomyRequestForm::RobotomyRequestForm(void) : Form("Undefined", 72, 45) {

	std::cout << "Robotomy default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form(target, 72, 45) {

	std::cout << "Robotomy " << target << " constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src): Form(src.getName(), 72, 45) {

	std::cout << "Robotomy copy constructor called" << std::endl;
}

/*
 ** DESTRUCTOR
 */

RobotomyRequestForm::~RobotomyRequestForm(void) {

	std::cout << "Robotomy destructor called" << std::endl;
}

/*
 ** COPY ASSIGNMENT OPERATOR
 */

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {

	std::cout << "Robotomy copy assigment operator called" << std::endl;
	if (this != &rhs)
		this->_signed = rhs._signed;
	return (*this);
}

/*
 ** MEMBER FUNCTIONS
 */

int RobotomyRequestForm::execute(Bureaucrat const & executor) const {

	try {
		checkForm(executor);
		executeRobotomy();
        return (1);
	}
	catch (const std::exception &e) {
        std::cout << this->_name << " form couldn't be executed: " << e.what() << std::endl;
	}
    return (0);
}

void	RobotomyRequestForm::executeRobotomy(void) const {

    static int time = rand();
    time ++;
	std::cout << "**** Drilling noises ****" << std::endl;
	if (time % 2 == 0)
		std::cout << this->_name << " has been robotomized" << std::endl;
    else
        throw RobotomyRequestForm::RobotomyError();
}
	
