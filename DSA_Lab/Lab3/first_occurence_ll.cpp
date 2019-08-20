#include <bits/stdc++.h>
using namespace std;
struct Node { 
   int data; 
   struct Node *next; 
}; 
void insert(struct Node **head, int newdata){
   struct Node* newnode = new Node();
   newnode->data = newdata;
   newnode->next = *head;
   *head = newnode;
}
void find(struct Node **head,int X){
   int count=0;
   Node*temp=*head;
   while(temp!=NULL)
      {
         if(temp->data == X){
            cout<<"Element "<<X<<" found. \n";
            break;
         }
         else{
            cout<<"Element "<<X<<" not found. \n";
         }
         temp=temp->next;
      }
      

}
int main(){
   struct Node *head = NULL;
   int ch, val, key; 
   cout<<"1) Insert in Linked List"<<endl;
   cout<<"2) Find an element in Linked Lsit"<<endl;
   cout<<"3) Exit"<<endl;
   do {
      cout<<"Enter choice: "<<endl;
      cin>>ch;
      switch(ch) {
         case 1: {   
            cout<<"Enter value to be pushed:"<<endl;
            cin>>val;
            insert(&head, val);
            break;
         }
         case 2: {
            cout<<"Enter value to be searched:"<<endl;
            cin>>key;
            find(&head, key);
            break;
         }
         case 3: {
            cout<<"Exit"<<endl;
            break;
         }
         default: {
            cout<<"Invalid Choice"<<endl;
         }
      }
   }while(ch!=3); 
      return 0;
}  
