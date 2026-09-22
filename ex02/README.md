## L'esercizio: ex02 — "Repetitive work"

Obiettivo: ripetere lo stesso pattern di ex01 per una nuova classe derivata, `FragTrap`, con valori e messaggi propri.

**Requisiti del soggetto:**
- FragTrap eredita da ClapTrap, con costruttori/distruttore propri.
- Attributi: hit points (100), energy points (100), attack damage (30).
- Nuova abilità: `void highFivesGuys(void);`, che stampa un messaggio positivo.
- `attack()` **non** viene ridefinito in FragTrap — usa direttamente quello ereditato da ClapTrap.

### FragTrap.hpp

```cpp
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& other);
		FragTrap& operator=(const FragTrap& other);
		~FragTrap();

		void highFivesGuys(void);
};

#endif
```

### FragTrap.cpp — punti chiave

Stesso pattern di ScavTrap: chiamata al costruttore di ClapTrap, poi override dei valori:

```cpp
FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " enters the battlefield!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "FragTrap " << this->_name << " wants to high five, but it's dead..." << std::endl;
		return;
	}
	std::cout << "FragTrap " << this->_name << ": \"Give me five, guys! High fives all around!\"" << std::endl;
}
```

### Perché `fraggy.attack()` infligge 30 danni senza che FragTrap ridefinisca `attack()`

Questo è il punto concettuale centrale dell'esercizio, ed è facile fraintenderlo come polimorfismo — non lo è, per lo stesso motivo spiegato sopra per ScavTrap.

`attack()` di FragTrap **è** `attack()` di ClapTrap: nessuna ridefinizione, nessuna funzione `virtual`, nessuna decisione a runtime. La funzione ereditata legge semplicemente l'attributo `_attackDamage`, e quell'attributo è stato sovrascritto a 30 nel costruttore di FragTrap. Cambia il dato che la funzione legge, non la funzione stessa.

**Analogia:** è come un unico distributore automatico (`attack()`) che eroga sempre "quello che c'è nello slot configurato" — se cambi cosa hai caricato nello slot (l'attributo `_attackDamage`), cambia cosa esce, ma il meccanismo del distributore resta identico, non "capisce" da solo che tipo di macchina è.

### Test: dimostrare il chaining con più classi derivate insieme

Un buon test per ex02 mette in scena sia FragTrap che ScavTrap nello stesso `main`, usando un blocco locale `{ }` per forzare la distruzione di uno dei due oggetti prima della fine del programma — così si vede chiaramente l'ordine LIFO (Last In, First Out) sia in costruzione che in distruzione:

```cpp
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::cout << "Creation FragTrap" << std::endl;
	FragTrap fraggy("Fraggy");

	std::cout << "\n Statistics " << std::endl;

	// Usa l'attack ereditato da ClapTrap, ma infligge 30 danni base.
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
```

Output atteso:

```
Creation FragTrap
ClapTrap Fraggy create!
FragTrap Fraggy enters the battlefield!

 Statistics
ClapTrap Fraggy attacks a heavy target causing 30 damage.
ClapTrap Fraggy takes 50 point of damage! HP now: 50
ClapTrap Fraggy repairs itself, regaining 20 hit points! Current HP: 70

 Special ability
FragTrap Fraggy: "Give me five, guys! High fives all around!"

 Living with Scavtrap
ScavTrap enters a local block
ClapTrap Scavguy create!
ScavTrap Scavguy has been created!
ScavTrap Scavguy is now in Gate keeper mode.
ScavTrap emerges from the block!
ScavTrap Scavguy has been destroyed.
ClapTrap Scavguy destroy.

 FRAGTRAP DESTRUCTION
FragTrap Fraggy has been decommissioned.
ClapTrap Fraggy destroy.
```

Da notare: `Scavguy`, creato ed entrato nel blocco `{ }` **dopo** `Fraggy`, viene distrutto **prima** di `Fraggy`, non appena il blocco si chiude — è l'ordine LIFO in azione anche tra oggetti di classi diverse, ognuno con la propria catena base→derivata rispettata.

### Struttura del progetto (ex01/ex02)

```
ex02/
├── includes/
│   ├── ClapTrap.hpp
│   ├── ScavTrap.hpp
│   └── FragTrap.hpp
├── src/
│   ├── ClapTrap.cpp
│   ├── ScavTrap.cpp
│   └── FragTrap.cpp
├── main.cpp
└── Makefile
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
