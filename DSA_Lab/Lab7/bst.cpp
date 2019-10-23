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
					ancestor = ancestor->left;
				}
				else
					ancestor = ancestor->right;
			}
			return successor;
		}
	}


TreeNode* predecessor(TreeNode* root, int data) {
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
					predecessor = ancestor;
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
	cout<<root->val<<" ";
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
	int choice;

	// cout<<"Enter the number of elements to be inserted in the tree: ";
	// int n;
	// cin>>n;
	// cout<<"Enter the elements: ";
	// while(n--){
	// 	int k;
	// 	cin>>k;
	// 	root = insert(root,k);
	// }

	// cout<<"The max. element is "<<findmax(root)->val<<endl;

	// cout<<"The min. element is "<<findmin(root)->val<<endl;
	// cout<<"-----------------------------------"<<endl;
	 
	//  cout<<"Enter the number to be searched\n";
	//  int num;
	//  cin>>num;
	//  if(search(root,num)== true)
	//  	cout<<"Found\n";
	//  else
	//  	cout<<"Not Found\n";

	//  cout<<"Enter the number to be Deleted\n";
	//  int num1;
	//  cin>>num1;
	//  if(search(root,num1)== true)
	//  	Delete(root,num1);
	//  else
	//  	cout<<"This number is not found on the tree\n";
	 

	//  cout<<"The max. element is "<<findmax(root)->val<<endl;

	//  cout<<"The min. element is "<<findmin(root)->val<<endl;
	
	// preorder(root);
	// cout<<"---------------"<<endl;
	// leveltraversal(root);
	// cout<<endl;
	
	// cout<<"Enter the number to find predecessor\n";
	//  int num2;
	//  cin>>num2;
	//  if(search(root,num2)== true)
	//  	cout<<"Predecessor of "<<num2<<" is: "<<predecessor(root,num2)->val<<endl;
	//  else
	//  	cout<<"This number is not found on the tree\n";

	//  cout<<"Enter the number to find successor\n";
	//  int num3;
	//  cin>>num3;
	//  if(search(root,num3)== true)
	//  	cout<<"Successor of "<<num3<<" is: "<<successor(root,num3)->val<<endl;
	//  else
	//  	cout<<"This number is not found on the tree\n";

	 do
    {
        cout<<"Select Yout Choice\n";
		cout<<" 1. Insert\n 2. Search\n 3. Max element\n 4. Min element\n 5. successor\n 6. predecessor\n 7. Delete\n 8. Preorder Traversal Print\n 9.Level Traversal Print\n";
        cin>>choice;
        switch (choice)
        {
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
               	cout<<"The max. element is: "<<findmax(root)->val<<endl;
                break;
            case 4:
               	cout<<"The min. element is: "<<findmin(root)->val<<endl;
                break;
            case 5:
            	int k;
            	cout<<"Enter the key to find successor: \n";
            	cin>>k;

               	cout<<"The successor element is: "<<successor(root,k)->val<<endl;
                break;
            case 6:
            	int k1;
            	cout<<"Enter the key to find predecessor: \n";
            	cin>>k1;

               	cout<<"The predecessor element is: "<<predecessor(root,k)->val<<endl;
                break;
            case 7:
            	int d;
				cout<<"Enter the key to be deleted\n";
				cin>>d;
				root = Delete(root, d);
                break;
            case 8:
            	cout << "Preorder traversal of the BST is \n";  
    			preorder(root);
    			cout<<"\n";
    			break;
    		case 9:
            	cout << "Level order traversal of the BST is \n";  
    			leveltraversal(root);
    			cout<<"\n";
    			break;
            default:
               cout<<"WRONG CHOICE";
        }
    } while (choice != 0);

}