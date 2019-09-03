#include <bits/stdc++.h>
using namespace std;

struct node{
int roll;
float cgpa;
int marks;
struct node* next;
};


struct node* head = NULL;
void insert(int roll, float cgpa, int marks){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->roll = roll;
    temp->cgpa = cgpa;
    temp->marks = marks;
    temp->next = head;
    head = temp;
}

void display(struct node** head){
    int i =1;
    struct node* ptr;
    ptr = *head;
    while(ptr != NULL){
        cout<<"Eligibility list:"<<endl<<endl;
        cout<<"No"<<"  "<<"Roll no."<<"  "<<"Marks"<<"  "<<"CGPA"<<endl;
        cout<<i<<"     "<<ptr->roll<<"       "<<ptr->marks<<"      "<<ptr->cgpa<<endl;
        ptr = ptr->next;
        i++;
    }
}

void display1(struct node** head,int cutoff){
    int i =1;
    struct node* ptr;
    ptr = *head;
    while((ptr != NULL) && ptr->cgpa > cutoff){
        cout<<"Eligibility list:"<<endl<<endl;
        cout<<"No"<<"  "<<"Roll no."<<"  "<<"Marks"<<"  "<<"CGPA"<<endl;
        cout<<i<<"     "<<ptr->roll<<"       "<<ptr->marks<<"      "<<ptr->cgpa<<endl;
        ptr = ptr->next;
        i++;
    }

}

void sortedInsert(struct node** head_ref, struct node* new_node)
{
    struct node* current;
    if (*head_ref == NULL || ((*head_ref)->marks) >= (new_node->marks))
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else
    {
        
        current = *head_ref;
        while (current->next!=NULL &&
               current->next->marks < new_node->marks)
        {
            // if(current->cgpa < cutoff){
            //     continue;
            // }
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}


struct node* Sort(struct node **head_ref)
{
    
    struct node *sorted = NULL;
 
    struct node *current = *head_ref;
    while (current != NULL)
    {
      
        struct node *next = current->next;
 
        sortedInsert(&sorted, current);
  
        current = next;
    }
 
    return sorted;
}


int main(){
    int n, roll, marks, i = 1, ch;
    float cgpa, cutoff;
    struct node *sorted;
    do{
        cout<<"\n1. Enter Student Details\n";
        cout<<"2. Merit list based on marks\n";
        cout<<"3. Merit list based on cutoff\n";
        cout<<"4. Display\n";
        cout<<"5. Exit\n";
        cout<<"Enter your choice ";
        cin>>ch;
        switch(ch){
            case 1:
            cout<<"Enter the roll no. ";
            cin>>roll;
            cout<<"Enter the cgpa ";
            cin>>cgpa;
            cout<<"Enter the marks ";
            cin>>marks;
            insert(roll, cgpa, marks);
            break;
            case 2:
            sorted = Sort(&head);
            display(&sorted);
            case 3:
            int cutoff = 8;
            display1(&sorted, cutoff);
            //disp
            break;
            case 4:
            display(&head);
            break;
            case 5:
            i = 5;
            break;
            default:
            cout<<"Enter appropriate choice\n";
        }
    }while(i!=5);
return 0;
}

