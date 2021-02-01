#include <cstdlib>
#include <string>
#include <iostream>
#include <random>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "equipement.hh"
#include "survivant.hh"

class communaute
{
public:
	communaute(std::string Nom);
	~communaute();
	// Getters
	std::string getNom() const { return this -> c_nom;}
	bool getPerdu() const { return this -> perdu;}
	int getJourSurvecus() const { return this -> jourSurvecus;}
	int getNbNourriture() const { return this -> nbNourriture;}
	int getNbEau() const { return this -> nbEau;}
	int getNbMedicaments() const { return this -> nbMedicaments;}
	int getNbJardins() const { return this -> nbJardins;}
	int getNbCouchages() const { return this -> nbCouchages;}
	survivant & getSurvivant(int num);
	// Surcharge
	void afficheNomJour(std::ostream &flux) const; // affiche le nombre de jours qu'a survécu la commu
	friend std::ostream& operator<<(std::ostream &flux, communaute const& c); // surcharge de l'opérateur <<
	// Methodes d'actions
	void EnvoyerChercherDesVivres(survivant & s, equipement & e); // surcharger fonction pour quand pas d'equip
	void EnvoyerChercherSurvivants(survivant & s); // amene survivant mais malade, equipement radio ? -> pas malade
	void FaireConstruire(survivant & s, equipement & e); // permet de construire des abris (et des jardins mais pas eu le temps)
	void Soigner(survivant & soigneur, survivant & cible); // permet de faire soigner un survivant par un autre
	// Methodes d'infos
	void resumeInfos() const; // gros print de toutes les infos sur la commu
	void etatDeSanteCommu() const; // affiche l'état de santé de chaque membre
	void PrintActionsRestantes() const; // affiche les membres qui ne font rien
	bool ActionsRestantes() const; // return si il reste des membres qui ne font rien (sert pour FinirJour)
	// Methodes de jeu
	void ChoisirActionsSurvivants(); // Permet de faire faire un action à tous les survivants
	void FinirJour();
	void JouerXtours(int x); // permet d'automatiser X tours si on pense que la communauté tiendra
private:
	std::string c_nom;
	bool perdu; // nous permettra de savoir si la communauté est encore en vie
	int jourSurvecus;
	int nbNourriture;
	int nbEau;
	int nbMedicaments;
	int nbJardins;
	int nbCouchages;
	std::vector<survivant> membres; // les survivants de la commu
	std::vector<equipement> equipements; // les equipements de la commu 

	void ajouterMembre();
};