// lab2(1).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct pole
{
	int key;
	pole *next, *prev;
};

class list
{
public:
	list();
	~list();
	void Add(int);
	void Delete(int);
	void getAmount();

private:
	int amount;	
	pole *first, *last;
	void AddFirst(int);
	void Addsecund(int);
};

list::list()
{
	amount = 0;
	first = NULL;
	last = NULL;
}

list::~list(){;}

void list::getAmount()
{
	cout << "Ilosc elementow listy: " << amount << endl;
}


void list::AddFirst(int key)
{
	pole* tmp = new pole;
	pole* nju = new pole;
	nju->key = key;
	if(amount==0)
	{
	nju->next = NULL;
	nju->prev = NULL;
	}
	else
	{
		tmp = first;
		tmp->prev = nju;
		nju->prev = NULL;
		nju->next = first;
		first = nju;
		
	}
amount++;
}

void list::Addsecund(int key)
{
	pole* nju = new pole;
	nju->key=key;

		if(nju->key > first->key)
		{
			nju->prev=first;
			last=nju;
		}
		if(nju->key < first->key)
		{
			last = first;
			last->prev=nju;
			nju->next=last;
			nju->prev=NULL;
			first = nju;
		}
		amount++;

}


void list::Add(int key)
{
	if(amount==0)
	{
		AddFirst(key);
	}
else if(amount==1)
	{
		Addsecund(key);
	} 
	else
	{
		pole* currentR = first;
		pole* currentL = NULL;
		for(int i=0; i<amount;i++)
		{
			if(key == currentR->key)
			{
				cout << "taka wartość juz istnieje"<< endl;
			}

			if(key < currentR->key )
			{
				if(currentR == first)
				{
					AddFirst(key);

				}

				if (currentR == last)
				{
					pole* nju = new pole;
					nju->key = key;
					nju->prev = currentR;
					nju->next = NULL;
					currentR->next=nju;
					last = nju;
					amount++;
				}
				else
				{
					pole* nju = new pole;
					nju->key = key;
					nju->prev = currentL;
					currentL->next=nju;
					nju->next = currentR;
					currentR->prev=nju;
					amount++;
				}
				      
			}
			currentL = currentR;
			currentR = currentR->next;
		}
		/*if(key > last->key)
		{
			pole* nju = new pole;
			nju->key = key;
			last->next=nju;
			nju->prev=last;
			nju->next=NULL;
			last = nju;
		}*/

	}
}

void list::Delete(int key)
{
	pole* currentR = first;
	pole* currentL = NULL;
	bool ifdel=false;
	for(int i=0;i<amount;i++)
	{
		if(currentR==first)
		{
			if(key==currentR->key)
			{
				currentL=currentR;
				currentR=currentR->next;
				first=currentR;
				currentR->prev=NULL;
				delete currentL;
				ifdel=true;
			}

		}
		if(currentR==last)
		{
			if(key==currentR->key)
			{
				last=currentL;
				currentL->next=NULL;
				delete currentR;
				ifdel=true;
			}
		}
		if(key==currentR->key)
		{
			pole* tmp=currentR;
			currentR=currentR->next;
			currentL->next=currentR;
			currentR->prev=currentL;
			delete tmp;
			ifdel=true;
		}



	}
	if(ifdel==false)
	{
		cout << "brak takiego elementu" << endl;
	}

}


int _tmain(int argc, _TCHAR* argv[])
{
	list* lista = new list();
	lista->Add(1);
	lista->getAmount();
	lista->Add(2);
	//lista->Add(3);

 /*	pole* test = new pole;
	pole* test1= new pole;
	pole* nowe = new pole;

	test->key=1;
	test1->key=2;
	test->next=test1;
	test1->prev=test;
	nowe=test;
	cout << endl << nowe->key;
	cout << endl;
	nowe=nowe->next;

	cout << endl << nowe->key;
	cout << endl;
*/
	system("pause");
	return 0;
}
