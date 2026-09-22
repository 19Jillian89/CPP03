/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilnassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 10:49:16 by ilnassi           #+#    #+#             */
/*   Updated: 2026/09/22 10:52:47 by ilnassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//Default Constructor
FragTrap::FragTrap() : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap Default constructor called" << std::endl;
}

//Named Constructor
FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " enters the battlefield!" << std::endl;
}

//Copy Constructor
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) 
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = other;
}

//Assignment Operator
FragTrap& FragTrap::operator=(const FragTrap& other) 
{
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	if (this != &other) 
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap() 
{
	std::cout << "FragTrap " << this->_name << " has been decommissioned." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << ": \"Give me five, guys!\"" << std::endl;
}
