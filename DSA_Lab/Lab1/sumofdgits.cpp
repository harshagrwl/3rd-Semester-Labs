 #include <bits/stdc++.h>  
 using namespace std;  
 int main()  
 {  
    int n,sum=0,m;    
    cout<<"Enter the number: ";    
    cin>>n;    
    while(n>0)    
    {    
    m=n%10;    
    sum=sum+m;    
    n=n/10;    
    }    
    cout<<"Sum of digits= "<<sum<<endl;    
    return 0;  
 }  