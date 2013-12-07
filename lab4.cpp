// lab3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>

using namespace std;

//*****************************NODE**********************************
class Node
{
private:
	Node* left;
	Node* right;
	Node* parent;
	int key;
public:
	Node();
	Node(int);
	Node(int, Node*);
	~Node();
	int getKey();
	Node* getLeft();
	Node* getRight();
	Node* getParent();
	void setKey(int);
	void setLeft(Node*);
	void setRight(Node*);
	void setParent(Node*);
	int sons();
};

Node::~Node(){	;}

Node::Node()
{
	key=NULL;
	parent=right=left=NULL;
}

Node::Node(int _key)
{
	key=_key;
	parent=right=left=NULL;
}

Node::Node(int _key, Node* _parent)
{
	key=_key;
	parent=_parent;
	right=left=NULL;
}

int Node::getKey()
{
	return(key);
}

Node* Node::getLeft()
{
	return(left);
}

Node* Node::getRight()
{
	return(right);
}

Node* Node::getParent()
{
	return(parent);
}

void Node::setKey(int _key)
{
	key=_key;
}

void Node::setLeft(Node* _left)
{
	left = _left;
}

void Node::setRight(Node* _right)
{
	right = _right;
}

void Node::setParent(Node* _parent)
{
	parent = _parent;
}

int Node::sons()
{
	int i=0;
	if(getLeft()!=NULL) i++;
	if(getRight()!=NULL) i++;
	return(i);
}



//*****************************TREE**********************************
class Tree
{
private:
	Node* root;
	void setRoot(Node*);
	void display(Node*);
	Node* min(Node*);
	Node* max(Node*);

	void predDel(Node*);
	void sucDel(Node*);

	void elementnum(Node*, int*);

	

	int log2(int);
public:
	Tree();
	~Tree();
	Node* getRoot();
	void add(int);
	void addRandom(int);
	Node* search(int);
	void display();
	Node* min();
	Node* max();
	Node* successor(Node*);
	Node* predecessor(Node*);
	int elementnum();

	void removeNode(int);
	void DSW();
	void rotation();
void rotationLeft(Node*);
	void rotationRight(Node*);

};

Tree::~Tree(){;}

Tree::Tree()
{
	root=NULL;
}

void Tree::setRoot(Node* _root)
{
	root = _root;
}

Node* Tree::getRoot()
{
	return(root);
} 

void Tree::add(int key)
{
	Node* nju = new Node(key);
	if(getRoot()==NULL)
	{
		setRoot(nju);
	}
	else
	{
		bool insert(false);
		Node* i = getRoot();
		Node* i_parent = NULL;
		while (!insert)
		{	
			if(nju->getKey() == i->getKey())
			{
				cout << "taki element istnieje" << endl;
				insert=true;
			}
			else if(nju->getKey() < i->getKey())
			{
				if(i->getLeft() == NULL)
				{
					i->setLeft(nju);
					nju->setParent(i);
					insert=true;
				}
				else
				{ 
					i_parent=i;
					i=i->getLeft();
				}
			}
			else if(nju->getKey() > i->getKey())
			{
				if(i->getRight() == NULL)
				{
					i->setRight(nju);
					nju->setParent(i);
					insert=true;
				}
				else
				{
					i_parent=i;
					i=i->getRight();
				}
			}
		}
	}
}


void Tree::display()
{
	Node* tmp=getRoot();
	if(tmp!=NULL)
	{
		display(tmp->getLeft());
		cout << tmp->getKey() << " ";
		display(tmp->getRight());
	}
	
}


void Tree::display(Node* _root)
{
	if(_root!=NULL)
	{
		display(_root->getLeft());
		cout << _root->getKey() << " ";
		display(_root->getRight());
	}
	
}

int Tree::elementnum()
{
	int* num = new int;
	*num = 0;
	Node* tmp = getRoot();
	if(tmp!=NULL)
	{
		elementnum(tmp->getLeft(),num);
		*num=*num+1;
		elementnum(tmp->getRight(),num);
	}
	return(*num);
}

void Tree::elementnum(Node* _root, int* num)
{
	if(_root!=NULL)
	{
		elementnum(_root->getLeft(),num);
		*num=*num+1;
		elementnum(_root->getRight(),num);
	}

}


Node* Tree::search(int _key)
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

Node* Tree::min()
{
	Node* tmp = new Node();
	tmp=getRoot();
	while(tmp->getLeft()!= NULL)
	{
		tmp=tmp->getLeft();
	}
	return(tmp);
}

Node* Tree::min(Node* i)
{
	while(i->getLeft()!= NULL)
	{
		i=i->getLeft();
	}
	return(i);
}


Node* Tree::max()
{
	Node* tmp = new Node();
	tmp=getRoot();
	while(tmp->getRight()!= NULL)
	{
		tmp=tmp->getRight();
	}
	return(tmp);
}

Node* Tree::max(Node* i)
{
	while(i->getRight()!= NULL)
	{
		i=i->getRight();
	}
	return(i);
}


Node* Tree::successor(Node* i)
{
	Node* tmp = new Node();


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

Node* Tree::predecessor(Node* i)
{
	Node* tmp = new Node();


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

void Tree::sucDel(Node* rem)
{
	Node* suc = new Node();
	suc = successor(rem);
	if (suc->getRight()!=NULL)
	{
		if(suc==rem->getRight())
		{
			suc->getParent()->setRight(suc->getRight());
			suc->getRight()->setParent(suc->getParent());
		}
		else
		{
		suc->getParent()->setLeft(suc->getRight());
		suc->getRight()->setParent(suc->getParent());
		}
	}
	rem->setKey(suc->getKey());
	if(rem->getRight()==suc) rem->setRight(NULL);

	delete suc;
}
void Tree::predDel(Node* rem)
{
	Node* pred = new Node();
	pred = predecessor(rem);
	if (pred->getLeft()!=NULL)
	{
		if(pred==rem->getLeft())
		{
		pred->getParent()->setLeft(pred->getLeft());
		pred->getLeft()->setParent(pred->getParent());
		}
		else
		{
		pred->getParent()->setRight(pred->getLeft());
		pred->getLeft()->setParent(pred->getParent());
		}

	}
	rem->setKey(pred->getKey());
	if(rem->getLeft()==pred) rem->setLeft(NULL);
	delete pred;

}

void Tree::removeNode(int _key)
{
	Node* i = new Node();
	i = search(_key);

	if(i!=NULL)
	{
		if(i->sons()==0 )
		{
			if(i->getParent()!=NULL)
			{
				if(i->getParent()->getLeft()==i)
				{
					i->getParent()->setLeft(NULL);
					delete i;
				}
				else if(i->getParent()->getRight()==i)
				{
					i->getParent()->setRight(NULL);
					delete i;
				}
			}
			else delete i;
		}
		else if(i->sons()==1)
		{
			if(i->getParent()!=NULL)
			{
				if(i->getLeft()!=NULL)
				{
					if((i->getParent()->getLeft()) == i)
					{
						i->getParent()->setLeft(i->getLeft());
						delete i;
					}
					else if((i->getParent()->getRight()) == i)
					{
						i->getParent()->setRight(i->getLeft());
						delete i;
					}
				}
			
			else if(i->getRight()!=NULL)
			{
					if((i->getParent()->getLeft()) == i)
					{
						i->getParent()->setLeft(i->getRight());
						delete i;
					}
					else if ((i->getParent()->getRight()) == i)
					{
						i->getParent()->setRight(i->getRight());
						delete i;
					}
			}
			}
		}
		else if (i->sons()==2)
		{
			predDel(i);
			//sucDel(i);
		}

	}

}

void Tree::addRandom(int quant)
{
	for(int i=0;i<quant;i++)
	{
		add((rand() % 100000 << 16)+rand() % 100000);
	}

}

void Tree::rotationRight(Node* A)
{
	Node* B = new Node();

B=A->getLeft();
if (B!=NULL)
{
	Node* p = new Node();
	p=A->getParent();
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
		if(p->getLeft()==A)
		{
			if(p->getParent()==NULL)
			{
				getRoot()->setLeft(B);
			}
			else
			{
				p->setLeft(B);
			}

		}
		else
		{
			if(p->getParent()==NULL)
			{
				getRoot()->setRight(B);
			}
			else
			{
				p->setRight(B);
			}
		}

	}
	else
	{
		Node* tmp = new Node();
		tmp = A;
		tmp->getRight()->setParent(tmp);
		setRoot(B);
		root->setRight(tmp);
		root->setParent(B->getParent());
	}



}


}

void Tree::rotationLeft(Node* A)
{
Node* B = new Node();

B=A->getRight();
if (B!=NULL)
{
	Node* p = new Node();
	p=A->getParent();
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
		if(p->getLeft()==A)
		{
			if(p->getParent()==NULL)
			{
				getRoot()->setLeft(B);
			}
			else
			{
				p->setLeft(B);
			}

		}
		else
		{
			if(p->getParent()==NULL)
			{
				getRoot()->setRight(B);
			}
			else
			{
				p->setRight(B);
			}
		}

	}
	else
	{
		Node* tmp = new Node();
		tmp = A;
		if(tmp->getLeft()!=NULL)
		{
			tmp->getLeft()->setParent(tmp);
		}
		setRoot(B);
		root->setLeft(tmp);
		root->setParent(B->getParent());
	}



}


}

int Tree::log2(int x)
{
	int y=1;

	while( x > 0 ) 
	{
		x=(x>>1);
		y =(y<<1);
	}
	return(y);
}

void Tree::DSW()
{
	int n=0;
	int s=0;
	int o=0;
	Node* p = new Node();
	p=getRoot();

	while (p!=NULL)
	{
		if(p->getLeft()!=NULL)
		{
			rotationRight(p);
			if(p->getParent()!=NULL)
			{
				p=p->getParent();
			}
		}
		else
		{
		n++;
		p=p->getRight();
		}
	}
	s=n+1-log2(n+1);
	p=getRoot();
	for(int i = 0; i < s; i++)
	{
		rotationLeft(p);
		if(p->getParent()!=NULL) {p=p->getParent()->getRight();}
	}
	n=n-s;
	while(n>1)
	{
		n=n >> 1;
		p=getRoot();
		for (int i = 0; i < n; i++)
		{
			rotationLeft(p);
			if(p->getParent()!=NULL)
			{
					p=p->getParent()->getRight();
			}
			else
			{
				p=p->getRight();
			}
			

		}
	}

	
}

//*****************************main**********************************
int _tmain(int argc, _TCHAR* argv[])
{
	int a;
	srand(time(NULL));
	
/*	Tree* tree1 = new Tree();
    tree1->add(20);
	tree1->add(30);
	tree1->add(10);
	//tree1->add(15);
	tree1->add(25);
	tree1->add(15);
	tree1->add(tree1->max()->getKey()+1);
	tree1->add(tree1->min()->getKey()-1);
	tree1->add(22);
	tree1->add(23);
	tree1->display();
	cout << endl;
	tree1->search(11);
	cout << endl;
	cout << tree1->successor(tree1->search(31))->getKey();
	cout << endl;
	cout << tree1->predecessor(tree1->search(20))->getKey() << endl;
	//tree1->removeNode(9);
	//tree1->removeNode(30);
	tree1->display();
	cout << endl<<endl;
	cout << tree1->getRoot()->getKey();
	tree1->DSW();
	//tree1->rotationLeft(tree1->search(20));
	//tree1->rotationLeft(tree1->search(23));

	cout << endl<<endl;
	cout << tree1->getRoot()->getKey();
	cout << endl<<endl;

	tree1->display();


	*/

	/*	cout << "Usun: ";
	cin >> a ;

	tree1->removeNode(a);
	*/
//	tree1->display();

	cout<< endl<< endl;

	Tree* tree2 = new Tree();

	tree2->add(9);
	tree2->add(5);
	tree2->add(7);
	tree2->add(15);
	tree2->add(10);
	tree2->add(18);
	tree2->add(19);

	cout << endl;
	tree2->display();
	cout << tree2->getRoot()->getKey()<<endl;
	tree2->DSW();

	cout << tree2->getRoot()->getKey();


	cout << endl;



	Tree* tree3 = new Tree();

/*	tree3->add(9);
	tree3->add(15);
	tree3->add(5);
	tree3->add(7);
	tree3->add(10);
	tree3->add(18);
	tree3->add(19);

	tree3->rotationRight(tree3->search(9));

	cout << tree3->search(9)->getParent()->getKey()<<endl;
	cout << tree3->search(9)->getLeft()->getKey()<<endl;
	cout << tree3->search(9)->getRight()->getKey()<<endl;

	tree3->rotationRight(tree3->search(9));

	cout << tree3->search(9)->getParent()->getKey()<<endl;
	cout << tree3->search(9)->getLeft()<<endl;
	cout << tree3->search(9)->getRight()->getKey()<<endl;
	
	tree3->rotationRight(tree3->search(15));

	cout << tree3->search(9)->getRight()<<endl;
	cout << tree3->search(7)->getParent()->getKey()<<endl;
	tree3->rotationLeft(tree3->search(5));

	cout << tree3->search(7)->getParent()<<endl;
	cout << tree3->search(7)->getLeft()<<endl;
	cout << tree3->search(7)->getRight()<<endl;
	tree3->rotationLeft(tree3->search(9));
	tree3->rotationLeft(tree3->search(15));
	tree3->rotationLeft(tree3->search(7));
	cout << tree3->getRoot()->getKey()<<endl;;
	cout << tree3->search(18)->getParent()->getKey()<<endl;
	cout << tree3->search(18)->getLeft()->getKey()<<endl;
	cout << tree3->search(18)->getRight()->getKey()<<endl;

*/
	system("pause");
	return 0;
}
