/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilnassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 13:59:04 by ilnassi           #+#    #+#             */
/*   Updated: 2026/09/22 14:00:09 by ilnassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap(), _name("Default")
{
	this->_hitPoints = 100;      // Stato nativo di FragTrap
	this->_energyPoints = 50;    // Stato nativo di ScavTrap
	this->_attackDamage = 30;    // Stato nativo di FragTrap
	std::cout << "DiamondTrap Default constructor called" << std::endl;
}

// Costruttore con Nome (Mancava nel tuo file)
DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	this->_hitPoints = 100;       // Da FragTrap
	this->_energyPoints = 50;     // Da ScavTrap
	this->_attackDamage = 30;     // Da FragTrap
	std::cout << "DiamondTrap " << this->_name << " has risen!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name)
{
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	std::cout << "DiamondTrap Copy constructor called for " << this->_name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	if (this != &other) 
	{
		this->_name = other._name;
		this->ClapTrap::_name = other.ClapTrap::_name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " destroyed." << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am DiamondTrap [ " << this->_name  << " ] and my ClapTrap name is [ " << this->ClapTrap::_name << " ]" << std::endl;
}
