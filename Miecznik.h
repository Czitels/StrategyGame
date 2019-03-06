#pragma once
#include "Soldier.h"
class Miecznik :
	public Soldier
{
public:
	Miecznik();
	~Miecznik();
	int getpower();
	int getilosc();
	int getdefense();
	void setilosc(int);
	void afterbattle(int);
};

