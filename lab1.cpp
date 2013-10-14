SDiZO
=====
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

struktura* Losowanie(int _n){
	int n = _n;
	struktura** tab = new struktura* [n];
	for(int i=0;i<n;i++)
	{
		tab[i]->double1=0;
		tab[i]->char1=rand() % 100;
		tab[i]->int1=rand() % 100 +1;	
	}
	return(*tab);
}


int _tmain(int argc, _TCHAR* argv[])
{


	system("pause");
}

