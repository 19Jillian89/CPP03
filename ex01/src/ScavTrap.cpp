/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilnassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 21:55:47 by ilnassi           #+#    #+#             */
/*   Updated: 2026/09/13 22:17:34 by ilnassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//Costruttore default
ScavTrap::ScavTrap() : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "Default constructor called" << std::endl;
}

//Costruttore con nome
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	this->_hitPoints = 100;
        this->_energyPoints = 50;
        this->_attackDamage = 20;
        std::cout << "ScavTrap " << this->_name << " has been created!" << std::endl;
}

//Costruttore copia
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy called" << std::endl;
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap operator called" << std::endl;

	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

//Distruttore
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " has been destroyed." << std::endl;
}

//New Attack()
void	ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " cannot attack, is dead!" << std::endl;
		return;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ScavTrap " <<this->_name << " out of energy!" << std::endl;
		return;
	}
	this->_energyPoints -= 1;
	std::cout << "Scavtrap " << this->_name << " attack " << target 
		<< " dealing " << this->_attackDamage << "point of damage" << std::endl;
}

void	ScavTrap::guardGate()
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " cannot guard the gate because it is dead!" << std::endl;
        return;
	}
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}
