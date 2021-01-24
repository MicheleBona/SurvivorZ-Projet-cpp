#include "equipement.hh"
using namespace std;

equipement::equipement() : e_Possede(true)
{

}

equipement::equipement(bool poss) : e_Possede(poss)
{

}

equipement::~equipement()
{

}

void equipement::jaiQuoi() const
{
	if (e_Possede)
	{
		cout << "J'ai ";
	}
	else
	{
		cout << "Je n'ai pas ";
	}
}