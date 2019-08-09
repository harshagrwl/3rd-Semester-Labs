#include <bits/stdc++.h>
#define MAX 10
using namespace std;

class Stack{
	 int top;
	public:
	 Stack() {top = -1; }
	 int a[MAX];
	 bool push(int x);
	 int pop();
	 void print();
};

bool Stack::push(int x){ 
    if (top >= (MAX - 1)) { 
        cout << "Stack is Full\n"; 
        return false; 
    } 
    else { 
        a[++top] = x; 
        cout << x << " pushed into stack\n"; 
        return true; 
    } 
}
int Stack::pop(){
	if (top < 0) { 
        cout << "Stack is Empty\n"; 
        return 0; 
    } 
    else { 
        int x = a[top--]; 
        return x; 
    } 
} 
void Stack::print(){
	for(int i=0;i<=top;i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}
 
int main(){
	Stack s;
	int choice;
	int x;
	do{
	cout<<"Enter 1 to push an element, 2 to pop, 3 to print and 4 to exit\n";
	cin>>choice;
	switch(choice){
		case 1: cout<<"Enter the element to be pushed to stack:\n";
				cin>>x;
				s.push(x);
				break;
		case 2: s.pop();
				break;
		case 3: s.print();
				break;
		default: cout<<"Succesfully Closed the program\n";
	}
}
while (choice!=4);
	return 0;
}