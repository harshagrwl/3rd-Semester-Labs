#include<bits/stdc++.h>
using namespace std;


	void heapify(int a[],int i, int n){
		int left = 2*i;
		int right = 2*i + 1;
		int largest;
		if(left <= n && a[left] > a[i])
			largest = left;
		else
			largest = i;
		if(right <= n && a[right] > a[largest])
			largest = right;

		if(largest!=i){
			swap(a[i],a[largest]);
			heapify(a, largest, n);
		}
	}

	void buildheap(int a[],int n){
		for(int t = n/2;t >= 1;t--)
			heapify(a,t,n);
	}

	void maximum(int a[]){
		cout<<"The maximum element int the heap is: "<<a[1]<<endl;
	}

	void extractmax(int a[],int n){
		swap(a[1],a[n]);
		n--;
		heapify(a,1,n);
		cout<<"The elements of the heap are: "<<endl;
               	for(int i = 1;i<=n;i++){
					cout<<a[i]<<" ";
				}
				cout<<endl;
	}

int main(){
	// int n;
	// cin>>n;
	// int a[n];
	// for(int i = 1;i<=n;i++){
	// 	cin>>a[i];
	// }
	// buildheap(a,n);
	// for(int i = 1;i<=n;i++)
	// 	cout<<a[i]<<" ";
	// cout<<endl;
	// maximum(a);
	// extractmax(a,n);
	// for(int i = 1;i<=n-1;i++)
	// 	cout<<a[i]<<" ";
	int choice;

	cout<<"Enter the number of elements to be inserted in the tree: ";
				int n;
				cin>>n;
				int a[n];
				cout<<"Enter the elements: ";
				for(int i = 1;i<=n;i++){
					cin>>a[i];
				}
	do
    {
        cout<<"Select Yout Choice\n";
		cout<<" 1. Insert/Build-Heap\n 2. Max element\n 3. Extract Maximum\n 4. Print the tree nodes\n";
		cin>>choice;
        switch (choice)
        {
            case 1:
                
				buildheap(a,n);
                break;
            case 2:
            	maximum(a);
                break;
            case 3:
               	extractmax(a,n);
                break;
            case 4:
               	cout<<"The elements of the heap are: "<<endl;
               	for(int i = 1;i<=n;i++){
					cout<<a[i]<<" ";
				}
				cout<<endl;
                break;
            default:
               cout<<"WRONG CHOICE";
        }
    } while (choice != 0);
}
