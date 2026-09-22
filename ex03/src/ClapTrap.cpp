/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilnassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 17:20:53 by ilnassi           #+#    #+#             */
/*   Updated: 2026/09/13 19:27:09 by ilnassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

//Costruttore di default
ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Default." << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " create!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name)
{
	std::cout << "ClapTrap copy." << std::endl;
	*this = other;
}

// Operatore di Assegnazione
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

//Distruttore
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destroy." << std::endl;
}

//funzione di attacco
void ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is dead!!" << std::endl;
		return;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " out of energy!" << std::endl;
		return;
	}
	this->_energyPoints -= 1;
	std::cout << "ClapTrap " << _name << " attacks " << target
		<< " causing " << _attackDamage << " damage." << std::endl;
}


//Ricezione danni
void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " already dead!" << std::endl;
		return;
	}
	if (amount >= this-> _hitPoints)
	{
		this->_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " takes " << amount 
			<< " points of damage and dies!" << std::endl;
	}
	else 
	{
		this->_hitPoints -= amount;
		std::cout << "ClapTrap " << _name << " takes " << amount
			<< " point of damage! HP now: " << this->_hitPoints << std::endl;
	}
}

// Riparazione
void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hitPoints == 0) 
    {
        std::cout << "ClapTrap " << _name << " cannot repair itself... is dead!" << std::endl;
        return;
    }
    if (this->_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " out of energy to repair itself!" << std::endl;
        return;
    }
    this->_energyPoints -= 1;
    this->_hitPoints += amount;
    std::cout << "ClapTrap " << _name << " repairs itself, regaining " << amount 
              << " hit points! Current HP: " << this->_hitPoints << std::endl;
}
