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
};

Node::~Node(){	;}

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


//*****************************TREE**********************************
class Tree
{
private:
	Node* root;
	void setRoot(Node*); 
public:
	Tree();
	~Tree();
	Node* getRoot();
	void add(int);
	void addRandom(int);
	void remove(int);
	void search(int);
	void display(Node*);
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
		Node* i = root;
		while (i!=NULL)
		{
			if(nju->getKey() < i->getKey())
			{
				if(i->getLeft() == NULL)
				{
					i->setLeft(nju);
					nju->setParent(i);
				}
				else
				i=i->getLeft();
			}
			else if(nju->getKey() > i->getKey())
			{
				if(i->getRight() == NULL)
				{
					i->setRight(nju);
					nju->setParent(i);
				}

				i=i->getRight();
			}
			else if(nju->getKey() == i->getKey())
			{
				cout << "Taki element istnieje" << endl;
			}
		}
	}
}

void Tree::display(Node* _root)
{
	if(_root!=NULL)
	{
		display(_root->getLeft());
		cout << " " << _root->getKey() << " ";
		display(_root->getRight());
	}

}


//*****************************main**********************************
int _tmain(int argc, _TCHAR* argv[])
{
	Tree tree1;
	tree1.add(10);
	tree1.add(11);
//	tree1.add(9);
	tree1.display(tree1.getRoot());

	system("pause");
	return 0;
}
