#include <iostream>
#include "Wioska.h"
#include <conio.h>
#include <cstdlib>
#include <time.h>

using namespace std;

ostream & operator<<(ostream &out, Wioska &tmp);
void polegry();
void Interfejs2();
int main()
{
	srand(time(NULL));
	while (true)
	{
		cout << "MENU GLOWNE" << endl;
		cout << "1. Rozpocznij nowa gre" << endl;
		cout << "2. Zasady i specyfikacje zolnierzy" << endl;
		cout << "3. Zakoncz program" << endl << endl;
		char wybor;
		wybor = _getch();
		switch (wybor)
		{
		case '1':
		{
			polegry();
			break;
		}
		case '2':
		{
			cout << "15 tur. Ostatni atak wroga jest najwazniejszy.\nPikinier: atak 10, obrona 10. \nMiecznik: atak 10, obrona 40. \nTopornik: Atak 40, obrona 10. \nZwiadowca: Wieksza ilosc to pewny zwiad." << endl << endl;
			break;
		}
		case'3':
		{
			exit(0);
		}
		default:
		{
			cout << "lul" << endl;
			break;
		}
		}
	}
	system("pause");
	return 0;
}

ostream & operator<<(ostream &out, Wioska& tmp)
{
	return out << "Pojemnosc spichlerza: " << tmp.MAX_ilosc << endl << "Aktualna ilosc surowcow: " << tmp.iloscsurowcow << endl << "Budynki - poziom oraz koszt ulepszenia:" << endl << "Ratusz: " << tmp.Ratusz->getlevel() << " " << tmp.Ratusz->getprice() << endl << "Koszary: " << tmp.Koszary->getlevel() << " " << tmp.Koszary->getprice() << endl << "Spichlerz: " << tmp.Spichlerz->getlevel() << " " << tmp.Spichlerz->getprice() << endl << "Kopalnia: " << tmp.Kopalnia->getlevel() << " " << tmp.Kopalnia->getprice() << endl << "Ilosc wojska:" << endl << "Pikinierzy: " << tmp.MojPikinier->getilosc() << endl << "Topornicy: " << tmp.MojTopornik->getilosc() << endl << "Miecznicy: " << tmp.MojMiecznik->getilosc() << endl << "Zwiadowcy: " << tmp.MojZwiadowca->getilosc() << endl<<endl;
}
void polegry()
{
	Wioska MojaWioska;
	Soldier*WrogPikinier = new Pikinier;
	Soldier*WrogMiecznik = new Miecznik;
	Soldier*WrogTopornik = new Topornik;
	Soldier*WrogZwiadowca = new Zwiadowca;
	int enemypower = WrogPikinier->getpower() + WrogMiecznik->getpower() + WrogTopornik->getpower();
	int enemydefense = WrogPikinier->getdefense() + WrogMiecznik->getdefense() + WrogTopornik->getdefense();
	int enemycounter;
	cout << "Gra sie zaczela !" << endl << endl;
	for (int i = 0; i < 15; i++)
	{
		cout << "Tura nr:" << i << endl << endl;
		bool next = true;
		while (next)
		{
			Interfejs2();
			char wybor1;
			cin >> wybor1;
			switch (wybor1)
			{
			//wypisanie
			case'1':
			{
				cout << MojaWioska;
				break;
			}
			//budowanie
			case'2':
			{
				int wybor2;
				cout << "Ktory budynek chcesz rozbudowac?" << endl;
				cout << "Obecna ilosc surowcow: " << MojaWioska.iloscsurowcow << endl;
				cout << "1. Ratusz: " << MojaWioska.Ratusz->getprice() << endl;
				cout << "2. Koszary: " << MojaWioska.Koszary->getprice() << endl;
				cout << "3. Spichlerz: " << MojaWioska.Spichlerz->getprice() << endl;
				cout << "4. Kopalnia: " << MojaWioska.Kopalnia->getprice() << endl;
				cin >> wybor2;
				if ((wybor2 == 1) && (MojaWioska.iloscsurowcow >= 500))
				{
					MojaWioska.iloscsurowcow -= MojaWioska.Ratusz->getprice();
					MojaWioska.Ratusz->ZwiekszPoziom(400);
				}
				else if ((wybor2 == 2) && (MojaWioska.iloscsurowcow >= 300))
				{
					MojaWioska.iloscsurowcow -= MojaWioska.Koszary->getprice();
					MojaWioska.Koszary->ZwiekszPoziom(300);				}
				else if ((wybor2 == 3) && (MojaWioska.iloscsurowcow >= 200))
				{
					MojaWioska.iloscsurowcow -= MojaWioska.Spichlerz->getprice();
					MojaWioska.Spichlerz->ZwiekszPoziom(200);
					MojaWioska.MAX_ilosc = MojaWioska.Spichlerz->getlevel() * 1000;
				}
				else if ((wybor2 == 4) && (MojaWioska.iloscsurowcow >= 250))
				{
					MojaWioska.iloscsurowcow -= MojaWioska.Kopalnia->getprice();
					MojaWioska.Kopalnia->ZwiekszPoziom(250);
				}
				else
				{
					cout << " Nie stac Cie! " << endl;
				}
				cout << endl;
				break;
			}
			//rekrutowanie
			case'3':
			{
				cout << "Kogo chcesz zrekrutowac?" << endl;
				cout << "Ilosc surowcow: " << MojaWioska.iloscsurowcow << endl;
				int wybor3;
				cout << "1.Pikinier. Koszt: 20 (Koszary 2)" << endl;
				cout << "2.Miecznik. Koszt: 40 (Koszary 3)" << endl;
				cout << "3.Topornik. Koszt: 40 (Koszary 4)" << endl;
				cout << "4.Zwiadowca. Koszt: 80 (Koszary 5)" << endl << endl;
				cin >> wybor3;
				if ((wybor3 == 1) && ((MojaWioska.Koszary->getlevel())>1))
				{
					int ilosc;
					cout << "Mozesz kupic: " << MojaWioska.iloscsurowcow / 20 << endl;
					cout << "Wpisz ilosc: ";
					cin >> ilosc;
					if (ilosc <= MojaWioska.iloscsurowcow / 20)
					{
						MojaWioska.MojPikinier->setilosc(ilosc);
						MojaWioska.iloscsurowcow -= ilosc * 20;
					}
				}
				else if ((wybor3 == 2) && ((MojaWioska.Koszary->getlevel())>2))
				{
					int ilosc;
					cout << "Mozesz kupic: " << MojaWioska.iloscsurowcow / 40 << endl;
					cout << "Wpisz ilosc: ";
					cin >> ilosc;
					if (ilosc <= MojaWioska.iloscsurowcow / 40)
					{
						MojaWioska.MojMiecznik->setilosc(ilosc);
						MojaWioska.iloscsurowcow -= ilosc * 40;
					}
				}
				else if ((wybor3 == 3) && ((MojaWioska.Koszary->getlevel())>3))
				{
					int ilosc;
					cout << "Mozesz kupic: " << MojaWioska.iloscsurowcow / 40 << endl;
					cout << "Wpisz ilosc: ";
					cin >> ilosc;
					if (ilosc <= MojaWioska.iloscsurowcow / 40)
					{
						MojaWioska.MojTopornik->setilosc(ilosc);
						MojaWioska.iloscsurowcow -= ilosc * 40;
					}
				}
				else if ((wybor3 == 4) && ((MojaWioska.Koszary->getlevel())>4))
				{
					int ilosc;
					cout << "Mozesz kupic: " << MojaWioska.iloscsurowcow / 80 << endl;
					cout << "Wpisz ilosc: ";
					cin >> ilosc;
					if (ilosc <= MojaWioska.iloscsurowcow / 80)
					{
						MojaWioska.MojZwiadowca->setilosc(ilosc);
						MojaWioska.iloscsurowcow -= ilosc * 80;
					}
				}
				else
					cout << "Nie masz odpowiedniego poziomu koszar, lub nie wybrales opcji 1-4" << endl;
				cout << endl;
				MojaWioska.VillagePower = MojaWioska.MojPikinier->getpower() + MojaWioska.MojMiecznik->getpower() + MojaWioska.MojTopornik->getpower();
				MojaWioska.VillageDefense= MojaWioska.MojPikinier->getdefense() + MojaWioska.MojMiecznik->getdefense() + MojaWioska.MojTopornik->getdefense();
				break;
			}
			case'4':
			{
				cout << "Wyslano wojska!" << endl;
				float proporcja;
				if (MojaWioska.VillagePower > enemypower)
				{
					cout << "Wygrales! " << endl;
					proporcja = (enemypower * 100) / MojaWioska.VillagePower;
					MojaWioska.MojPikinier->afterbattle(100-proporcja);
					MojaWioska.MojMiecznik->afterbattle(100-proporcja);
					MojaWioska.MojTopornik->afterbattle(100-proporcja);
					WrogPikinier->afterbattle(0);
					WrogMiecznik->afterbattle(0);
					WrogTopornik->afterbattle(0);
				}
				else if (MojaWioska.VillagePower < enemypower)
				{
					cout << "Przegrales!" << endl;
					proporcja = (enemypower * 100) / MojaWioska.VillagePower;
					MojaWioska.MojPikinier->afterbattle(0);
					MojaWioska.MojMiecznik->afterbattle(0);
					MojaWioska.MojTopornik->afterbattle(0);
					WrogPikinier->afterbattle(100-proporcja);
					WrogMiecznik->afterbattle(100-proporcja);
					WrogTopornik->afterbattle(100-proporcja);
				}
				else
				{
					cout << "Remis!" << endl;
					MojaWioska.MojPikinier->afterbattle(0);
					MojaWioska.MojMiecznik->afterbattle(0);
					MojaWioska.MojTopornik->afterbattle(0);
					WrogPikinier->afterbattle(0);
					WrogMiecznik->afterbattle(0);
					WrogTopornik->afterbattle(0);

				}
				break;
			}
			case '5':
			{
				if (MojaWioska.MojZwiadowca->getilosc() > WrogZwiadowca->getilosc())
				{
					cout << "Udalo sie zdobyc informacje nt wrogiego wojska." << endl;
					cout << "Pikinierzy: " << WrogPikinier->getilosc() << endl;
					cout << "Miecznicy: " << WrogMiecznik->getilosc() << endl;
					cout << "Topornicy: " << WrogTopornik->getilosc() << endl;
					cout << "Zwiadowcy: " << WrogZwiadowca->getilosc() << endl;
				}
				else
				{
					cout << "Wrogich zwiadowcow jest wiecej. Twoje wojska wracaja bez raportu." << endl;
				}
				break;
			}
			case '6':
			{
				next = false;
				break;
			}
			default:
			{
				cout << "Nic nie wybrales." << endl;
				break;
			}

			}
		}
		//przyrost surowcow
			if ((MojaWioska.iloscsurowcow + 250 + 250*MojaWioska.Kopalnia->getlevel()) <= MojaWioska.MAX_ilosc)
			{
				MojaWioska.iloscsurowcow =MojaWioska.iloscsurowcow+ 250 + 250*MojaWioska.Kopalnia->getlevel();
			}
			else if (((MojaWioska.iloscsurowcow+ 250 + 250*MojaWioska.Kopalnia->getlevel()) > MojaWioska.MAX_ilosc) && (MojaWioska.iloscsurowcow < MojaWioska.MAX_ilosc))
			{
				MojaWioska.iloscsurowcow = MojaWioska.MAX_ilosc;
			}
			//przyrost wrogiego wojska
			enemycounter=rand()%4;
			switch (enemycounter)
			{
			case 0:
			{
				WrogPikinier->setilosc(3*i);
				break;
			}
			case 1:
			{
				WrogMiecznik->setilosc(2 * i);
				break;
			}
			case 2:
			{
				WrogTopornik->setilosc(3 * i);
				break;
			}
			case 3:
			{
				WrogZwiadowca->setilosc(1*i);
				break;
			}
			}
			enemypower= WrogPikinier->getpower() + WrogMiecznik->getpower() + WrogTopornik->getpower();
			enemydefense= WrogPikinier->getdefense() + WrogMiecznik->getdefense() + WrogTopornik->getdefense();

}
cout << "Wróg na Ciebie naciera!" << endl << endl;
cout << "Wrogie wojsko: " << endl << endl;
cout << "Pikinierzy: " << WrogPikinier->getilosc() << endl;
cout << "Miecznicy: " << WrogMiecznik->getilosc() << endl;
cout << "Topornicy: " << WrogTopornik->getilosc() << endl;
cout << "Zwiadowcy: " << WrogZwiadowca->getilosc() << endl << endl;
cout << "Twoje wojsko:" << endl;
cout << "Pikinierzy: " << MojaWioska.MojPikinier->getilosc() << endl;
cout << "Miecznicy: " << MojaWioska.MojMiecznik->getilosc() << endl;
cout << "Topornicy: " << MojaWioska.MojTopornik->getilosc() << endl;
cout << "Zwiadowcy: " << MojaWioska.MojZwiadowca->getilosc() << endl << endl;
float proporcja;
if (MojaWioska.VillagePower > enemypower)
{
	cout << "Wygrales! " << endl;
	proporcja = ((enemypower * 100) / MojaWioska.VillagePower)*MojaWioska.Ratusz->getlevel();
	cout << "Twoj zdobyty ranking: " << proporcja << endl;
	cout << "BRAWO!" << endl;
}
else if (MojaWioska.VillagePower < enemypower)
{
	cout << "Przegrales!" << endl;
	cout << "Twoj zdobyty ranking: 0 :(" << endl;
	cout << "Pomimo wszystko, brawo !" << endl;
}
else
{
	cout << "Remis!" << endl;
	cout << "Twoj zdobyty ranking: 5 na pocieszenie :-)" << endl;
	cout << "BRAWO!" << endl;

}
}
void Interfejs2()
{
	cout << "1.Informacje o wiosce." << endl;
	cout << "2.Rozbuduj." << endl;
	cout << "3.Rekrutuj." << endl;
	cout << "4.Atak." << endl;
	cout << "5.Wyslij zwiadowcow." << endl;
	cout << "6.Nowa tura." << endl<<endl;
}