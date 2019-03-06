#include "Topornik.h"



Topornik::Topornik()
{
	atak = 40;
	obrona = 10;
	plecak = 10;
	ilosc = 0;
	koszt = 40;
}

int Topornik::getpower() { return atak*ilosc; }
int Topornik::getilosc() { return ilosc; }
int Topornik::getdefense() { return obrona*ilosc; }
void Topornik::setilosc(int tmp) { this->ilosc += tmp; }
void Topornik::afterbattle(int tmp) { ilosc *= tmp; }
Topornik::~Topornik()
{
}
