#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

TreeNode* makenode(int data){
	TreeNode* newnode = new TreeNode();
	newnode->val = data;
	newnode->left = newnode->right = NULL;
	return newnode;
}

TreeNode* insert(TreeNode* root, int data){
	if(root == NULL){
		root = makenode(data);
	}
	else if (data <= root->val){
		root->left = insert(root->left,data);
	}
	else
		root->right = insert(root->right,data);
	return root;
}

bool search(TreeNode* root, int data){
	if(root == NULL)
		return false;
	else if(root->val == data)
		return true;
	else if(data <= root->val)
		return search(root->left,data);
	else
		return search(root->right,data);
}

TreeNode* Find(TreeNode* root, int data){
	if(root == NULL)
		return NULL;
	else if(root->val == data)
		return root;
	else if(data <= root->val)
		return Find(root->left,data);
	else
		return Find(root->right,data);
}

TreeNode* findmax(TreeNode* root){
	while(root->right!=NULL)
		root = root->right;
	return root;
}

TreeNode* findmin(TreeNode* root){
	while(root->left!=NULL)
		root = root->left;
	return root;
}

TreeNode* Delete(TreeNode* root, int data){
	if(root == NULL)
		return NULL;
	else if(data < root->val)
		root->left = Delete(root->left,data);
	else if(data > root->val)
		root->right = Delete(root->right,data);
	else{
		if(root->left == NULL && root->right == NULL){
			delete root;
			root = NULL;
		}
		else if(root->left == NULL){
			struct TreeNode* temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL){
			struct TreeNode* temp = root;
			root = root->left;
			delete temp;
		}
		else{
			struct TreeNode* temp = findmin(root->right);
			root->val = temp->val;
			root->right = Delete(root->right,temp->val);
		}
		return NULL;
	}
}

TreeNode* successor(TreeNode* root, int data){
		struct TreeNode* curr = Find(root,data);
		if(curr == NULL)
			return NULL;
		if(curr->right!=NULL)
			return findmin(curr->right);
		else{
			struct TreeNode* ancestor = root;
			struct TreeNode* successor = NULL;
			while(ancestor!=curr){
				if(curr->val < ancestor->val){
					successor = ancestor;
					successor= ancestor->left;
				}
				else
					successor = ancestor->right;
			}
			return NULL;
		}

}

TreeNode* predecessor(TreeNode* root, int data){
		struct TreeNode* curr = Find(root,data);
		if(curr == NULL)
			return NULL;
		if(curr->left!=NULL)
			return findmax(curr->left);
		else{
			struct TreeNode* ancestor = root;
			struct TreeNode* predecessor = NULL;
			while(ancestor!=curr){
				if(curr->val > ancestor->val){
					ancestor = ancestor;
					ancestor = ancestor->right;
				}
				else
					ancestor = ancestor->left;
			}
			return predecessor;
		}

}

void preorder(TreeNode* root){
	if(root == NULL)
		return;
	cout<<root->val<<endl;
	preorder(root->left);
	preorder(root->right);
}

void leveltraversal(TreeNode* root){
	if(root == NULL)
		return;
	queue<TreeNode*> Q;
	Q.push(root);
	while(!Q.empty()){
		TreeNode* curr = Q.front();
		cout<<curr->val<<" ";
		if(curr->left!=NULL)
			Q.push(curr->left);
		if(curr->right!=NULL)
			Q.push(curr->right);
		Q.pop();
	}
}

int main(){
	TreeNode* root = NULL;
	root = insert(root,10);
	root = insert(root,15);
	root = insert(root,20);
	root = insert(root,35);
	root = insert(root,75);
	cout<<"The max. element is "<<findmax(root)->val<<endl;
	cout<<"The min. element is "<<findmin(root)->val<<endl;
	cout<<"-----------------------------------"<<endl;
	 int num;
	 cout<<"Enter the number to be searched\n";
	 cin>>num;
	 if(search(root,num)== true)
	 	cout<<"Found\n";
	 else
	 	cout<<"Not Found\n";
	 Delete(root,75);
	 Delete(root,10);
	 cout<<"The max. element is "<<findmax(root)->val<<endl;
	 cout<<"The min. element is "<<findmin(root)->val<<endl;
	Delete(root,15);
	preorder(root);
	cout<<"---------------"<<endl;
	leveltraversal(root);
	cout<<endl;
	cout<<"predecessor of 35 is "<<predecessor(root,35)->val<<endl;
}