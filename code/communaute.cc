#include "communaute.hh"
using namespace std;


communaute::communaute(string Nom) //constructeur de la commu mode normal
{
	c_nom = Nom;
	jourSurvecus=0;
	nbNourriture=5;
	nbEau=5;
	nbMedicaments=0;
	nbJardins=0;
	membres.push_back(survivant());
	survivant s_test = survivant();
	s_test.devientMalade();
	membres.push_back(s_test);
}

communaute::~communaute()
{
	membres.clear();
}

void communaute::ajouterMembre() 
{
	membres.push_back(survivant());
}

void communaute::resumeInfos() const
{
	cout << " Le nom de la communaute est : " << getNom() << endl;
	cout << " Elle a survécu : " << getJourSurvecus() << " jours..." << endl;
	cout << " Il reste " << nbNourriture << " de nourriture..." << endl;
	cout << " Il reste " << nbEau << " d'eau..." << endl;
	cout << " Il reste " << nbMedicaments << " de médicaments..." << endl; ;
	for (int i=0; i<membres.size(); i++)
	{
		if (membres[i].getEtatSante() == false) 
		{
			cout << " Le premier survivant est en bonne santé! " << endl;
		}
		else 
		{
			cout << " Le premier survivant est malade... " << endl;
		}
	}
}

void communaute::Soigner(survivant & soigneur, survivant & cible)
{
	if (nbMedicaments>0)
	{
		if (cible.getEtatSante() == true)
		{
			cible.devientGueri();
			nbMedicaments--;
			soigneur.devientBusy();
		}
	}
}

