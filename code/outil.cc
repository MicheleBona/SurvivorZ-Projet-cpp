#include "outil.hh"

outil::outil(): equipement(), o_durabilite(0)
{

}

outil::outil(int durabilite): equipement(), o_durabilite(durabilite)
{

}

outil::~outil()
{

}

outil::outil(const outil & o)
{
	o_durabilite = o.o_durabilite;
}

int outil::AdditionerDura(outil const& b)
{
	return o_durabilite + b.o_durabilite;
}

outil& outil::operator+=(const outil & b)
{
	o_durabilite += b.o_durabilite;
	return *this;
}

outil& outil::operator=(const outil & copy)
{
	if(this != &copy)
    //On vérifie que l'objet n'est pas le même que celui reçu en argument
	{
        o_durabilite = copy.o_durabilite;
    }
    return *this; //On renvoie l'objet lui-même
}

outil operator+(const outil &a,outil const& b)
{
	outil resultat = outil(a);
	resultat += b;
	return resultat;
}