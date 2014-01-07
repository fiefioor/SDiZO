// lab5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Node.h"
#include "AVLtree.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	AVLtree* tree1 = new AVLtree();

	tree1->add(30);
	tree1->add(10);
	tree1->add(15);
	tree1->add(25);
	tree1->add(15);
	tree1->add(tree1->max()->getKey()+1);
	tree1->add(tree1->min()->getKey()-1);
	tree1->add(22);
	tree1->add(23); 

	cout << tree1->getRoot()->getKey();
	cout << endl << endl;
	cout << tree1->getRoot()->getBf() << endl;

	tree1->removeNode(25);
	cout << endl << endl;
	cout << tree1->getRoot()->getKey() << endl;

	system("pause");
	return 0;
}

