#pragma once
#include "Soldier.h"
class Pikinier :
	public Soldier
{
public:
	Pikinier();
	~Pikinier();
	int getpower();
	int getilosc();
	int getdefense();
	void setilosc(int);
	void afterbattle(int);
};

