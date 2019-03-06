#include "Ratusz.h"



Ratusz::Ratusz()
{
	poziom = 1;
	koszt = 500;
}


Ratusz::~Ratusz()
{
}
void Ratusz::ZwiekszPoziom()
{
	++poziom;
	koszt = koszt * 2;
}
int Ratusz::getlevel()
{
	return poziom;
}
int Ratusz::getprice()
{
	return koszt;
}