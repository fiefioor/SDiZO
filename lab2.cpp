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
	void display_U();
	void display_D();

private:
	int amount;	
	pole *first, *last;
	void AddFirst(int);
	void AddLast(int);
	pole* Search(int);
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

pole* list::Search(int key)
{
	pole* i=first;
	while(i!=NULL)
	{
		if(i->key == key)
		{
			return i;
		}
		i=i->next;
	}
	return NULL;
}


void list::AddFirst(int key)
{
		pole* nju = new pole;
		nju->key=key;
	if(amount==0)
	{
		first=nju;
		last=nju;
		nju->next=NULL;
		nju->prev=NULL;
	}
	else
	{
		first->prev=nju;
		nju->prev=NULL;
		nju->next=first;
		first=nju;
	}
	amount++;
}

void list::AddLast(int key)
{
	if(amount==1)
	{
		last->key=key;
		last->prev=first;
		last->next=NULL;
	}
	else
	{
		pole* nju = new pole;
		nju->key = key;
		last->next=nju;
		nju->next=NULL;
		nju->prev=last;
		last=nju;
	}

	amount++;
}

void list::Add(int key)
{
	if(amount==0)
	{
		AddFirst(key);
	}
	else
	if(amount==1)
	{
		if(key > first->key) AddLast(key);
		if(key < first->key) AddFirst(key);
	}
	else
	{
		if(key < first->key) AddFirst(key);
		else if(key > last->key) AddLast(key);
		else
		{
			pole* nju = new pole;
			nju->key=key;
			pole* i=first;
			while (i->key < key)
			{
				if(i->key == key) cout << "element istnieje" << endl;
				i=i->next;
			}
			nju->next=i;
			nju->prev=i->prev;
			i->prev->next=nju;
			i->prev=nju;
			amount++;
		}
	}
}

void list::Delete(int key)
{
	if(amount==0) cout << "brak elementow"<<endl;
	if(amount==1)
	{
		delete first;
		first=NULL;
		last=NULL;
		amount--;
	}
	else if(key == first->key)
	{
		first=first->next;
		delete first->prev;
		first->prev = NULL;
		amount--;
	}
	else if(key == last->key)
	{
		last = last->prev;
		delete last->next;
		last->next=NULL;
		amount--;
	}
	else
	{
		pole* right = first;
		pole* left = NULL;
		pole* tmp=NULL;
		if(right!=NULL)
		{
			if(right->key==key)
			{
				left=right->prev;
				right->next->prev=left;
				left->next=right->next;
				delete right;
				amount--;
			}
			right=right->next;

		}

	}



}

void list::display_U()
{
	pole* pointer = first;
	for(int i=0;i<amount-1;i++)
	{
		cout << "Klucz " << i+1 << " elementu listy : " << pointer->key << endl;
		pointer=pointer->next;
	}
	cout << "Klucz ostatniego elementu listy : " << pointer->key << endl;

}

void list::display_D()
{
	pole* pointer = last;
	for(int i=amount;i>1;i--)
	{
		cout << "Klucz " << i << " elementu listy : " << pointer->key << endl;
		pointer=pointer->prev;
	}
	cout << "Klucz pierwszego elementu listy : " << pointer->key << endl;

}

int _tmain(int argc, _TCHAR* argv[])
{
	list* lista = new list();
	lista->Add(22);
	lista->getAmount();
	lista->Add(11);
	lista->getAmount();
	lista->Add(43);
	lista->getAmount();
	lista->Add(37);
	lista->Add(100);
	lista->getAmount();
	lista->display_U();
	lista->display_D();
	lista->Delete(100);
	lista->Delete(11);
	lista->getAmount();
	lista->display_U();
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
