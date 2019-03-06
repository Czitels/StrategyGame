#include "Kopalnia.h"



Kopalnia::Kopalnia()
{
	poziom = 1;
	koszt = 250;
}


Kopalnia::~Kopalnia()
{
}
void Kopalnia::ZwiekszPoziom()
{
	++poziom;
	koszt += 150;
}
int Kopalnia::getlevel()
{
	return poziom;
}
int Kopalnia::getprice()
{
	return koszt;
}
