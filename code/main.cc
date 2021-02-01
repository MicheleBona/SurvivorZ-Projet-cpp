#include <iostream>
#include <fstream>
#include "communaute.hh"
#include "equipement.hh"
#include "outil.hh"
#include "contenant.hh"
#include "sac.hh"
#include <unistd.h>


using namespace std;
void ReglesJeu();
int DebutJeu();
int TourDeJeu(communaute & c);

void ReglesJeu()
{
	cout << "Le but du jeu est de faire prospérer sa communauté de survivants." << endl;
	cout << "Pour ce faire vous devrez récolter de la nourriture, de l'eau et construire des abris afin que chaque survivant de la communauté tienne un jour de plus!" << endl;
	cout << "Vous pouvez chaque jour faire faire une action à un survivant: " << endl;
	cout << "\t v = Envoyer chercher des vivres; le survivant ramenera de la nourriture, de l'eau et, eventuellement, des médicaments (plus rares)." << endl;
	cout << "\t c = Faire construire un abri" << endl;
	cout << "\t s = Envoyer chercher d'autres survivants." << endl;
	cout << "\t h = Soigner un autre survivant malade." << endl;
	cout << "Dès que chaque survivant a une action à faire vous pourrez passez au jour suivant! Mais attention il faut que tout le monde est " ;
	cout << "assez à manger et à boire, mais aussi que tout le monde est un abri sur sa tête pour dormir sinon le malchanceux qui dort à la belle étoile tombe malade ";
	cout << "(un survivant malade ne plus faire d'actions)."<< endl;
	//EXPLIQUER EQUIPEMENTS
	cout << "Bonne chance! :)" << endl;

}
int DebutJeu()
{
	string nomCommu;
	cout << "Bienvenue dans SurvivorZ! Essayez de survivre à l'apocalypse Zombie..." << endl;
	ReglesJeu();
	cout << endl;
	cout << "Veuillez tout d'abord entrer le nom de votre communauté de survivants:" << endl;
	getline(std::cin, nomCommu);
	communaute joueur = communaute(nomCommu);
	usleep(300000);//sleeps for 0.3 second
	cout << "Voici les informations concernant votre communauté:" << endl;
	joueur.resumeInfos();
	usleep(300000);//sleeps for 0.3 second
	joueur.ActionsRestantes();
	usleep(1000000);//sleeps for 1 second
	
	cout << joueur;
	TourDeJeu(joueur);
	
	return 0;
}

int TourDeJeu(communaute & c)
{
	int nb=0;
	bool pasFini = true;
	char action;
	while (pasFini)
	{
		char action;
		cout << "~~~~~~~~~~~~~~~~~~~~TOUR-DE-JEU~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Que voulez-vous faire:" << endl;
		cout << "\t i = Infos sur ma communauté" << endl;
		cout << "\t a = Faire faire des actions à mes survivants" << endl;
		cout << "\t z = Faire chercher des vivres à tout le monde pour X tours" << endl; // METTRE INVENTAIRE
		cout << "\t e = Voir l'état de santé de ma communauté" << endl;
		cout << "\t r = Voir les survivants qui n'ont rien à faire" << endl;
		cout << "\t t = Terminer la journée" << endl;
		cout << "\t s = Sortir du jeu..." << endl;
		
		cin >> action;
		cout << "~~~~~~~~~~~~~~~~~~~~TOUR-DE-JEU~~~~~~~~~~~~~~~~~~~~" << endl;
		usleep(500000);//sleeps for 1/2 second
		// switch pour actions différentes
		switch(action){
			case 'i':
			c.resumeInfos();
			usleep(500000);//sleeps for 1/2 second
			break;
			case 'a':
			c.ChoisirActionsSurvivants();
			break;
			case 'z':
			cout << "Combien de jours voulez-vous passer ? (tous les survivants iront chercher des vivres chaque jour)" << endl;
			cin >> nb;
			while (!cin.good())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Veuillez entrer un int..." << endl;
				cin >> nb;
			}
			c.JouerXtours(nb);
			break;
			case 'e':
			c.etatDeSanteCommu();
			break;
			case 'r':
			c.PrintActionsRestantes();
			break;
			case 't':
			c.FinirJour();
			pasFini = !c.getPerdu();
			break;
			case 's':
			cout << c;
			return 0;
			break;
			default:
		    cout << "Tapez une des lettres pour faire l'action..." << endl;
		}
	}
	cout << "Merci d'avoir joué!" << endl;
	return 0;
}

int main(){

	
	unsigned int microsecond = 1000000;
	DebutJeu();

	return 0;
}
