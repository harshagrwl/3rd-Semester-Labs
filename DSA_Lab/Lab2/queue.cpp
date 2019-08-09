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
    if (end == (MAX - 1)) { 
        cout << "Queue is Full\n"; 
        return false; 
    } 
    else { 
        a[++end] = x; 
        cout << x << " pushed into queue\n"; 
        return true; 
    } 
}
int Queue::dequeue(){
	if ((front == end == -1) || (front > end)) { 
        cout << "Queue is Empty\n"; 
        return 0; 
    } 
    else { 
        int x = a[front++]; 
        return x; 
    } 
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
	cout<<"Enter 1 to enqueue an element, 2 to dequeue, 3 to print and 4 to exit\n";
	cin>>choice;
	switch(choice){
		case 1: cout<<"Enter the element to be enqueued:\n";
				cin>>x;
				q.enqueue(x);
				break;
		case 2: q.dequeue();
				break;
		case 3: q.print();
				break;
		default: cout<<"Succesfully Closed the program\n";
	}
}
while (choice!=4);
	return 0;
}