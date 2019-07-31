#include <bits/stdc++.h> 
using namespace std;
int main(){
	int n;
	cout<<"Enter the no. of elemnets: "<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter the elements: "<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	cout<<"Sorted Array: "<<endl;
	for(int i=0;i<n;i++){
		cout<< arr[i]<< endl;
	}
}