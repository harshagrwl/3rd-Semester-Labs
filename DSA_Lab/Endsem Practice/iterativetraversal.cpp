#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};

Node* newnode(int data){
	Node* node = new Node();
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

Node* insert(Node* root, int data){
	if(root == NULL){
		root = newnode(data);
	}
	else if (data <= root->data){
		root->left = insert(root->left,data);
	}
	else
		root->right = insert(root->right,data);
	return root;
}

int countnodes(Node* root){
	if(root==NULL)
		return 0;
	return 1+countnodes(root->left)+countnodes(root->right);
}

void preorder(Node* root){
	if(root == NULL)
		return;
	int c = countnodes(root);
	Node* arr[c];
	int top = -1;
	arr[++top] = root;
	while(top>=0){
		Node* node = arr[top--];
		cout<<node->data<<" ";
		if(node->right){
			arr[++top] = node->right;
		}
		if(node->left){
			arr[++top] = node->left;
		}
	}
}

void inorder(Node* root){
	if(root == NULL)
		return;
	int c = countnodes(root);
	Node* arr[c];
	int top = -1;
	Node* curr = root;
	while(curr!=NULL || top>= 0){
	while(curr!=NULL){
		arr[++top] = curr;
		curr = curr->left;
	}
	
	curr = arr[top--];
		
	cout<<curr->data<<" ";
	curr = curr->right;
	}
}


void postorder(Node* root){
	if(root == NULL)
		return;
	int c = countnodes(root);
	Node* arr[c];
	Node* arr2[c];
	int top = -1,top2 = -1;
	arr[++top] = root;
	while(top>=0){
		Node* node = arr[top--];
		arr2[++top2] = node;
		if(node->left){
			arr[++top] = node->left;
		}
		if(node->right){
			arr[++top] = node->right;
		}
	}
	while(top2>=0){
		Node* node2 = arr2[top2--];
		cout<<node2->data<<" ";
	}
}


int main(){
	Node* root = NULL;
	int choice;
	do{
		cout<<"1.Insert\n 2.Preorder\n 3.In\n 4. Post\n";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter the number of elements to be inserted in the tree: ";
				int n;
				cin>>n;
				cout<<"Enter the elements: ";
				while(n--){
					int k;
					cin>>k;
					root = insert(root,k);
				}
                break;
            case 2:
            	cout << "Preorder traversal of the BST is \n";  
    			preorder(root);
    			cout<<"\n";
    			break;
    		case 3:
    			cout << "Inorder traversal of the BST is \n";  
    			inorder(root);
    			cout<<"\n";
    			break;
    		case 4:
    			cout << "Postorder traversal of the BST is \n";  
    			postorder(root);
    			cout<<"\n";
    			break;
    		default:
    			cout<<"WRONG CHOICE";
		}
	}
	while(choice!=0);
}