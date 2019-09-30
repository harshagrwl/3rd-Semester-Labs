#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* head;

void insert(int data, int n){
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    if(n==1){
        temp->next = head;
        head = temp;
        return;
    }
        Node* temp1 = head;
        for(int i = 0;i<n-2;i++){
            temp1 = temp1->next;
        }
        temp->next = temp1->next;
        temp1->next = temp;

}

void print(){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    cout<<"\n";
}

void delete1(int n){
    Node* temp = head;
    if(n==1){
        head = temp->next;
        delete temp;
        return;
    }
    for(int i=0;i<n-2;i++){
        temp = temp->next;
    }
    Node* temp1 = temp->next;
    temp->next = temp1->next;
    delete temp1;

}

void reverse(){
    Node *curr,*prev,*next;
    curr = head;
    prev = NULL;
    while(curr!=NULL){
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

int main(){
    head = NULL;
    insert(2,1);
    insert(10,2);
    insert(4,3);
    insert(5,4);
    insert(12,2);
    print();
    delete1(1);
    print();
    reverse();
    print();
}