#pragma once
#include "Soldier.h"
class Topornik :
	public Soldier
{
public:
	Topornik();
	~Topornik();
	int getpower();
	int getilosc();
	int getdefense();
	void setilosc(int);
	void afterbattle(int);
};

