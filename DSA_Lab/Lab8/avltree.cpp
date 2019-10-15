#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int key;
	Node* left;
	Node*right;
	int height;
};
Node* newnode(int key){
	Node* node = new Node();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
}

int height(Node *N)  
{  
    if (N == NULL)  
        return 0;  
    return N->height;  
}

Node* lrotate(Node* z){
	Node* y = z->right;
	Node* T = y->left;

	y->left = z;
	z->right = T;

	z->height  = max(height(z->left),height(z->right))+1;
	y->height  = max(height(y->left),height(y->right))+1;

	return y;	
}
Node* rrotate(Node* z){
	Node* y = z->left;
	Node* T = y->right;

	y->right = z;
	z->left = T;

	z->height  = max(height(z->left),height(z->right))+1;
	y->height  = max(height(y->left),height(y->right))+1;

	return y;	
}

bool search(Node* root, int data){
	if(root == NULL)
		return false;
	else if(root->key == data)
		return true;
	else if(data <= root->key)
		return search(root->left,data);
	else
		return search(root->right,data);
}

Node* Find(Node* root, int data){
	if(root == NULL)
		return NULL;
	else if(root->key == data)
		return root;
	else if(data <= root->key)
		return Find(root->left,data);
	else
		return Find(root->right,data);
}

Node* findmax(Node* root){
	while(root->right!=NULL)
		root = root->right;
	return root;
}

Node* findmin(Node* root){
	while(root->left!=NULL)
		root = root->left;
	return root;
}

Node* successor(Node* root, int data){
		Node* curr = Find(root,data);
		if(curr == NULL)
			return NULL;
		if(curr->right!=NULL)
			return findmin(curr->right);
		else{
			Node* ancestor = root;
			Node* successor = NULL;
			while(ancestor!=curr){
				if(curr->key < ancestor->key){
					successor = ancestor;
					successor= ancestor->left;
				}
				else
					successor = ancestor->right;
			}
			return NULL;
		}

}

Node* predecessor(Node* root, int data){
		Node* curr = Find(root,data);
		if(curr == NULL)
			return NULL;
		if(curr->left!=NULL)
			return findmax(curr->left);
		else{
			Node* ancestor = root;
			Node* predecessor = NULL;
			while(ancestor!=curr){
				if(curr->key > ancestor->key){
					ancestor = ancestor;
					ancestor = ancestor->right;
				}
				else
					ancestor = ancestor->left;
			}
			return predecessor;
		}

}

Node* insert(Node* node, int key){
	if(node == NULL){
		return newnode(key);
	}
	if(key < node->key){
		node-> left = insert(node->left, key);
	}
	else if(key > node->key){
		node-> right = insert(node->right, key);
	}

	node->height  = max(height(node->left),height(node->right))+1;

	int balance;
	if(node == NULL){
		balance = 0;
	}
	else
		balance = height(node->left) - height(node->right);


	//Case 1 LL
	if(balance > 1 && key < node->left->key){
		return rrotate(node);
	}
	//Case 2 LR
	if(balance > 1 && key > node->left->key){
		node->left = lrotate(node->left);
		return rrotate(node);
	}
	//Case 3 RR
	if(balance < -1 && key > node->right->key){
		return lrotate(node);
	}
	//Case 4 RL
	if(balance < -1 && key < node->right->key){
		node->right = rrotate(node->right);
		return lrotate(node);
	}

	return node;
}

int getBalance(Node *N){  
    if (N == NULL)  
        return 0;  
    return height(N->left) - height(N->right);  
}  

Node* Delete(Node* root, int data){
	if(root == NULL)
		return root;
	else if(data < root->key)
		root->left = Delete(root->left,data);
	else if(data > root->key)
		root->right = Delete(root->right,data);
	else{
		if(root->left == NULL && root->right == NULL){
			delete root;
			root = NULL;
		}
		else if(root->left == NULL){
			struct Node* temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL){
			struct Node* temp = root;
			root = root->left;
			delete temp;
		}
		else{
			struct Node* temp = findmin(root->right);
			root->key = temp->key;
			root->right = Delete(root->right,temp->key);
		}
	}
	if (root == NULL)  
    	return root;

    root->height = 1 + max(height(root->left),height(root->right));
    int balance;
	if(root == NULL){
		balance = 0;
	}
	else
		balance = height(root->left) - height(root->right);

	// LL 
    if (balance > 1 && getBalance(root->left) >= 0)  
        return rrotate(root);  
  
    // LR 
    if (balance > 1 && getBalance(root->left) < 0)  
    {  
        root->left = lrotate(root->left);  
        return rrotate(root);  
    }  
  
    // RR 
    if (balance < -1 && getBalance(root->right) <= 0)  
        return lrotate(root);  
  
    // RL
    if (balance < -1 && getBalance(root->right) > 0)  
    {  
        root->right = rrotate(root->right);  
        return lrotate(root);  
    }

    return root;

}
void preordert(Node* root){
	if(root!=NULL){
		cout<< root->key <<" ";
		preordert(root->left);
		preordert(root->right);
	}
}

int main(){
	Node* root  = NULL;
	int choice;
	

	do
    {
        cout<<"Select Yout Choice\n";
		cout<<" 1. Insert\n 2. Search\n 3. Max element\n 4. Min element\n 5. successor\n 6. predecessor\n 7. Delete\n 8. Preorder Traversal Print\n";
        cin>>choice;
        switch (choice)
        {
            case 1:
                int v;
				cout<<"Enter the key to be inserted\n";
				cin>>v;
				root = insert(root, v);
                break;
            case 2:
            	int x;
                cout << "Enter the element to be searched \n";
    			cin>>x;
    			if(search(root,x)){
    				cout<<"The element is present\n";

   				}
   				else
    				cout<<"The element is not present\n";

                break;
            case 3:
               	cout<<"The max. element is: "<<findmax(root)->key<<endl;
                break;
            case 4:
               	cout<<"The min. element is: "<<findmin(root)->key<<endl;
                break;
            case 5:
            	int k;
            	cout<<"Enter the key to find successor: \n";
            	cin>>k;

               	cout<<"The successor element is: "<<successor(root,k)->key<<endl;
                break;
            case 6:
            	int k1;
            	cout<<"Enter the key to find predecessor: \n";
            	cin>>k1;

               	cout<<"The predecessor element is: "<<predecessor(root,k)->key<<endl;
                break;
            case 7:
            	int d;
				cout<<"Enter the key to be deleted\n";
				cin>>d;
				root = Delete(root, d);
                break;
            case 8:
            	cout << "Preorder traversal of the AVL tree is \n";  
    			preordert(root);
    			cout<<"\n";
    			break;
            default:
               cout<<"WRONG CHOICE";
        }
    } while (choice != 0);

	
	return 0;
}