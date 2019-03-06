#pragma once
#include "Budynek.h"
class Spichlerz :
	public Budynek
{
public:
	Spichlerz();
	~Spichlerz();
	void ZwiekszPoziom();
	int getlevel();
	int getprice();
};

