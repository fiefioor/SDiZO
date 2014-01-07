#include "stdafx.h"
#include "AVLtree.h"
#include <iostream>

using namespace std;


AVLtree::AVLtree(void)
{
	root = NULL;
}


AVLtree::~AVLtree(void)
{
}

void AVLtree::setRoot(Node* _root)
{
	root=_root;
}

Node* AVLtree::getRoot()
{
        return(root);
} 

void AVLtree::display()
{
        Node* tmp=getRoot();
        if(tmp!=NULL)
        {
                display(tmp->getLeft());
                cout << tmp->getKey() << " ";
                display(tmp->getRight());
        }
        
}

void AVLtree::displayBf()
{
	Node* tmp=getRoot();
        if(tmp!=NULL)
        {
                displayBf(tmp->getLeft());
				cout << tmp->getKey() << " = " << tmp->getBf() << endl;
                displayBf(tmp->getRight());
        }
}


void AVLtree::display(Node* _root)
{
        if(_root!=NULL)
        {
                display(_root->getLeft());
                cout << _root->getKey() << " ";
                display(_root->getRight());
        }
        
}

void AVLtree::displayBf(Node* _root)
{
	if(_root!=NULL)
        {
                displayBf(_root->getLeft());
                cout << _root->getKey() << " = " << _root->getBf() << endl;
                displayBf(_root->getRight());
        }
}


Node* AVLtree::search(int _key)
{
        Node* tmp = getRoot();
        while(tmp!=NULL)
        {
                if(_key < tmp->getKey())
                {
                        tmp=tmp->getLeft();
                }
                else if(_key > tmp->getKey())
                {
                        tmp=tmp->getRight();
                }
                else if(_key == tmp->getKey())
                {
                        return(tmp);
                }
        }
        cout << "brak wezla";
        return(NULL);
}

Node* AVLtree::min()
{
        Node* tmp = new Node();
        tmp=getRoot();
        while(tmp->getLeft()!= NULL)
        {
                tmp=tmp->getLeft();
        }
        return(tmp);
}

Node* AVLtree::min(Node* i)
{
        while(i->getLeft()!= NULL)
        {
                i=i->getLeft();
        }
        return(i);
}


Node* AVLtree::max()
{
        Node* tmp = new Node();
        tmp=getRoot();
        while(tmp->getRight()!= NULL)
        {
                tmp=tmp->getRight();
        }
        return(tmp);
}

Node* AVLtree::max(Node* i)
{
        while(i->getRight()!= NULL)
        {
                i=i->getRight();
        }
        return(i);
}


///// rotacje

void AVLtree::RotateRR(Node* A)
{
	Node* B = A->getRight();
	Node* p = A->getParent();

	A->setRight(B->getLeft());

	if(A->getRight()!=NULL)
	{
		A->getRight()->setParent(A);
	}

	B->setLeft(A);
	B->setParent(p);
	A->setParent(B);

	if(p!=NULL)
	{
		if(p->getLeft() == A)
		{
			p->setLeft(B);
		}
		else
		{
			p->setRight(B);
		}

	}
	else
	{
		setRoot(B);
	}
	if(B->getBf()== -1)
	{
		A->setBf(0);
		B->setBf(0);
	}
	else
	{
		A->setBf(-1);
		B->setBf(1);
	}
}

void AVLtree::RotateLL(Node* A)
{
	Node* B = A->getLeft();
	Node* p = A->getParent();

	A->setLeft(B->getRight());

	if(A->getLeft()!=NULL)
	{
		A->getLeft()->setParent(A);
	}

	B->setRight(A);
	B->setParent(p);
	A->setParent(B);

	if(p!=NULL)
	{
		if(p->getLeft() == A)
		{
			p->setLeft(B);
		}
		else
		{
			p->setRight(B);
		}

	}
	else
	{
		setRoot(B);
	}
	if(B->getBf()== 1)
	{
		A->setBf(0);
		B->setBf(0);
	}
	else
	{
		A->setBf(1);
		B->setBf(-1);
	}
}

void AVLtree::RotateRL(Node* A)
{
	Node* B = A->getRight();
	Node* C = B->getLeft();
	Node* p = A->getParent();

	B->setLeft(C->getRight());

	if(B->getLeft()!=NULL)
	{
		B->getLeft()->setParent(B);
	}

	A->setRight(C->getLeft());

	if(A->getRight()!=NULL)
	{
		A->getRight()->setParent(A);
	}

	C->setLeft(A);
	C->setRight(B);
	A->setParent(C);
	B->setParent(C);
	C->setParent(p);

	if(p)
	{
		if(p->getLeft() == A)
		{
			p->setLeft(C);
		}
		else
		{
			p->setRight(C);
		}
	}
	else
	{
		setRoot(C);
	}

	if(C->getBf() == -1)
	{
		A->setBf(1);
	}
	else
	{
		A->setBf(0);
	}

	if(C->getBf() == 1)
	{
		B->setBf(-1);
	}
	else
	{
		B->setBf(0);
	}

	C->setBf(0);
}

void AVLtree::RotateLR(Node* A)
{
	Node* B = A->getLeft();
	Node* C = B->getRight();
	Node* p = A->getParent();

	B->setRight(C->getLeft());

	if(B->getRight()!=NULL)
	{
		B->getRight()->setParent(B);
	}

	A->setLeft(C->getRight());
	if(A->getLeft()!=NULL)
	{
		A->getLeft()->setParent(A);
	}

	C->setRight(A);
	C->setLeft(B);
	A->setParent(C);
	B->setParent(C);
	C->setParent(p);

	if(p!=NULL)
	{
		if(p->getLeft() == A)
		{
			p->setLeft(C);
		}
		else
		{
			p->setRight(C);
		}
	}
	else
	{
		setRoot(C);
	}

	if(C->getBf() == 1)
	{
		A->setBf(-1);
	}
	else
	{
		A->setBf(0);
	}

	if(C->getBf() == -1)
	{
		B->setBf(1);
	}
	else
	{
		B->setBf(0);
	}

	C->setBf(0);
}

void AVLtree::add(int key)
{
	Node* p, * r;
	bool t;

	Node* w = new Node(key);
	w->setBf(0);

	//	FAZA 1 - wstawienie węzła

	p = getRoot();
	if(p==NULL)
	{
		setRoot(w);
	}
	else
	{
		while(true)
		{
			if(key < p->getKey())
			{
				if(p->getLeft()==NULL)
				{
					p->setLeft(w);
					break;
				}
				else p=p->getLeft();
			}
			else
			{
				if(p->getRight() == NULL)
				{
					p->setRight(w);
					break;
				}
				else p = p->getRight();
			}
		}
			w->setParent(p);

		// FAZA 2 - balansowanie drzewa

			if(p->getBf()) p->setBf(0);
			else
			{
				if(p->getLeft() == w) p->setBf(1);
				else p->setBf(-1);

			r = p->getParent();
			t=false;

			while(r)
			{
				if(r->getBf()!=0)
				{
					t = true;
					break;		// przerywamy pętle
				};
								// jak nie to ustawiamy balans
				if(r->getLeft() == p) r->setBf(1);
				else r->setBf(-1);

				p = r;
				r = r->getParent();
			};

			if(t)
			{
				if(r->getBf() == 1)
				{
					if(r->getRight() == p) r->setBf(0);
					else if(p->getBf() == -1) RotateLR(r);
					else RotateLL(r);
				}
				else
				{
					if(r->getLeft() == p) r->setBf(0);
					else if(p->getBf() == 1) RotateRL(r);
					else RotateRR(r);
				}

			}
		}
	}
	/*Node* x = getRoot(); // x to root
	Node* y = NULL;
	Node* z;
	Node* n = new Node(key); // n to wezel ktory chcemy dodac
	n->setBf(0);

	while(x!=NULL)
	{
		if(x->getKey() == n->getKey())
		{
			delete n;	// jezeli istnieje wezel z takim kluczem nie wstawiamy nic i zwracamy false
		}
		y=x;
		if(n->getKey() < x->getKey()) x = x->getLeft();
		else x = x->getRight();

	}

	if(n->getParent()!=y)
	{
		setRoot(n);
	}

	if(n->getKey() < y->getKey()) y->setLeft(n);
	else y->setRight(n);
	if(y->getBf()!=0)
	{
		y->setBf(0);
	}
	if(y->getLeft() == n) y->setBf(1);
	else y->setBf(-1);

	z = y->getParent();
	while(z!=NULL)
	{
		if(z->getBf()!=0) break;
		if(z->getLeft() == y) z->setBf(1);
		else z->setBf(-1);

		y=z;
		z=z->getParent();
	}

	if(z==NULL) 

	if(z->getBf() == 1)
	{
		if(z->getRight() == y)
		{
			z->setBf(0);
		}
		if(y->getBf() == -1) RotateLR(z);
		else RotateLL(z);
	}
	else
	{
		if(z->getLeft() == y)
		{
			z->setBf(0);
		}
		if(y->getBf() == 1) RotateRL(z);
		else RotateRR(z);
	}
	*/
}

Node* AVLtree::removeNode(int key)
{
	Node *t, *y, *z;
	bool nest;
	Node* x = search(key);

	if((x->getLeft()!=NULL) && (x->getRight()!=NULL))
	{
		y = removeNode(predecessor(x)->getKey());
		nest = false;
	}
	else
	{
		if(x->getLeft()!=NULL)
		{
			y= x->getLeft();
			x->setLeft(NULL);
		}
		else
		{
			y = x->getRight();
			x->setRight(NULL);
		}
		x->setBf(0);
		nest = true;

	}


	if(y!=NULL)
	{
		y->setParent(x->getParent());
		y->setLeft(x->getLeft()); if(x->getLeft()) y->getLeft()->setParent(y);
		y->setRight(x->getRight()); if(x->getRight()) y->getRight()->setParent(y);
		y->setBf(x->getBf());
	}

	if(x->getParent())
	{
		if(x->getParent()->getLeft() == x) x->getParent()->setLeft(y); else x->getParent()->setRight(y);
	}
	else setRoot(y);

	if(nest)
	{
		z=y;
		y=x->getParent();
		while(y)
		{
			if(y->getBf() == 0)	//przypadek 1
			{
				if(y->getLeft() == z) y->setBf(-1); else y->setBf(1);
				break;
			}
			else
			{
				if(((y->getBf() == 1) && (y->getLeft() == z)) || ((y->getBf() == -1) && (y->getRight() == z)))
				{
					///// przypadek 2
					y->setBf(0);
					z=y;
					y=y->getParent();
				}
				else
				{
					if(y->getLeft() == z) t = y->getRight(); else t = y->getLeft();
					if(t->getBf()!=0)
					{
						// przypadek 3.1
						if(y->getBf() == 1) RotateLL(y); else RotateRR(y);
						break;
					}
					else if(y->getBf() == t->getBf())
					{
						// przypadek 3.2
						if(y->getBf() == 1) RotateLL(y); else RotateRR(y);
						z = t; 
						y = t->getParent();
					}
					else
					{
						// przypadek 3.3
						if(y->getBf() == 1) RotateLR(y); else RotateRL(y);
						z = y->getParent();
						y=z->getParent();
					}
				}
			}
		}
	}
	return(x);
}

Node* AVLtree::successor(Node* i)
{
	Node* tmp;


	if(i!=max())
	{
		if(i->getRight()!=NULL)
		{
			return (min(i->getRight()));
		}
		else
		{
			tmp = i->getParent();
			while((tmp != NULL) && (i==tmp->getRight()))
			{
				i=tmp;
				tmp=tmp->getParent();
			}
			return(tmp);
		}
	}
	return(i);
}

Node* AVLtree::predecessor(Node* i)
{
	Node* tmp;


	if(i!=min())
	{
		if(i->getLeft()!=NULL)
		{
			return (max(i->getLeft()));
		}
		else
		{
			tmp = i->getParent();
			while((tmp != NULL) && (i==tmp->getLeft()))
			{
				i=tmp;
				tmp=tmp->getParent();
			}
			return(tmp);
		}
	}
	return(i);
}
