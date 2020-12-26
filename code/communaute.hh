#include <cstdlib>
#include <string>
#include <iostream>
#include <random>
#include <vector>
#include "equipement.hh"
#include "survivant.hh"

class communaute
{
public:
	communaute(std::string Nom);
	~communaute();
	// Getters
	std::string getNom() const { return this -> c_nom;}
	int getJourSurvecus() const { return this -> jourSurvecus;}
	int getNbNourriture() const { return this -> nbNourriture;}
	int getNbEau() const { return this -> nbEau;}
	int getNbMedicaments() const { return this -> nbMedicaments;}
	int getNbJardins() const { return this -> nbJardins;}
	// Surcharge
	// Methodes
	void ajouterMembre();
	void resumeInfos() const;
	void EnvoyerChercherDesVivres(survivant & s, equipement & e);
	void FaireConstruire(survivant & s, equipement & e);
	void Soigner(survivant & soigneur, survivant & cible);
	void ActionsRestantes() const; // return s travaille FALSE
	void FinirJour();
private:
	std::string c_nom;
	int jourSurvecus;
	int nbNourriture;
	int nbEau;
	int nbMedicaments;
	int nbJardins;
	std::vector<survivant> membres;
	std::vector<survivant> equipements;
	/*vector<survivant *> listeSurvivants;
	listeSurvivants.push_back(new survivant(arguments)); 
	SI PLUSIEURS TYPES DE SURVIVANTS PRATIQUE*/
};
