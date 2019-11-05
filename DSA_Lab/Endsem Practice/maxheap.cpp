#include<bits/stdc++.h>
using namespace std;

void swap(int *x, int *y)
{
        int temp = *x;
        *x = *y;
        *y = temp;
}

class heap{
	int *arr;
	int cap;
	int size;
public:
	heap(int k){
		size = 0;
		cap = k;
		arr = new int[k];
	}

	int parent(int i){
		return (i-1)/2;
	}

	int lchild(int i){
		return 2*i + 1;
	}
	int rchild(int i){
		return 2*i + 2;
	}

	void insert(int k){
		if(size == cap){
			cout<<"Cannot insert key\n";
			return;
		}
		size++;
		int i = size - 1;
		arr[i] = k;

		while(i!=0 && arr[parent(i)] < arr[i]){
			swap(&arr[i],&arr[parent(i)]);
			i = parent(i);
		}
	}

	void heapify(int i){
		int l = lchild(i);
		int r = rchild(i);
		int largest = i;
		if (l < size && arr[l] > arr[i])
                largest = l;
        if (r < size && arr[r] > arr[largest])
                largest = r;
        if (largest != i){
                swap(&arr[i], &arr[largest]);
                heapify(largest);
        }
	}

	void buildheap(){
		int n;
		cout<<"Enter the no. of elemnts\n";
		cin>>n;
		size = n;
		cout<<"Enter the elemnts\n";
		for(int i = 0;i<n;i++){
			cin>>arr[i];
		}
		int ind = (n-1)/2;
		for(int i = ind;i>=0;i--)
			heapify(i);
	}

	int getmax(){
		return arr[0];
	}

	int extractmax(){
		if(size <= 0)
			return INT_MAX;
		if(size == 1){
			size--;
			return arr[0];
		}

		int ans = arr[0];
		arr[0] = arr[size - 1];
		size--;
		heapify(0);

		return ans;
	}

	void print(){
		for(int i = 0;i<size;i++){
			cout<<arr[i]<<" ";
		}
		cout<<"\n";
	}

	void heapsort(){
		for(int i = size-1;i>=0;i--){
			swap(&arr[0],&arr[i]);
			heapify(i);
		}
	}

};

int main(){
	heap h(10);
	h.buildheap();
	h.print();
	h.heapsort();
	h.print();
}