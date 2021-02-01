#include "survivant.hh"

survivant::survivant() : estMalade(false), estBusy(false)
{

}

survivant::survivant(bool malade)
{
	estMalade = malade;
	if (estMalade)
		estBusy = true;
}

survivant::survivant(const survivant & s)
{
	estMalade = s.estMalade;
	estBusy = s.estBusy;
}

survivant::~survivant()
{

}

void survivant::setBusy(bool busy)
{
	estBusy = busy;
}