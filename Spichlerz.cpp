#include "Spichlerz.h"



Spichlerz::Spichlerz()
{
	poziom = 1;
	koszt = 200;
}


Spichlerz::~Spichlerz()
{
}
void Spichlerz::ZwiekszPoziom()
{
	++poziom;
	koszt += 100;
}
int Spichlerz::getlevel()
{
	return poziom;
}
int Spichlerz::getprice()
{
	return koszt;
}