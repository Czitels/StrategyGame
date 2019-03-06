#pragma once
class Budynek
{
protected:
	int poziom;
	int koszt;
public:
	Budynek(int, int);
	Budynek();
	~Budynek();
	void ZwiekszPoziom(int);
	int getlevel();
	int getprice();
	void setall(int, int);
};

