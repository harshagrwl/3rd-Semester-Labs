#include <bits/stdc++.h>
using namespace std;
struct Node { 
   int data; 
   struct Node *next; 
};
struct Node* head = NULL;
Node* insert(int newdata){
   struct Node* newnode = new Node();
   newnode->data = newdata;
   newnode->next = head;
   head = newnode;
}
void sort (){
	if(head == NULL || head->next == NULL){
		return;
	}
	Node* last = head;
	int num = 1;
	while(last->next!=NULL){
		last = last->next;
		num++;
	}
	Node* ptr = head;
	Node* front = head;
	Node* rear = last;

	for(int i=0;i<num;i++){
		Node* temp = ptr;
		ptr = ptr->next;

		if(temp->data == 0){
			if(front!=temp){
				temp->next = head;
				head = temp;
				front->next = ptr;
			}
		}
		else if(temp->data == 2){
			rear->next = temp;
			temp->next = NULL;
			rear = temp;

			if(front == temp)
				head = front = ptr;
			else(int i=0;i<num;i++){
		Node* temp = ptr;
		ptr = ptr->ne
				front->next = ptr;
		}
		else{
			if(front!=temp)
				front = front->next;
		}
	}
}

void print(){
	Node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

int main(){
	struct Node *head = NULL;
   int ch, val, key; 
   cout<<"1) Insert in Linked List"<<endl;
   cout<<"2) Sort the list"<<endl;
   cout<<"3) Print the list"<<endl;
   cout<<"4) Exit"<<endl;
   do {
      cout<<"Enter choice: "<<endl;
      cin>>ch;
      switch(ch) {
         case 1: {   
            cout<<"Enter value to be entered:"<<endl;
            cin>>val;
            insert(val);
            break;
         }
         case 2: {        
            sort();
            break;
         }
         case 3: {
         	print();
            break;
         }
         case 4: {
         	cout<<"Exit"<<endl;
         	break;
         }
         default: {
            cout<<"Invalid Choice"<<endl;
         }
      }
   }while(ch!=4); 
      return 0;
}  