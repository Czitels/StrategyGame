#pragma once
#include "Soldier.h"
class Zwiadowca :
	public Soldier
{
public:
	Zwiadowca();
	~Zwiadowca();
	int getpower();
	int getilosc();
	int getdefense();
	void setilosc(int);
	void afterbattle(int);
};

