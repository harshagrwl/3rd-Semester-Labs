#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* next;
};



Node* merge(Node* a, Node* b){
	Node* ans = NULL;

	if(a==NULL)
		return b;
	else if(b==NULL)
		return a;

	if(a->data <= b->data){
		ans = a;
		ans->next = merge(a->next,b);
	}
	else{
		ans = b;
		ans->next = merge(a,b->next);
	}

	return ans;
}

void divide(Node* head, Node* a, Node* b){
	Node *slow, *fast;
	slow = head;
	fast = head->next;
	while(fast!=NULL){
		fast = fast->next;
		while(fast!=NULL){
			slow=slow->next;
			fast = fast->next;
		}
	}
	a = head;
	b = slow->next;
	slow->next = NULL;
}

Node* sort(Node* head){
	Node* temp = head;
	if((temp== NULL) || (temp->next == NULL))
		return head;
	Node* a;
	Node* b;
	divide(head,a,b);
	sort(a);
	sort(b);

	head = merge(a,b);
	return head;
}

Node* insert(Node* head, int data){
	Node* newnode = new Node();
	newnode->data = data;
	newnode->next = head;
	head = newnode;
	return head;
}

void print(Node* head){
	Node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

int main(){
	Node* n = NULL;
	n = insert(n,10);
	n = insert(n,12);
	n = insert(n,3);
	n = insert(n,25);
	n = insert(n,6);
	print(n);
	n = sort(n);

	print(n);
	return 0;
}