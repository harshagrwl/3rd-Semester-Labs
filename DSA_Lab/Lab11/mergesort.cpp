#include<bits/stdc++.h>
using namespace std;

void merge(int a[],int low, int mid, int high){
	int n1 = mid - low ;
	int n2 = high - mid;
	int l[n1+1], r[n2+1];
	for(int i = 0;i< n1;i++){
		l[i] = a[low + i];
	}
	for(int i = 0;i< n2;i++){
		r[i] = a[mid + i];
	}
	l[n1] = INT_MAX;
	r[n2] = INT_MAX;
	int i = 0,j=0;
	for(int k = low;k<high;k++){
		if(l[i] <= r[j]){
			a[k] = l[i];
			i++;
		}
		else{
			a[k] = r[j];
			j++;
		}
	}
}

void mergesort(int a[],int low,int high){
	if(high - low == 1)
		return;
	int mid = (high+low)/2;

	mergesort(a, low, mid);
	mergesort(a, mid, high);

	merge(a,low,mid,high);
}



int main(){
	cout<<"Enter the number of elements in the array: "<<endl;
	int n;
	cin>>n;
	int a[n];
	cout<<"Enter the array elements: "<<endl;
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	mergesort(a,0,n);
	cout<<"The sorted array is: "<<endl;
	for(int i = 0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}