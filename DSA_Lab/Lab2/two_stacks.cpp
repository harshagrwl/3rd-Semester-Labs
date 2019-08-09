#include<bits/stdc++.h>

using namespace std; 

class twoStacks 
{ 
	int *arr; 
	int size; 
	int top1, top2; 
public: 
twoStacks(int n)
{ 
	size = n; 
	arr = new int[n]; 
	top1 = -1; 
	top2 = size; 
} 

 
void push1(int x) 
{ 

	if (top1 < top2 - 1) 
	{ 
		top1++; 
		arr[top1] = x; 
	} 
	else
	{ 
		cout << "Stack 1 is full\n"; 
		
	} 
} 


void push2(int x) 
{
	if (top1 < top2 - 1) 
	{ 
		top2--; 
		arr[top2] = x; 
	} 
	else
	{ 
		cout << "Stack 2 is full\n"; 
		
	} 
} 


int pop1() 
{ 
	if (top1 >= 0 ) 
	{ 
		int x = arr[top1]; 
		top1--; 
		return x; 
	} 
	else
	{ 
		cout << "Stack 1 is empty\n"; 
		
	} 
} 
int pop2() 
{ 
	if (top2 < size) 
	{ 
		int x = arr[top2]; 
		top2++; 
		return x; 
	} 
	else
	{ 
		cout << "Stack 2 is empty\n"; 
		
	} 
} 
}; 



int main() 
{ 
	twoStacks ts(10); 
	int choice;
	int x;
	do{
	cout<<"Enter 1 to push an element to Stack 1, 2 to pop fron Stack 1, 3 to push to Stack 2, 4 to pop from Stack 2 and 5 to exit\n";
	cin>>choice;
	switch(choice){
		case 1: cout<<"Enter the element to be pushed to stack 1:\n";
				cin>>x;
				ts.push1(x);
				break;
		case 2: ts.pop1();
				break;
		case 3: cout<<"Enter the element to be pushed to stack 2:\n";
				cin>>x;
				ts.push2(x);
				break;
		case 4: ts.pop2();
				break;
		default: cout<<"Succesfully Closed the program\n";
	}
}
while (choice!=5);
	return 0; 
} 
