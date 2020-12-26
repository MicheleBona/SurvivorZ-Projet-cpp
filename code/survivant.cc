#include "survivant.hh"

survivant::survivant() : estMalade(false), Busy(false)
{

}

/*survivant::survivant(bool malade) : Busy(false)
{
	estMalade = malade;
}*/

survivant::survivant(const survivant & s)
{
	estMalade = s.estMalade;
	Busy = s.Busy;
}

survivant::~survivant(){

}