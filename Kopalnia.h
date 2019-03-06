#pragma once
#include "Budynek.h"
class Kopalnia :
	public Budynek
{
public:
	void ZwiekszPoziom();
	int getlevel();
	int getprice();
	Kopalnia();
	~Kopalnia();
};

