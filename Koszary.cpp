#include "Koszary.h"



Koszary::Koszary()
{
	poziom = 1;
	koszt = 300;
}


Koszary::~Koszary()
{
}
void Koszary::ZwiekszPoziom()
{
	++poziom;
	koszt += 200;
}
int Koszary::getlevel()
{
	return poziom;
}
int Koszary::getprice()
{
	return koszt;
}
