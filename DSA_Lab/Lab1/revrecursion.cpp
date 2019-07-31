#include <bits/stdc++.h>  
using namespace std; 
int rev(int n){
  static int m = 0;
  if(n == 0){
    return 0;
  }
  else{
  
  m *= 10;
  m += n%10;
  rev(n/10);

  return m;
}
} 
int main(){  
    int n, reverse=0, rem;    
    cout<<"Enter the number: ";    
    cin>>n;    
    cout<<"Reversed Number: "<<rev(n)<<endl;     
    return 0;  
}  