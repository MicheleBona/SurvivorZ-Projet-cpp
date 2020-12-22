#include "communaute.hh"

using namespace std;

communaute::communaute(string Nom) //constructeur d'une commu
{
	nom = Nom;
	jourSurvecus=0;
	nbNourriture=5;
	nbEau=5;
	nbMedicaments=0;
	nbJardins=0;
}

void communaute::Soigner(survivant & soigneur, survivant & cible)
{
	if (nbMedicaments>0)
	{
		if (cible.getEtatSante() == TRUE)
		{
			cible.estMalade = FALSE;
			nbMedicaments--;
			soigneur.Travaille = TRUE;
		}
	}
}