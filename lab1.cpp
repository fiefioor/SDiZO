// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

struct struktura
{
	int int1;
	char char1;
	double double1;
};

struktura** Losowanie(int _n){
	int n = _n;
	struktura** tab = new struktura* [n];
	for(int i=0;i<n-1;i++)
	{
		tab[i]->double1=0;
		tab[i]->char1=rand() % 100;
		tab[i]->int1=rand() % 100 +1;	
	}
	return(tab);
}

void Kasowanie(struktura** tab, int _n)
{
	int n = _n;
	for(int i=0; i<n-1; i++)
	{
		delete tab[i];
	}
	delete [] tab;
}

void Sortowanie(struktura** tab, int _n)	
{
	int n = _n;
	    for(int i=0; i<n-1; i++)
		{
			for(int j=0; j<n-1; j++)
			{
				if(tab[j+1]->int1 < tab[j]->int1)
                swap(tab[j+1], tab[j]);
			}
	}


}

int zliczanie_znakow(struktura** tab, int _n, char _h)
{
	char h = _h;
	int n = _n;
	int licznik=0;
	for(int i=0; i<n; i++)
	{
		if(tab[i]->char1==h) licznik++;
	}
	return licznik;
}


int _tmain(int argc, _TCHAR* argv[])
{


	system("pause");
}


