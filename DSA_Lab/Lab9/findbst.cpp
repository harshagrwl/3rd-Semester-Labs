#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

Node* newnode(int data){
	Node* nnode = new Node();
	nnode->data = data;
	nnode->left = NULL;
	nnode->right = NULL;
	return nnode;
}

Node* insert