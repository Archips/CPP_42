/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:35:12 by athirion          #+#    #+#             */
/*   Updated: 2022/08/17 14:40:12 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::Contact(void) {

	std::cout << "Constructor called" << std::endl;
	return ;
}

Contact::~Contact(void) {

	std::cout << "Destructor called" << std::endl;
	return ;
}

void	Contact::getName(void) const {

    std::cout << this->_name;
	return;

}

void	Contact::getLastName(void) const {

    std::cout << this->_lastName;
    return;

}

void	Contact::getNickname(void) const {

    std::cout << this->_nickname;
    return;

}

void	Contact::getPhoneNumber(void) const {

    std::cout << this->_phoneNumber;
    return;

}

void	Contact::getSecret(void) const {

    std::cout << this->_darkestSecret;
    return;

}

void Contact::setName(std::string name) {

    this->_name = name;
    return ;
}

void Contact::setLastName(std::string lastName) {

    this->_lastName = lastName;
    return ;
}

void Contact::setNickname(std::string nickname) {

    this->_nickname = nickname;
    return ;
}

void Contact::setPhoneNumber(std::string phoneNumber) {

    this->_phoneNumber = phoneNumber;
    return ;
}

void Contact::setSecret(std::string secret) {

    this->_darkestSecret = secret;
    return ;
}

