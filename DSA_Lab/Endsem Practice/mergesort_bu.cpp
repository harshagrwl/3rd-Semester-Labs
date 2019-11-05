#include<bits/stdc++.h>
using namespace std;

void merge(int a[],int low,int mid, int high){
	int n1 = mid - low;
	int n2 = high - mid;
	int l[n1+1],r[n2+1];
	for(int i = 0;i<n1;i++)
		l[i] = a[low+i];
	for(int i = 0;i<n2;i++)
		r[i] = a[mid + i];
	l[n1] = INT_MAX;
	r[n2] = INT_MAX;
	int i = 0,j = 0;
	for(int k = low;k<high;k++){
		
		if(l[i]<= r[j]){
			a[k] = l[i];
			i++;
		}
		else{
			a[k] = r[j];
			j++;
		}
	}
}


void sort(int n, int a[]){
	for(int w = 1; w<n; w*=2){
		for(int i = 0;i<n; i+= 2*w){
			int left, mid, right;
			left = i;
			mid = i + w;
			right = i+2*w;

			merge(a, left, mid, right);
		}
	}
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i = 0;i<n;i++)
		cin>>a[i];
	sort(n,a);
	for(int i = 0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}

