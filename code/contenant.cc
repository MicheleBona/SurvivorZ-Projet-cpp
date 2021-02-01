#include "contenant.hh"
using namespace std;

contenant::contenant(): contenance(2)
{

}

contenant::~contenant()
{

}

void contenant::jaiQuoi() const
{
	equipement::jaiQuoi();
	cout << "un contenant";
}