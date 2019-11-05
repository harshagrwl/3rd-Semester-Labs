#include<bits/stdc++.h>
using namespace std;

void swap(int*x,int*y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

int partition(int a[],int low,int high){
	int pivot = a[high];
	int i = low -1;
	for(int j = low;j< high;j++){
		if(a[j] <= pivot){
			i++;
			swap(&a[i],&a[j]);
		}

	}
	swap(&a[i+1],&a[high]);
	return i+1;
}

int qsort(int a[],int low,int high){
	int s[high - low + 1];
	int top = -1;
	s[++top] = low;
	s[++top] = high;

	while(top >= 0){
		high = s[top--];
		low = s[top--];
		int p = partition(a,low,high);
		if(p-1 > low){
			s[++top] = low;
			s[++top] = p -1;
		}

		if(p+1 < high){
			s[++top] = p+1;
			s[++top] = high;
		}
	}
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	qsort(a,0,n-1);
	for(int i = 0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
