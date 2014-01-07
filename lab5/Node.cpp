#include "stdafx.h"
#include "Node.h"


Node::~Node(){	;}

Node::Node()
{
	key=bf=NULL;
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

int Node::getBf()
{
	return(bf);
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

void Node::setBf(int _bf)
{
	bf=_bf;
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
