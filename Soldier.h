#pragma once
class Soldier
{
protected:
	int atak;
	int obrona;
	int plecak;
	int ilosc;
	int koszt;
public:
	Soldier();
	~Soldier();
	virtual int getpower()=0;
	virtual int getilosc() = 0;
	virtual int getdefense() = 0;
	virtual void setilosc(int) = 0;
	virtual void afterbattle(int)=0;
};

