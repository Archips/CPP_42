/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:40:00 by athirion          #+#    #+#             */
/*   Updated: 2022/08/24 17:53:31 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>

PhoneBook::PhoneBook(void) {

    this->_nbContact = 0;
	return ;
}

PhoneBook::~PhoneBook(void) {

	return ;
}

void    PhoneBook::fillPhoneBook(std::string name, std::string lastName,
                      std::string nickName, std::string phoneNumber,
                      std::string secret, int index) {
    
	this->_book[index].setName(name);
    this->_book[index].setLastName(lastName);
    this->_book[index].setNickname(nickName);
    this->_book[index].setPhoneNumber(phoneNumber);
    this->_book[index].setSecret(secret);
    this->_nbContact ++;

	return ;
}

void    PhoneBook::displayPhoneBook(int index) const {

    std::cout << std::setw(10) << index + 1 << "|";
	if (this->_book[index].getName().size() > 10)
		std::cout << std::setw(9) << this->_book[index].getName().substr(0, 9) << "." << "|";
	else
    	std::cout << std::setw(10) << this->_book[index].getName() << "|";
	if (this->_book[index].getLastName().size() > 10)
		std::cout << std::setw(9) << this->_book[index].getLastName().substr(0, 9) << "." << "|";
	else
		std::cout << std::setw(10) << this->_book[index].getLastName() << "|";
	if (this->_book[index].getNickname().size() > 10)
		std::cout << std::setw(9) << this->_book[index].getNickname().substr(0, 9) << "." << std::endl;
	else
    	std::cout << std::setw(10) << this->_book[index].getNickname() << std::endl;
    return ;
}

void PhoneBook::displayContact(int index) const {

	std::cout << std::endl;
    std::cout << this->_book[index].getName() << std::endl;
    std::cout << this->_book[index].getLastName() << std::endl;
    std::cout << this->_book[index].getNickname() << std::endl;
    std::cout << this->_book[index].getPhoneNumber() << std::endl;
    std::cout << this->_book[index].getSecret() << std::endl;
	std::cout << std::endl;
    return ;
}

int PhoneBook::getNbContact(void) const {

    return (_nbContact);
}
