# CPP03 
 
Questo modulo introduce l'ereditarietà in C++: si parte da una classe base semplice (`ClapTrap`) e nei successivi esercizi si costruiscono classi derivate (`ScavTrap`, `FragTrap`) e infine ereditarietà multipla (`DiamondTrap`).
 
Regole generali del modulo, valide per tutti gli esercizi:
 
- Compilazione con `c++ -Wall -Wextra -Werror`, compatibile con `-std=c++98`.
- Ogni classe deve implementare la **Orthodox Canonical Form**: costruttore di default, costruttore di copia, operatore di assegnazione per copia, distruttore.
- Ogni header ha bisogno dei propri include guard e deve essere utilizzabile in isolamento.
- Vietato usare STL (container/algoritmi) fino ai moduli 08/09.
- Ogni metodo deve stampare un messaggio che descrive cosa sta succedendo — è il modo in cui i peer evaluator verificano che la logica funzioni.
## L'ereditarietà in C++
 
**Definizione formale:** l'ereditarietà è un meccanismo che permette a una classe (detta *derivata* o *figlia*) di riutilizzare attributi e metodi di un'altra classe (detta *base* o *madre*), estendendola o specializzandola senza riscrivere da zero il codice già esistente. La classe derivata eredita tutto ciò che la base espone (public/protected), e può aggiungere nuovi attributi/metodi o ridefinire (override) quelli ereditati.
 
In C++ si dichiara così:
 
```cpp
class ScavTrap : public ClapTrap
{
	// ScavTrap ha già _name, _hitPoints, _energyPoints, _attackDamage
	// e i metodi attack(), takeDamage(), beRepaired() di ClapTrap
	public:
		void guardGate(); // metodo nuovo, solo suo
};
```
 
**Analogia:** pensa all'ereditarietà come a una ricetta base e le sue varianti. Hai la "ricetta madre" della pasta al pomodoro (ClapTrap): ingredienti base, procedimento base. ScavTrap è una variante — "pasta al pomodoro piccante": parte dalla stessa base (eredita gli ingredienti/procedimento), ma aggiunge qualcosa di suo (il peperoncino = `guardGate()`) e magari cambia le dosi di un ingrediente esistente (hit points 100 invece di 10). Non riscrivi la ricetta da zero, la estendi.
 
**Concetti chiave:**
 
1. **Costruzione a catena**: quando crei uno ScavTrap, C++ costruisce *prima* la parte ClapTrap (la base), *poi* la parte ScavTrap — non puoi specializzare qualcosa che non esiste ancora. La distruzione avviene in ordine inverso: prima la parte ScavTrap, poi quella ClapTrap, come togliere gli strati di una cipolla nell'ordine opposto in cui li hai messi.
2. **`public` nell'ereditarietà** (`class ScavTrap : public ClapTrap`): specifica come i membri `public`/`protected` della base restano visibili nella classe derivata. Con `public` (il caso quasi sempre usato in questo modulo), un `public` di ClapTrap resta `public` in ScavTrap.
3. **Attributi `private` vs `protected`**: se `_hitPoints` in ClapTrap è `private`, ScavTrap *non può accedervi direttamente*, nemmeno essendo sua figlia. Per permettere alle classi derivate di modificare gli attributi ereditati (come richiesto quando ScavTrap deve inizializzarli a valori diversi), spesso si cambia la visibilità in ClapTrap da `private` a `protected` — cioè "visibile alla classe stessa e alle sue classi derivate, ma non dall'esterno".
4. **Override**: ScavTrap ridefinisce `attack()` con un messaggio diverso — la firma resta identica, ma il comportamento (o solo il testo stampato) cambia rispetto alla versione di ClapTrap.
