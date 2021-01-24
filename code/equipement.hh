#pragma once
#include <iostream>
#include <string>
// objet qui ne sera pas créé en soi mais ses filles oui
class equipement // peut etre classe abstraite, on aura pas d'objet equipement (pas réussi à l'implémenter)
{
public:
	equipement();
	equipement(bool poss);
	~equipement();
	bool getPossede();
	void jaiQuoi() const; //masquage qui présente chaque equipement
	std::string getNom();
protected: 
	bool e_Possede; 
};