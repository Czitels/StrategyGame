#pragma once
#include "Budynek.h"
class Koszary :
	public Budynek
{
	const int MAX = 8;
public:
	void ZwiekszPoziom();
	Koszary();
	~Koszary();
	int getlevel();
	int getprice();
};

