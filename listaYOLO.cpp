#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
 
using namespace std;
 
struct pole{
	int klucz;
	pole *nast, *poprz;
};
 
class Lista{
	pole *Pierwszy, *Ostatni;
	int Ilosc;
 
	public:
		Lista();	
		bool AddSort(int klucz); //-dodawanie elementu w kolejnosci rosnacej 
		bool AddLast(int klucz); //-dodawanie elementu na koniec listy
		bool AddFirst(int klucz); //-dodawanie elementu na poczatek listy
		int TakeFirst(); //-Zdejmij pierwszy element
		int TakeLast(); //-Zdejmij ostatni element
		void Wyswietl(bool sposob);//-Wyswietl wszystkie elementy w kolejnosci rosnacej
 
		bool Usun(int klucz);
		pole * Szukaj(int klucz);
};
 
Lista::Lista(){
	Pierwszy=Ostatni=NULL;
	Ilosc=0;
}
 
//---dodawanie elementu na koniec listy
bool Lista::AddLast(int klucz){
	if (Szukaj(klucz)) return false;
	//jezeli lista nie ma zadnych elementow
	//dodajemy jako pierwszy i ostatni element
	if(!Ilosc){ 
		pole *nowy = new pole;
		nowy->klucz=klucz;
		Pierwszy=nowy; //ustawienie nowego pierwszego elementu
		Ostatni=nowy;//ustawienie nowego pierwszego elementu
		nowy->nast=NULL; //nie ma nastepnego elementu
		nowy->poprz=NULL; //nie ma pierwszego elementu
		Ilosc++;
	}
	//jezeli w liscie jest juz jakis element,
	//dodajemy go na sam koniec listy
	else{
		pole *nowy = new pole;
		nowy->klucz=klucz;
		Ostatni->nast=nowy;
		nowy->poprz=Ostatni;
		nowy->nast=NULL;
		Ostatni=nowy;
		Ilosc++;
	}
	return true;
}
 
//---dodawanie elementu na poczatek listy
bool Lista::AddFirst(int klucz){
	if (Szukaj(klucz)) return false;
	//jezeli lista nie ma zadnych elementow
	//dodajemy jako pierwszy i ostatni element
	if(!Ilosc){
		pole *nowy = new pole;
		nowy->klucz=klucz;
		Pierwszy=nowy;
		Ostatni=nowy;
		nowy->nast=NULL;
		nowy->poprz=NULL;
		Ilosc++;
	}
	//jezeli na liscie cos sie juz znajduje, nalezy
	//dodac element na poczatek listy
	else{
		pole *nowy = new pole;
		nowy->klucz=klucz;
		Pierwszy->poprz=nowy;
		nowy->poprz=NULL;
		nowy->nast=Pierwszy;
		Pierwszy=nowy;
		Ilosc++;
	}
	return true;
}
 
//---dodawanie elementu w kolejnosci rosnace 
bool Lista::AddSort(int klucz){
	//jezeli lista nie ma zadnych elementow
	//dodajemy jako pierwszy i ostatni element
	if(!Ilosc){
		pole *nowy = new pole;
		nowy->klucz=klucz;
		Pierwszy=nowy;
		Ostatni=nowy;
		nowy->nast=NULL;
		nowy->poprz=NULL;
		Ilosc++;
	}
	//jezeli na liscie znajduja sie juz jakieś elementy
	else{
		//dodawanie elementu na poczatek listy, jezeli nowy klucz
		//jest mniejszy niz klucz pierwszego elementu
		if(klucz<Pierwszy->klucz) AddFirst(klucz);
		//dodawanie elementu na koniec listy, jezeli nowy klucz
		//jest wiekszy niz klucz ostatniego elementu
		else if(klucz>Ostatni->klucz) AddLast(klucz);
		//dodawanie elementu w srodek listy, w odpowiednie dla niego miejsce
		else{
			pole *nowy = new pole;
			nowy->klucz=klucz;
 
			//szukanie miejsca wstawienia od pierwszego elementu
			pole *i=Pierwszy;
			while(i->klucz < klucz){ 
				if(i->klucz==klucz) return false; //zapobieganie powstawaniu duplikatow
				i=i->nast;
			}
 
			nowy->nast=i;
			nowy->poprz=i->poprz;
			i->poprz->nast=nowy;
			i->poprz=nowy;
			Ilosc++;
		}
	}
	return true;
} 
 
//---Wyswietl wszystkie elementy w kolejnosci rosnacej (true = rosnaco, false = malejaco)
void Lista::Wyswietl(bool sposob){
	if(sposob){
		pole *it=Pierwszy;
		while(it!=NULL){
			printf("%d -> ", it->klucz);
			it=it->nast;
		}
	}
	else{
		pole *it=Ostatni;
		while(it!=NULL){
			printf("%d -> ", it->klucz);
			it=it->poprz;
		}
	}
	printf("\n");
}
 
pole * Lista::Szukaj(int klucz){
	pole *i=Pierwszy;
	//szukanie elementu
	while(i!=NULL){
		if(i->klucz==klucz) return i;
		i=i->nast;
	}
	//nie znaleziono elementu
	return NULL;
}
 
bool Lista::Usun(int klucz){
	if(!Ilosc) return false;
	if(Ilosc==1){
		delete Pierwszy;
		Pierwszy=NULL;
		Ostatni=NULL;
		Ilosc=0;
		return true;
	}
	else if(klucz==Pierwszy->klucz){
		Pierwszy=Pierwszy->nast;
		delete Pierwszy->poprz;
		Pierwszy->poprz=NULL;
		Ilosc--;
		return true;
	}
	else if(klucz==Ostatni->klucz){
		Ostatni=Ostatni->poprz;
		delete Ostatni->nast;
		Ostatni->nast=NULL;
		Ilosc--;
		return true;
	}
	else{
		pole *i=Pierwszy;
		while(i!=NULL){
			//znaleziono podany klucz, usuwamy go
			if(i->klucz==klucz){
				i->poprz->nast=i->nast;
				i->nast->poprz=i->poprz;
				delete i;
				Ilosc--;
				return true;
			}
			i=i->nast;
		}
		return false;
	}
}
 
int main(){
	srand(time(NULL));
	int ilosc;
	//wczytywanie od uzytkownika informacji
	//o ilosci elementow dodanych do listy
	printf("Podaj ilosc elementow: ");
	scanf("%d",&ilosc);
	Lista zadanie;
 
	//dodawanie elementow do listy
	for(int i=0; i<ilosc; i++){
		if(!zadanie.AddSort(rand()%200+1)){
			printf("Klucz o podanym indexie juz istnieje!\n");
		}
	}
 
	zadanie.Wyswietl(true);
	int szuk;
	printf("Szukaj elementu: ");
	scanf("%d",&szuk);
 
	pole*sz=zadanie.Szukaj(szuk);
	//jezeli znalazlo
	if(sz){
		printf("Znalazlem klucz: %d\n",sz->klucz);
	}
	//jesli nie znalazlo
	else printf("Nie znalazlem podanego klucza!\n");
 
	int usun;
	printf("Usun element: ");
	scanf("%d",&usun);
 
	if(zadanie.Usun(usun)){
		printf("Usunalem klucz: %d\n",usun);
	}
	//jesli nie znalazlo
	else printf("Nie znalazlem podanego klucza!\n");
	zadanie.Wyswietl(false);
	return 0;
}
