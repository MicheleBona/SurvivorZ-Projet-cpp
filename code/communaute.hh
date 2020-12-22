#include <cstdlib>
#include <string>
#include <iostream>
#include <random>
#include "equipement.hh"
#include "survivant.hh"

class communaute
{
public:
	communaute(std::string nom);
	~communaute();
	// Getters
	std::string getNom() const { return this -> nom;}
	int getJourSurvecus() const { return this -> jourSurvecus;}
	int getNbNourriture() const { return this -> nbNourriture;}
	int getNbEau() const { return this -> nbEau;}
	int getNbMedicaments() const { return this -> nbMedicaments;}
	int getNbJardins() const { return this -> nbJardins;}
	// Surcharge
	// Methodes
	void resumeInfos();
	void EnvoyerChercherDesVivres(survivant & s, equipement & e);
	void FaireConstruire(survivant & s, equipement & e);
	void Soigner(survivant & soigneur, survivant & cible);
	void ActionsRestantes(); // return s travaille FALSE
	void FinirJour();
private:
	std::string nom;
	int jourSurvecus;
	int nbNourriture;
	int nbEau;
	int nbMedicaments;
	int nbJardins;
	//survivant * membres;
};