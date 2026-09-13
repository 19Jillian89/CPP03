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

int	main()
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
    for (int i = 0; i < 11; i++) {
        tiredBoy.attack("un muro");
    }

    std::cout << "\nEnd of Program (Destructors)" << std::endl;
    return 0;
}
