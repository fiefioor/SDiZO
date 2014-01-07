#pragma once
class Node
{
private:
	Node* left;
	Node* right;
	Node* parent;
	int key;
	int bf; //balance factor
public:
	Node();
	Node(int);
	Node(int, Node*);
	~Node();
	int getKey();
	int getBf();
	Node* getLeft();
	Node* getRight();
	Node* getParent();
	void setKey(int);
	void setBf(int);
	void setLeft(Node*);
	void setRight(Node*);
	void setParent(Node*);
	int sons();
};

