#include "equipement.hh"
#pragma once
class contenant : public equipement // calsse abstraite encore
{
public:
	contenant();
	 ~contenant();
	 void jaiQuoi() const; //masquage qui présente chaque equipement
	 int getContenance();
	 std::string getNom();
protected: 
	int contenance; 
	// utilisé
	// typedef plutot que 2 classe sac et gourde ?
};