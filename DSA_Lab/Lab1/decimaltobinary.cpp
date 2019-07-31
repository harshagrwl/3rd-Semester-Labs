#include <bits/stdc++.h> 
using namespace std;
void convert(int n){
	int binary[32];
	int i = 0;
	while (n>0){
		binary[i] = n%2;
		n /=2;
		i++;
	}
	for (int j =i-1;j>=0;j--){
		sort(binary,binary+2);
		cout<<binary[j]<<endl;
	}
}
int main(){
	int n;
	cout<<"Enter the no. "<<endl;
	cin>>n;
	cout<<"Number in binary "<<endl;
	convert(n);
	return 0;
}