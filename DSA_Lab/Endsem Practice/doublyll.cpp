#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
}root1,root2;

node* newnode(int data){
	node* temp = new node();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
}

void insert(node* root, int key){
	node* temp = root;
	node* p = newnode(key);
	if(root == NULL){
		root = p;
		p->left = root;
	}
	else if(temp->data > key){
		p->right = temp;
		temp->left = p;
		root = p;
		p->left = root;
	}
	else{
		while(temp->data < key && temp->right!=NULL){
			if(temp->right->data > key)
				break;
			temp = temp->right;
		}
		if(temp->right!=NULL){
			p->right = temp->right;
			temp->right->left = p;
			temp->right = p;
			p->left = temp;
		}
		else{
			p->left = temp;
			temp->right = p;
		}
	}

}

void merge(node* n1,node* n2){
	node* temp = n2;
	while(temp!=NULL){
		insert(&root1,temp->data);
		temp = temp->right;
	}
}

void delete1(node* root, int k){
	node* temp = root;
	if(root == NULL){
		cout<<"Empty List\n";
	}
	else{
		if(temp->data == k){
			root = temp->right;
			temp->right = NULL;
			delete temp;
		}
		else{
			while(temp->right)
		}
	}
}

void display(node* root){
	node* temp = root;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp = temp->right;
	}
	cout<<"\n";
}

int main(){
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		int z;
		cin>>z;
		insert(&root1,z);
	}
	int m;
	cin>>m;
	for(int i = 0;i<m;i++){
		int z;
		cin>>z;
		insert(&root2,z);
	}
	display(&root1);
	display(&root2);
	merge(&root1,&root2);
	display(&root1);
}



