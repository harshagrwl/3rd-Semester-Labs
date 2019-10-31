#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
private:
	
	int n;
	int arr[100];
	void swap(int, int);
	
public:
	
	MaxHeap();
	
	void build(int);
	void heapify(int);
	
	void insert(int);
	
	int Maxele();
	void extractMax();
	
	void deleteHeap();
	void print();
};

MaxHeap::MaxHeap()
{
	n = 0;

}

void MaxHeap::swap(int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void MaxHeap::build(int index)
{
	int parent = (index-1)/2;
	
	if (arr[parent] < arr[index])
	{
		swap(parent, index);
		build(parent);
	}
}

void MaxHeap::heapify(int index)
{
	int lchild = 2 * index + 1;
	int rchild = 2 * index + 2;
	int max = index;
	
	if (lchild < n && arr[lchild] > arr[max])
	{
		max = lchild;
	}
	
	if (rchild < n && arr[rchild] > arr[max])
	{
		max = rchild;
	}
	
	if (max != index)
	{
		swap(max, index);
		heapify(max);
	}
}

void MaxHeap::insert(int data)
{
	if (n >= 100)
	{
		return;
	}
	
	arr[n] = data;
	build(n++);
}

int MaxHeap::Maxele()
{
	if (n == 0)
	{
		return 0;
	}
	
	return arr[0];
}

void MaxHeap::extractMax()
{
	if (n == 0)
	{
		return;
	}
	
	swap(0, --n);
	heapify(0);
}

void MaxHeap::deleteHeap()
{
	n = 0;
}

void MaxHeap::print(){
	for(int i = 0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	MaxHeap h;
	
	int choice = -1;
	while (choice != 4)
	{
		cout << "1. Build Heap\n2. Insert into Heap\n3. Get Maximum Element\n4. Extract Maximum Element\n5. Print\n";
		cout << "Enter your Choice : ";
		cin >> choice;
		
		switch (choice)
		{
			case 1:
				h.deleteHeap();
				int temp1;
				cout << "Enter the Number of Elements you want to insert: ";
				cin >> temp1;
				
					cout << "Enter Elements: ";
				for (int a = 0; a < temp1; a++)
				{
					int temp2;
					cin >> temp2;
					h.insert(temp2);
				}
				break;
				
			case 2:
				int temp;
				cout << "Enter Element: ";
				cin >> temp;
				h.insert(temp);
				break;
				
			case 3:
				cout<<"The maximum element in the heap is:  ";
				cout << h.Maxele() << endl;
				break;
				
			case 4:
				h.extractMax();
				break;
				
			case 5:
				h.print();
				break;
			default:
				cout << "Invalid Choice" << endl;
				break;
		}
		
		cout << endl;
	}
}

