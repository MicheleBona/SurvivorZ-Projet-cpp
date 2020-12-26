#include <cstdlib>
#include <string>
#include <iostream>
#include <random>

class survivant
{
public:
	survivant();
	//survivant(bool malade);
	survivant(const survivant & s); //copy
	~survivant();
	// Getters
	bool getEtatSante() const { return this -> estMalade;}
	bool getBusy() const { return this -> estBusy;}
	// des setters plutot
	void devientBusy() {this -> estBusy = true;}
	void devientMalade() {this -> estMalade = true;}
	void devientGueri() {this -> estMalade = false;}
	// Surcharge
	// Methodes
private:
	//id ?
	bool estMalade;
	bool estBusy; // friens ou protected ?
};
