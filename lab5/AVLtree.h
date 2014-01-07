#pragma once
#include"Node.h"
class AVLtree
{
private:
        Node* root;
        void setRoot(Node*);
        void display(Node*);
		void displayBf(Node*);
        Node* min(Node*);
        Node* max(Node*);

        void predDel(Node*);
        void sucDel(Node*);

public:
        AVLtree();
        ~AVLtree();
        Node* getRoot();
        void add(int);
        void addRandom(int);
        Node* search(int);
        void display();
		void displayBf();
        Node* min();
        Node* max();
        Node* successor(Node*);
        Node* predecessor(Node*);

		///////rotacje pojedyncze
		void RotateRR(Node*);
		void RotateLL(Node*);

		///////rotacje podwojne
		void RotateLR(Node*);
		void RotateRL(Node*);

		///////usuwanie elementu
        Node* removeNode(int);
};

