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
        for(int i=0;i<n;i++)
        {
			tab[i] = new struktura;
                tab[i]->double1=0;
                tab[i]->char1=rand() % 100;
                tab[i]->int1=rand() % 1000 +1;        
        }
        return(tab);
}

void Kasowanie(struktura** tab, int _n)
{
        int n = _n;
        for(int i=0; i<n; i++)
        {
                delete tab[i];
        }
        delete [] tab;
}

void Sortowanie(struktura** tab, int _n)        
{
        int n = _n;
            for(int i=0; i<n; i++)
                {
                        for(int j=0; j<n-1; j++)
                        {
                                if(tab[j+1]->int1 < tab[j]->int1)
								 swap(tab[j+1], tab[j]);
                        }
        }


}

int Zliczanie_znakow(struktura** tab, int _n, char _h)
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

void Display_int(struktura** tab, int n)
{
	for(int i=0;i<n;i++)
	{
		cout << tab[i]->int1 << " ";
	}

}

void Display_char(struktura** tab, int n)
{
	for(int i=0;i<n;i++)
	{
		cout << tab[i]->char1 << " ";
	}

}


int _tmain(int argc, _TCHAR* argv[])
{
        //czas start1
        struktura** pomiar1;
        pomiar1=Losowanie(1000);
        Sortowanie(pomiar1,1000);
	//	Display_int(pomiar1,1000);
	//	cout << endl;
	//	Display_char(pomiar1,1000);
        cout << endl << Zliczanie_znakow(pomiar1,1000,'A') << endl;
        Kasowanie(pomiar1,1000); 
        //czas stop1

		getchar();

		//czs start2
        struktura** pomiar2;
        pomiar2=Losowanie(10000);
        Sortowanie(pomiar2,10000);
	//	Display_int(pomiar1,1000);
	//	cout << endl;
	//	Display_char(pomiar1,1000);
        cout << endl << Zliczanie_znakow(pomiar2,10000,'B') << endl;
        Kasowanie(pomiar2,10000); 
        //czas stop2
		
		getchar();

		//czas start3
        struktura** pomiar3;
        pomiar3=Losowanie(100000);
        Sortowanie(pomiar3,100000);
	//	Display_int(pomiar1,1000);
	//	cout << endl;
	//	Display_char(pomiar1,1000);
        cout << endl << Zliczanie_znakow(pomiar3,100000,'C') << endl;
        Kasowanie(pomiar3,100000); 
        //czas stop3
}
