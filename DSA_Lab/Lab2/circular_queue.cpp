#include <bits/stdc++.h>
#define MAX 10
using namespace std;

class Queue{
	 int front;
	 int end;
	public:
	 Queue() {front = -1; end = -1; }
	 int a[MAX];
	 bool enqueue(int x);
	 int dequeue();
	 void print();
};

bool Queue::enqueue(int x){ 
    if ((front == 0 && end == MAX -1) || 
            (front - end == 1)) 
    { 
        printf("\nQueue is Full"); 
        return false; 
    } 
  
    else if (front == -1)
    { 
        front = end = 0; 
        a[end] = x;
        return true; 
    } 
  
    else if (end == MAX -1 && front != 0) 
    { 
        end = 0; 
        a[end] = x;
        return true;
    } 
  
    else
    { 
        end++; 
        a[end] = x;
        return true; 
    } 
}
int Queue::dequeue(){
	if (front == -1) 
    { 
        printf("Queue is Empty\n"); 
        return 0; 
    } 
  
    int data = a[front]; 
    a[front] = -1; 
    if (front == end) 
    { 
        front = -1; 
        end = -1; 
    } 
    else if (front == MAX-1) 
        front = 0; 
    else
        front++; 
  
    return data;  
} 
void Queue::print(){
	for(int i=front;i<=end;i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}
 
int main(){
	Queue q;
	int choice;
	int x;
	do{
	cout<<"Enter 1 to enqueue an element, 2 to dequeue, 3 to exit\n";
	cin>>choice;
	switch(choice){
		case 1: cout<<"Enter the element to be enqueued:\n";
				cin>>x;
				q.enqueue(x);
				break;
		case 2: q.dequeue();
				break;
		default: cout<<"Succesfully Closed the program\n";
	}
}
while (choice!=3);
	return 0;
}