#include <bits/stdc++.h>
using namespace std;
struct Node { 
   char data; 
   struct Node *next; 
}; 
struct Node* top = NULL; 
void push(int val) {
   struct Node* newnode = new Node(); 
   newnode->data = val; 
   newnode->next = top; 
   top = newnode; 
}
void pop() {
   if(top==NULL)
      cout<<"Stack is empty"<<endl;
   else {
      struct Node *temp = top;
      cout<<"The popped element is "<< top->data <<endl;
      top = top->next;
      delete(temp);
   }
}
void display() {
   struct Node* ptr;
   if(top==NULL)
      cout<<"stack is empty";
   else {   
      ptr = top; 
      cout<<"Stack elements are: ";
      while (ptr != NULL) { 
         cout<< ptr->data <<" "; 
         ptr = ptr->next; 
      } 
   }
   cout<<endl;
}

bool pair1(char a,char b){
    if((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']'))
        return true;
    else
    {
            return false;
    }
    
}

bool isbalanced(string a){
    int n = a.size();
    for(int i = 0;i<n;i++){
        if(a[i] == '(' || a[i] == '{' || a[i] == '[' ){
            push(a[i]);
        }
        else if(a[i] == ')' || a[i] == '}' || a[i] == ']'){
            if(top == NULL || !pair1(top->data,a[i])){
                return false;
            }
            else{
                pop();
            }
        }
        if(top==NULL){
            return true;
        }
        else
        {
            return false;
        }
        
    }
}
int main(){
    string a;
    cin>>a;
    if(isbalanced(a)){
        cout<<"Balanced";
    }
    else
    {
        cout<<"Imbalanced";
    }
    

}