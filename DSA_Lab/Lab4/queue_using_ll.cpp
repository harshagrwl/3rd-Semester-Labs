#include <bits/stdc++.h>
using namespace std;
class Node{
public:
   int data;
   Node* next;
};

class Queue{
public:
   Node *front, *rear;
};

Node* newnode (int x){
   Node *temp = new Node();
   temp->data = x;
   temp->next = NULL;
   return temp;
}

Queue* newqueue(){
   Queue *qu = new Queue();
   qu->front = qu->rear = NULL;
   return qu;
}

void enqueue(Queue *q, int k){
   Node *temp = newnode(k);
   if(q->rear == NULL){
      q->front = q->rear = temp;
      return;
   }
   q->rear->next = temp;
   q->rear = temp;
   
}

Node* dequeue(Queue *q){
   if (q->front == NULL){
      return NULL;
   }
   Node* temp = q->front;
   q->front = q->front->next;

   if(q->front == NULL){
      q->rear = NULL;
   }
   //cout<<"Dequeued "<<temp->data<<" from Queue"<<endl;
   return temp;
   delete temp;
}

int main(){
   Queue* q = newqueue();
   int ch, val; 
   cout<<"1) Enqueue"<<endl;
   cout<<"2) Dequeue"<<endl;
   cout<<"3) Exit"<<endl;
   do {
      cout<<"Enter choice: "<<endl;
      cin>>ch;
      switch(ch) {
         case 1: {   
            cout<<"Enter value to be pushed:"<<endl;
            cin>>val;
            enqueue(q, val);
            cout<<"Enqueud "<<val<<" to the queue"<<endl;
            break;
         }
         case 2: {
            Node *n = dequeue(q);
            if(n!=NULL){
               cout<<"Dequeued "<<n->data<<" from Queue"<<endl;
            }
            else
               cout<<"Queue is Empty"<<endl;
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
