## L'esercizio: ex00 — "Aaaaand... OPEN!"
 
Obiettivo: implementare una classe `ClapTrap` con:
 
**Attributi privati** (inizializzati nel costruttore):
- `_name` — nome del ClapTrap
- `_hitPoints` (10) — punti vita
- `_energyPoints` (10) — punti energia
- `_attackDamage` (0) — danno d'attacco
**Metodi pubblici:**
- `attack(const std::string& target)` — attacca un bersaglio, causando `_attackDamage` danni
- `takeDamage(unsigned int amount)` — subisce danno, perde `amount` punti vita
- `beRepaired(unsigned int amount)` — si ripara, recupera `amount` punti vita
**Vincoli di comportamento:**
- Attaccare e riparare consumano 1 punto energia ciascuno.
- Se il ClapTrap non ha più punti vita o punti energia, non può eseguire azioni.
## Svolgimento
 
### 1. Header (`ClapTrap.hpp`)
 
Si dichiara la struttura della classe: attributi privati e firme dei metodi pubblici, protetti da include guard (`#ifndef`/`#define`/`#endif`) per evitare doppie inclusioni.
 
```cpp
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
 
# include <string>
 
class ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
 
	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap();
 
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};
 
#endif
```
 
### 2. Costruttori, distruttore e Orthodox Canonical Form
 
Il soggetto richiede tutte e quattro le funzioni canoniche:
 
- **Costruttore di default**: crea un ClapTrap con valori generici ("Default").
- **Costruttore con nome**: crea un ClapTrap con un nome specifico, passato come parametro.
- **Costruttore di copia**: definisce cosa succede creando un oggetto a partire da un altro esistente (`ClapTrap b(a);`).
- **Operatore di assegnazione**: definisce cosa succede copiando i valori di un oggetto in un altro già esistente (`b = a;`).
```cpp
ClapTrap::ClapTrap()
	: _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Default." << std::endl;
}
 
ClapTrap::ClapTrap(const std::string& name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " create!" << std::endl;
}
 
ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name)
{
	std::cout << "ClapTrap copy." << std::endl;
	*this = other;
}
 
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}
 
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destroy." << std::endl;
}
```
 
### 3. `attack()`
 
Controlla che il ClapTrap abbia punti vita ed energia prima di agire; se sì, consuma 1 punto energia e stampa il messaggio di attacco.
 
```cpp
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
```
 
### 4. `takeDamage()`
 
Il punto delicato: `_hitPoints` è `unsigned int`, quindi non può mai diventare negativo. Se il danno subito è maggiore o uguale ai punti vita rimasti, `_hitPoints` va forzato a 0 invece di sottrarre direttamente (altrimenti si otterrebbe un underflow, cioè il valore "girerebbe" a un numero enorme vicino ai 4 miliardi).
 
```cpp
void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " already dead!" << std::endl;
		return;
	}
	if (amount >= this->_hitPoints)
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
```
 
### 5. `beRepaired()`
 
Stessa logica di controllo di `attack()`: niente vita o niente energia, niente riparazione. Consuma 1 punto energia e aumenta i punti vita.
 
```cpp
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
```
 
### 6. Test (`main.cpp`)
 
Il test copre i casi principali richiesti dal soggetto: creazione, attacco, riparazione, morte per danno, tentativo di agire da morto, esaurimento dell'energia, e ordine di distruzione.
 
```cpp
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
	trappy.takeDamage(10); // la uccide
	trappy.attack("Target Dummy"); // non funziona: è morta
	trappy.beRepaired(5);          // non funziona: è morta
 
	std::cout << "\n Energy Depletion " << std::endl;
	ClapTrap tiredBoy("Tired");
	for (int i = 0; i < 11; i++)
		tiredBoy.attack("un muro");
 
	std::cout << "\nEnd of Program (Destructors)" << std::endl;
	return 0;
}
```

## Output atteso (esempio)
 
```
Character creation
ClapTrap Clappy create!
ClapTrap Trappy create!
 
 Attack and Repair
ClapTrap Clappy attacks Target Dummy causing 0 damage.
ClapTrap Clappy repairs itself, regaining 5 hit points! Current HP: 15
 
 Sustain damage
ClapTrap Trappy takes 4 point of damage! HP now: 6
ClapTrap Trappy takes 10 points of damage and dies!
ClapTrap Trappy is dead!!
ClapTrap Trappy cannot repair itself... is dead!
 
 Energy Depletion
ClapTrap Tired create!
ClapTrap Tired attacks un muro causing 0 damage.
[... x10 ...]
ClapTrap Tired out of energy!
 
End of Program (Destructors)
ClapTrap Tired destroy.
ClapTrap Trappy destroy.
ClapTrap Clappy destroy.
```
 
Nota: `_attackDamage` di `ClapTrap` è 0 di default (è voluto dal soggetto) — il danno vero arriva nelle sottoclassi `ScavTrap` e `FragTrap` degli esercizi successivi. I distruttori vengono chiamati in ordine inverso rispetto alla creazione (LIFO), coerente con lo stack.
