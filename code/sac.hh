#include "contenant.hh"
#pragma once
class sac : public contenant
{
public:
	sac();
	~sac();
	std::string getNom() const { return this -> Nom;}
	int getContenance();
	bool getPossede();
	void jaiQuoi() const; //masquage qui présente chaque equipement
private:
	std::string Nom;
	
};