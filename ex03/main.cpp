/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilnassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 22:17:55 by ilnassi           #+#    #+#             */
/*   Updated: 2026/10/04 17:23:45 by ilnassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "=== 1. CREAZIONE PRIMO DIAMONDTRAP ===" << std::endl;
    DiamondTrap dippy("Dippy");
    dippy.whoAmI();

    std::cout << "\n=== 2. TEST DEL COSTRUTTORE DI COPIA ===" << std::endl;
    DiamondTrap dippyClone(dippy);
    std::cout << "[Verifica Clone]: ";
    dippyClone.whoAmI();
    dippyClone.attack("bersaglio di prova");

    std::cout << "\n=== 3. TEST DELL'OPERATORE DI ASSEGNAZIONE ===" << std::endl;
    DiamondTrap randomBot("Generico");
    randomBot = dippy;
    std::cout << "[Verifica dopo assegnazione]: ";
    randomBot.whoAmI();

    std::cout << "\n=== 4. TEST DELLE AZIONI E DEL MIX STATS ===" << std::endl;
    dippy.attack("un bersaglio nemico");
    dippy.guardGate();
    dippy.highFivesGuys();
    dippy.takeDamage(45);
    dippy.beRepaired(20);

    std::cout << "\n=== 5. DISTRUZIONE DEGLI OGGETTI ===" << std::endl;
    return 0;
}
