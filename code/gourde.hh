#include "contenant.hh"
#pragma once
class gourde : public contenant
{
public:
	gourde();
	~gourde();
	std::string getNom() const { return this -> Nom;}
	int getContenance();
	bool getPossede();
private:
	std::string Nom;
	void jaiQuoi() const; //masquage qui présente chaque equipement
};