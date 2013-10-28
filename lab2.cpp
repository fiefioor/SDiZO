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
private:
	int amount;	
	pole *first, *last;
	void AddFirst(int);
};

list::list()
{
	amount = 0;
	first = NULL;
	last = NULL;
}

list::~list(){;}

void list::AddFirst(int key)
{
	if(amount==NULL)
	{
	pole* nju = new pole;
	nju->key = key;
	nju->next = NULL;
	nju->prev = NULL;
	amount++;
	}
	else
	{
		pole* nju = new pole;
		nju->key = key;
		nju->prev = NULL;
		nju->next = first;
		first = nju;
		amount++;
	}
}

void list::Add(int key)
{
	if(amount==0)
	{
		AddFirst(key);
	}
	else
	{
		pole* currentR = first;
		pole* currentL = NULL;
		for(int i=0; i<amount;i++)
		{
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
					last = nju;
					amount++;
				}
				else
				{
					pole* nju = new pole;
					nju->key = key;
					nju->prev = currentL;
					nju->next = currentR;
					amount++;
				}

			}
			currentL = currentR;
			currentR = currentR->next;
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	system("pause");
}

