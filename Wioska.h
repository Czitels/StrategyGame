#pragma once
#include <iostream>
#include "Budynek.h"
#include "Soldier.h"
#include "Pikinier.h"
#include "Miecznik.h"
#include "Topornik.h"
#include "Zwiadowca.h"
using namespace std;
class Wioska
{
	friend void polegry();
	friend ostream & operator<<(ostream &out, Wioska& tmp);
	int MAX_ilosc;
	int iloscsurowcow;
	Budynek *Ratusz;//Start: 500
	Budynek *Koszary;//300
	Budynek *Spichlerz;//200
	Budynek *Kopalnia;//250
	Soldier *MojPikinier;
	Soldier *MojMiecznik;
	Soldier *MojTopornik;
	Soldier *MojZwiadowca;
	int VillagePower;
	int VillageDefense;
public:
	Wioska();
	~Wioska();
};

