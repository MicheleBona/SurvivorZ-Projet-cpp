#include "equipement.hh"
#pragma once
class outil : public equipement
{
public:
	outil();
	outil(int durabilite);
	outil(const outil & o); 
	~outil();
	int getDurabilite() const { return this -> o_durabilite;}
	int AdditionerDura(const outil & b);
	friend outil operator+(const outil &a,const outil & b);
	outil& operator=(const outil & copy);
	outil& operator+=(const outil & b);

	void jaiQuoi() const; //masquage qui présente chaque equipement
private:
	int o_durabilite;
};