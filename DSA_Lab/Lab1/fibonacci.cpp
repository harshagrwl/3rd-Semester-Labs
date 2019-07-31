  #include<bits/stdc++.h>
     
    using namespace std;
     
    int main()
    {
       int n, c, first = 0, second = 1, next;
     
       cout << "Enter the number of terms" << endl;
       cin >> n;
     
       cout << "Fibonnaci Seties: " << endl;
     
       for ( c = 0 ; c < n ; c++ )
       {
          if ( c <= 1 )
             next = c;
          else
          {
             next = first + second;
             first = second;
             second = next;
          }
          cout << next << endl;
       }
     
       return 0;
    }