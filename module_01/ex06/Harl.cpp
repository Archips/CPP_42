/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 12:34:53 by athirion          #+#    #+#             */
/*   Updated: 2022/09/04 12:34:55 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {

}

Harl::~Harl(void) {

}

void    Harl::debug(void){

    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
    std::cout << std::endl;
}

void    Harl::info(void){

    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
    std::cout << std::endl;
}

void    Harl::error(void){

    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
    std::cout << std::endl;
}

void    Harl::warning(void){

    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
    std::cout << std::endl;
}

void    Harl::complain(std::string level) {

    int i;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void(Harl::*levelPtr[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (i = 0; i < 4; i ++) {
        if (!level.compare(levels[i])) {
            break;
        }
        if (i == 3) {
            i = 4;
            break;
        }
    }

    switch (i) {
        case 0:
                (this->*levelPtr[i++])();
        case 1:
                (this->*levelPtr[i++])();
        case 2:
                (this->*levelPtr[i++])();
        case 3:
                (this->*levelPtr[i])();
                break;
        case 4:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}
