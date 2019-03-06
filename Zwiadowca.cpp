#include "Zwiadowca.h"



Zwiadowca::Zwiadowca()
{
	ilosc = 0;
	koszt = 80;
}

int Zwiadowca::getpower() { return atak*ilosc; }
int Zwiadowca::getilosc() { return ilosc; }
int Zwiadowca::getdefense() { return obrona*ilosc; }
void Zwiadowca::setilosc(int tmp) { this->ilosc += tmp; }
void Zwiadowca::afterbattle(int tmp) { ilosc *= tmp; }
Zwiadowca::~Zwiadowca()
{
}
