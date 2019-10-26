#include<bits/stdc++.h>
using namespace std;

struct Node{
	int key;
	struct Node* left;
	struct Node* right;
};

struct Node *newNode(int k) { 
    struct Node *node = new Node(); 
    node->key = k; 
    node->right = node->left = NULL; 
    return node;
} 

int countNodes(struct Node* root){ 
    if (root == NULL) 
        return (0); 
    return (1 + countNodes(root->left) + countNodes(root->right)); 
} 
bool complete(struct Node* root, int index, int nodes){
	if(root == NULL){
		return true;
	}
	if(index >= nodes)
		return false;

	return ((complete(root->left,2*index+1,nodes)) && (complete(root->right,2*index+2,nodes)));
}

bool heap(struct Node* root){
	if(root->left == NULL && root->right == NULL)
		return true;
	if(root->right == NULL){
		if(root->key >= root->left->key)
			return true;
	}
	else{
		if(root->key >= root->left->key && root->key >= root->right->key)
			return(heap(root->left) && heap(root->right));
		else
			return false;
	}
}

bool isHeap(struct Node* root) {
    int nodes = countNodes(root); 
    int index = 0;
    if (complete(root, index, nodes) && heap(root)) 
        return true; 
    return false; 
} 

int main() 
{ 
    struct Node* root = NULL; 
    root = newNode(10); 
    root->left = newNode(9); 
    root->right = newNode(8); 
    root->left->left = newNode(7); 
    root->left->right = newNode(6); 
    root->right->left = newNode(5); 
    root->right->right = newNode(4); 
    root->left->left->left = newNode(3); 
    root->left->left->right = newNode(2); 
    root->left->right->left = newNode(1); 
  
    if (isHeap(root)) 
        printf("Given binary tree is a Heap\n"); 
    else
        printf("Given binary tree is not a Heap\n"); 
  
    return 0; 
} 