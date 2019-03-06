#include "Miecznik.h"



Miecznik::Miecznik()
{
	atak = 10;
	obrona = 40;
	plecak = 10;
	ilosc = 0;
	koszt = 40;
}

int Miecznik::getpower() { return atak*ilosc; }
int Miecznik::getilosc() { return ilosc; }
int Miecznik::getdefense() { return obrona*ilosc; }
void Miecznik::setilosc(int tmp) { this->ilosc += tmp; }
void Miecznik::afterbattle(int tmp) { ilosc *= tmp; }
Miecznik::~Miecznik()
{
}
