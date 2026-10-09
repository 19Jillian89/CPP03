/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilnassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 19:36:53 by ilnassi           #+#    #+#             */
/*   Updated: 2026/09/13 19:40:14 by ilnassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "Character creation" << std::endl;
    ClapTrap clappy("Clappy");
    ClapTrap trappy("Trappy");

    std::cout << "\n Attack and Repair " << std::endl;
    clappy.attack("Target Dummy");
    clappy.beRepaired(5);

    std::cout << "\n Sustain damage " << std::endl;
    trappy.takeDamage(4);
    trappy.takeDamage(10); // Questo lo ucciderà
    trappy.attack("Target Dummy"); // Non dovrebbe funzionare perché è morto
    trappy.beRepaired(5);       // Non dovrebbe funzionare perché è morto

    std::cout << "\n Energy Depletion " << std::endl;
    ClapTrap tiredBoy("Tired");
    //Vengono consumati i punti energia
    for (int i = 0; i < 11; i++)
    {
        tiredBoy.attack("un muro");
    }

    std::cout << "\n Copy constructor test " << std::endl;
    ClapTrap original("Original");
    original.takeDamage(3); // modifico lo stato prima di copiare
    ClapTrap copy(original); // qui deve stampare "ClapTrap copy." una sola volta
    copy.attack("Test Dummy"); // se la copia è corretta, danno e nome coerenti con original

    std::cout << "\n Copy assignment test " << std::endl;
    ClapTrap third("Third");
    third = original; // qui deve stampare "ClapTrap Copy assignment operator called"
    third.attack("Test Dummy");

    std::cout << "\nEnd of Program (Destructors)" << std::endl;
    return 0;
}

