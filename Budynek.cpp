#include "Budynek.h"

Budynek::Budynek() {}

Budynek::Budynek(int poziom, int koszt)
{
	this->poziom = poziom;
	this->koszt = koszt;
}


Budynek::~Budynek()
{
}
void Budynek::ZwiekszPoziom(int priceup)
{
	poziom++;
	koszt += priceup;
}
int Budynek::getlevel()
{
	return poziom;
}
int Budynek::getprice()
{
	return koszt;
}
void Budynek::setall(int poziom, int koszt)
{
	this->poziom = poziom;
	this->koszt = koszt;
}