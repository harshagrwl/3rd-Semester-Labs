#include<bits/stdc++.h>
using namespace std;

struct node{
	char name[10];
	float mark;
	float cgpa;
	struct node *next;
}*person=NULL,*head=NULL,*temp=NULL,*curr=NULL,*head1=NULL,*current=NULL,*o=NULL,*next1=NULL;

void SortList();
void Insert();

void Menu()
{
    cout<<"1.Insert student data."<<endl;
    cout<<"2.Display student list."<<endl;
    cout<<"3.Sort the students according to Marks."<<endl;
    cout<<"4.Exit."<<endl;
    cout<<"Enter Your choice: ";
}

void Insert()
{
    person =new node;
    char roll[10];
    cout<<endl;
    cout<<"Enter Your name: ";
    cin>>person->name;
    cout<<"Enter Your marks: ";
    cin>>person->mark;
    cout<<"Enter Your cgpa: ";
    cin>>person->cgpa;
    cout<<endl;

    if (head == NULL)
    {
        head = person;
        person->next = NULL;
    }
    else
    {
        person->next = head;
        head = person;
    }
}

void Print()
{
    temp = head;
    int i = 1;

    cout<<"Eligibility list:"<<endl<<endl;
    cout<<"No"<<"  "<<"Name"<<"  "<<"Marks"<<"  "<<"CGPA"<<endl;

    if (temp == NULL)
   cout<<"List is empty!!";
    else
    {
        while (temp != NULL)
        {
            cout<<i<<"  "<<temp->name<<"    "<<temp->mark<<"    "<<temp->cgpa<<endl;
            temp = temp->next;
            i++;
        }

    }
    cout<<endl;
}

void SortedInsert(int cutoff)
{
    temp = head;
    person = NULL;
    if (head == NULL)
    {
        head = person;
        person->next = NULL;
    }
    else
    {
        if ((person->mark > temp->mark)&& (person->cgpa > cutoff))
        {
             person->next = temp;
             head = person;

        }
        else
        {
            while ((temp->next != NULL) && (temp->next->mark > person->mark))
            {
                temp = temp-> next;
            }

                person->next=temp->next;
                temp->next = person;

            }
        }
    }


void SortList(int cutoff)
{

    current = head;
    if (current == NULL)
    cout<<"List empty"<<endl;
    else
    {
        while (current != NULL)
        {
            
            SortedInsert(cutoff);
            
        }

    }


    cout<<"Sorted list: "<<endl;
}
int main(){
	int choice, cutoff;
	cout<<"Enter the Cutoff"<<endl;
	cin>>cutoff;
    do
    {
        Menu();
        cin>>choice;
        switch (choice)
        {
            case 1:
                Insert();
                break;
            case 2:
                Print();
                break;
            case 3:
                SortList(cutoff);
                Print();
                break;
            default:
               cout<<"WRONG CHOICE";
        }
    } while (choice != 0);

    return 0;
}