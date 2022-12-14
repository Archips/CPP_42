/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athirion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 09:48:32 by athirion          #+#    #+#             */
/*   Updated: 2022/10/24 09:48:34 by athirion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

int main(int ac, char **av) {

    Scalar s;

    if (ac == 2) {
        s.convertInput(av[1]);
    }
    else
        std::cout << "Error: Bad input" << std::endl;
    return (0);
}
