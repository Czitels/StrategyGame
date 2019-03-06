#include "Pikinier.h"



Pikinier::Pikinier()
{
	atak = 10;
	obrona = 10;
	plecak = 50;
	ilosc = 5;
	koszt = 20;
}

int Pikinier::getpower() { return atak*ilosc; }
int Pikinier::getdefense() { return obrona*ilosc; }
int Pikinier::getilosc() { return ilosc; }
void Pikinier::setilosc(int tmp) { this->ilosc += tmp; }
void Pikinier::afterbattle(int tmp) { ilosc *= tmp; }
Pikinier::~Pikinier()
{
}
