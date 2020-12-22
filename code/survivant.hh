#include <cstdlib>
#include <string>
#include <iostream>
#include <random>
//#include "communaute.hh"

class survivant
{
public:
	survivant(string nom);
	survivant(const survivant & s); //copy
	~survivant();
	// Getters
	string getNom();
	bool getEtatSante();
	bool getTravail();
	// Surcharge
	// Methodes
private:
	string Nom;
	bool estMalade;
	bool Travaille;
};