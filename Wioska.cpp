#include "Wioska.h"
#include <iostream>


Wioska::Wioska()
{
	iloscsurowcow = 500;
	Ratusz = new Budynek;
	Ratusz->setall(1, 500);
	Koszary = new Budynek;
	Koszary->setall(1, 300);
	Spichlerz = new Budynek;
	Spichlerz->setall(1, 200);
	Kopalnia = new Budynek;
	Kopalnia->setall(1, 250);
	MAX_ilosc = Spichlerz->getlevel() * 1000;
	MojPikinier = new Pikinier;
	MojMiecznik = new Miecznik;
	MojTopornik = new Topornik;
	MojZwiadowca = new Zwiadowca;
}


Wioska::~Wioska()
{
	delete Ratusz;
	delete Koszary;
	delete Spichlerz;
	delete Kopalnia;
	delete MojPikinier;
	delete MojMiecznik;
	delete MojTopornik;
	delete MojZwiadowca;
}
