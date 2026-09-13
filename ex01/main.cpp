/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilnassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 22:17:55 by ilnassi           #+#    #+#             */
/*   Updated: 2026/09/13 22:26:25 by ilnassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	std::cout << "Character creation" << std::endl;
	ScavTrap scavy("Scavy");

	std::cout << "\n Statistics and Attack " << std::endl;
	scavy.attack("enemy");

	std::cout << "\n Inherited Functions " << std::endl;
	scavy.takeDamage(50);
	scavy.beRepaired(22);

	std::cout << "\n Special Ability " << std::endl;
	scavy.guardGate();

	std::cout << "\n Destruction " << std::endl;
	return 0;
}
