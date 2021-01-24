#include "communaute.hh"
using namespace std;


communaute::communaute(string Nom) //constructeur de la commu mode normal
{
	c_nom = Nom;
	perdu = false;
	jourSurvecus=0;
	nbNourriture=5;
	nbEau=5;
	nbMedicaments=0;
	nbJardins=0;
	nbCouchages=0;
	for (int i; i<3; i++){
		membres.push_back(survivant());
	srand (time(NULL)); //seed pour le rand (proba de trouver de l'equipement)
	equipements.push_back(equipement());
	}
}

communaute::~communaute()
{
	membres.clear();
	// FOR ... delete equipement SI je fais des pointeurs
	equipements.clear();
}

survivant & communaute::getSurvivant(int num)
{
	return membres[num];
}

void communaute::ajouterMembre() 
{
	membres.push_back(survivant());
}

void communaute::resumeInfos() const
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~INFOS~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Le nom de la communaute est : " << getNom() << endl;
	cout << "Elle a survécu : " << getJourSurvecus() << " jours..." << endl;
	cout << "Il reste " << nbNourriture << " de nourriture..." << endl;
	cout << "Il reste " << nbEau << " d'eau..." << endl;
	cout << "Il reste " << nbMedicaments << " de médicaments..." << endl;
	cout << "Il y a " << nbCouchages << " couchages." << endl;
	cout << "Il y a " << membres.size() << " survivants." << endl;
	// print les malades
	bool pasDeMalades = true;
	for (int i=0; i<membres.size(); i++)
	{
		if (i==0){
			if (membres[i].getEtatSante() == true) 
			{
				cout << "Le premier survivant est malade... " << endl;
				pasDeMalades = false;
			}
		}
		else
		{
			if (membres[i].getEtatSante() == true) 
			{
				cout << "Le "<< i+1 << "eme survivant est malade... " << endl;
				pasDeMalades = false;
			}
		}
	}
	if (pasDeMalades)
	{
		cout << "Personne n'est malade!" << endl;
	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~~INFOS~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

void communaute::afficheNomJour(ostream &flux) const
{
    flux << c_nom << " a survécu "  << jourSurvecus << " jours." << endl;
}

ostream& operator<<( ostream &flux, communaute const& c )
{
    c.afficheNomJour(flux);
    return flux;
}


void communaute::EnvoyerChercherDesVivres(survivant & s, equipement & e)
{
	if (s.getBusy()==false)
	{
		// le survivant travail aujourdhui
		s.setBusy(true);
		// systeme de proba en fonction des jours survécu...
		int probaVivres=50;
		int probaMeds=5;
		// combien apportera t il de vivres ?
		int nourriture=0;
		int eau=0;
		int meds=0;
		for (int i=0; i<5; i++) // 5 chances de ramener chaque vivre
		{
			if ((rand() % 100) < probaVivres) // chance de ramener chaque vivre 1 fois
			{
				nourriture++;
			}
			if ((rand() % 100) < probaVivres) // chance de ramener chaque vivre 1 fois
			{
				eau++;
			}
			if ((rand() % 100) < probaMeds) // chance de ramener un médicament 
			{
				meds++;
			}
		}
		//TOTAL
		cout << "Le survivant a ramené:" << endl;
		cout << " - " << nourriture << " de nourriture" << endl;
		cout << " - " << eau << " d'eau" << endl;
		cout << " - " << meds << " médicaments" << endl;
		nbNourriture = nbNourriture + nourriture;
		nbEau = nbEau + eau;
		nbMedicaments = nbMedicaments + meds;
	}
	else cout << "Ce survivant est déjà occupé..." << endl;
}

void communaute::EnvoyerChercherSurvivants(survivant & s)
{
	if (s.getBusy()==false) // on vérifie que le survivant qui effectue l'action n'est pas occupé
	{
		s.setBusy(true); // il devient occupé
		membres.push_back(survivant(true)); // il amène un survivant mais malade car survivre tout seul c'est dur ;)
		cout << "Un nouveau survivant rejoint la communauté mais il est malade..." << endl;
	}
}

void communaute::FaireConstruire(survivant & s, equipement & e)
{
	if (s.getBusy()==false)
	{
		//if marteau -> maison/cabane
		// construit tente
		nbCouchages = nbCouchages + 2;
		s.setBusy(true);
		cout << "Une tente a été construite! 2 personnes de plus auront un abri." << endl;
	}
}

void communaute::etatDeSanteCommu() const
{
	for (int i=0; i<membres.size(); i++)
	{
		if (i==0){
			if (membres[i].getEtatSante() == false) 
			{
				cout << "Le premier survivant est en bonne santé! " << endl;
			}
			else 
			{
				cout << "Le premier survivant est malade... " << endl;
			}
		}
		else
		{
			if (membres[i].getEtatSante() == false) 
			{
				cout << "Le "<< i+1 <<"eme survivant est en bonne santé! " << endl;
			}
			else 
			{
				cout << "Le "<< i+1 << "eme survivant est malade... " << endl;
			}
		}
	}
}

void communaute::Soigner(survivant & soigneur, survivant & cible)
{
	if (nbMedicaments>0)
	{
		etatDeSanteCommu();
		if (cible.getEtatSante() == true)
		{
			cible.devientGueri();
			cible.setBusy(false);
			nbMedicaments--;
			soigneur.setBusy(true);
			cout << "Le survivant a été soigné!" << endl;
		}
	}
	else
		cout << "Vous n'avez pas de médicaments vous ne pouvez soigner personne..." << endl;
}

void communaute::PrintActionsRestantes() const
{
	int compteur=0;
	std::vector<int> Faineants;
	for (int i=0; i<membres.size(); i++)
	{
		if (membres[i].getBusy() == false) 
		{
			Faineants.push_back(i);
			compteur++;
		}
	}
	if (compteur==0)
	{
		cout << "C'est bon! Tout le monde a quelque chose à faire." << endl;
	}
	else
	{
		cout << compteur << " survivants n'ont rien a faire..."<< endl;
		cout << "Il sagit des numéros: ";
		for (int i=0; i<Faineants.size(); i++)
		{
			cout << Faineants[i]+1 << " ";
		}
		cout << endl;
	}
}

bool communaute::ActionsRestantes() const
{
	int compteur=0;
	for (int i=0; i<membres.size(); i++)
	{
		if (membres[i].getBusy() == false) 
		{
			compteur++;
			break;
		}
	}
	if (compteur==0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
void communaute::ChoisirActionsSurvivants()
{
	
	for (int i=0; i<membres.size(); i++)
	{
		/*if (membres[i].getEtatSante())
		{
			cout << "Le survivant n°" << i+1 << " est malade il ne peut pas travailler..." << endl;
		}*/
		if (membres[i].getBusy())
		{
			cout << "Le survivant n°" << i+1 << " est déjà occupé..." << endl;
		}
		else 
		{
			char action;
			cout << "Choisissez l'action du survivant n°" << i+1 << " en tapant la lettre correspondante dans le terminal" << endl;
			cout << "\t v = Envoyer chercher des vivres" << endl;
			cout << "\t c = Faire construire un abri" << endl;
			cout << "\t s = Envoyer chercher d'autres survivants" << endl;
			cout << "\t h = Soigner un autre survivant malade" << endl;
			cin >> action;
			switch (action)
			{
				case 'v':
					EnvoyerChercherDesVivres(membres[i], equipements[0]);
				break;
				case 'c':
					FaireConstruire(membres[i], equipements[0]);
				break;
				case 's':
					EnvoyerChercherSurvivants(membres[i]);
				break;
				case 'h':
					int cible;
					cout << "Soigner qui ? Ecrire son numéro:" << endl;
					cin >> cible;
					Soigner(membres[i], membres[cible-1]);
				break;
				default:
				cout << "Tapez une des lettres pour faire l'action..." << endl;
			}
		}
		
	}
}

void communaute::JouerXtours(int x)
{
	for (int j=0; j<x ; j++)
	{
		for (int i=0; i<membres.size(); i++)
		{
			EnvoyerChercherDesVivres(membres[i], equipements[0]);
		}
		FinirJour();
	}
	cout << x << " jours sont passés!" << endl;
	
}


void communaute::FinirJour()
{
	// verifions que tout le monde a quelque chose à faire
	if (!ActionsRestantes())
	{
		// mise à jour des ressources
		nbNourriture = nbNourriture - membres.size();
		nbEau = nbEau - membres.size();

		// si il n'y a pas assez de nourriture pour tout le monde
		if (nbNourriture<0 || nbEau<0)
		{
			int negatif = -min(nbNourriture,nbEau); // on pose le manque à combler plus grand (entre eau et nourriture)
			for (int i=0; i<negatif; i++) // un nombre de survivant egal au manque à combler meurt 
			{
				if (membres.size()>0) // si il reste des survivants à faire mourir
				{
					membres.pop_back(); // survivant tué = enlevé du vector des membres de la communauté
					nbNourriture++; // on récupère ainsi les vivres qu'ils auraient couté
					nbEau++;
				}
				if (membres.size()==0) 
				{
					perdu = true;
				}
			}
		}

		if (!perdu) // si la communauté a survécu un jour de plus
		{
			jourSurvecus++;
			// les survivants qui dorment à la belle étoile deviennent malades 
			if (nbCouchages<membres.size())
			{
				int n = membres.size() - nbCouchages;
				int i = 0;
				int compteur = 0;
				// les survivants malades ont priorité pour les abris (si il n'y a toujours pas assez d'abri un AUTRE survivant tombera malade)
				while (compteur < n)
				{
					if (i < membres.size())
					{
						if (membres[i].getEtatSante() == false)
						{
							membres[i].devientMalade();
							compteur++;
						}
					}
					else break; // tous le monde est malade, la partie va finir quand il n'y aura plus de vivres...
					i++;
				}
			}
			// mise en place du nouveau jour
			for (int i=0; i<membres.size(); i++)
			{
				// si il est pas malade il est de nouveau disponible
				if (membres[i].getEtatSante() == false) 
				{
					membres[i].setBusy(false);
				}
			}
			cout << "Un nouveau jour se lève sur " << c_nom << "..." << endl;
			resumeInfos();
		}
		else // il n'y a plus de survivants
		{
			cout << "Tous les survivants sont mort, la partie est terminée..." << endl;
			afficheNomJour(cout);
		}
	}
	else // si tout le monde n'a pas quelque chose à faire
	{
		cout << "Tout le monde n'a pas quelque chose à faire..." << endl;
	}
}