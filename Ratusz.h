#pragma once
#include "Budynek.h"
class Ratusz :
	public Budynek
{
	const int MAX = 5;
public:
	Ratusz();
	~Ratusz();
	void ZwiekszPoziom();
	void ZwiekszKoszt();
	int getlevel();
	int getprice();
};

