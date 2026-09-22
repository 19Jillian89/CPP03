/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilnassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 22:17:55 by ilnassi           #+#    #+#             */
/*   Updated: 2026/09/22 11:08:39 by ilnassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	std::cout << "Creation FragTrap" << std::endl;
	FragTrap fraggy("Fraggy");

	std::cout << "\n Statistics " << std::endl;
	
	//Use Claptrap's attack, but it will deal a full 30 base damage.
	fraggy.attack("a heavy target");
	fraggy.takeDamage(50);
	fraggy.beRepaired(20);

	std::cout << "\n Special ability " << std::endl;
	fraggy.highFivesGuys();

	std::cout << "\n Living with Scavtrap " << std::endl;
	{
		std::cout << "ScavTrap enters a local block " << std::endl;
        	ScavTrap scavguy("Scavguy");
        	scavguy.guardGate();
        	std::cout << "ScavTrap emerges from the block!" << std::endl;
	}

	std::cout << "\n FRAGTRAP DESTRUCTION " << std::endl;
	return 0;
}
