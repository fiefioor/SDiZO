// lab3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

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

	void removeNode(int);
	
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
	if (suc->sons()==1)
	{
		suc->getParent()->setLeft(suc->getRight());
		suc->getRight()->setParent(suc->getParent());
	}
	rem->setKey(suc->getKey());
	delete suc;
}
void Tree::predDel(Node* rem)
{
	Node* pred = new Node();
	pred = predecessor(rem);
	if (pred->sons()==1)
	{
		pred->getParent()->setRight(pred->getLeft());
		pred->getLeft()->setParent(pred->getParent());
	}
	rem->setKey(pred->getKey());
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

//*****************************main**********************************
int _tmain(int argc, _TCHAR* argv[])
{
	Tree* tree1 = new Tree();
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
	tree1->removeNode(9);
//	tree1->removeNode(30);
	tree1->display();

	cout << endl;
	system("pause");
	return 0;
}
