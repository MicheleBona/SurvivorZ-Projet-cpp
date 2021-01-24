#include <cstdlib>
#include <string>
#include <iostream>
#include <random>

class survivant
{
public:
	survivant();
	survivant(bool malade);
	survivant(const survivant & s); //copy
	~survivant();
	// Getters
	bool getEtatSante() const { return this -> estMalade;}
	bool getBusy() const { return this -> estBusy;}
	// Setters
	void setBusy(bool busy); 
	void devientBusy() {this -> estBusy = true;} // auraient du etre des setters mais c'était plus pratique quand je codais et j'ai plus le temps
	void devientMalade() {this -> estMalade = true;} // de changer partout...
	void devientGueri() {this -> estMalade = false;}
	// Methodes
	void etatMaladie(); // meurt si pas soigné (compteur vérifié chaque jour et incrementé) PAS IMPLÉMENTé
private:
	bool estMalade; // false = en bonne santé; true = malade
	bool estBusy; // false = pas occupé; true = occupé
};