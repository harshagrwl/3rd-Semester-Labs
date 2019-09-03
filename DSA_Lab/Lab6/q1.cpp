   /*Title : Creating Student Database Using Singly linked list */


#include<bits/stdc++.h>

struct Student
{
	int roll;
	char name[30];
	float marks;
	struct Student *next;				//Self referential pointer...

};

typedef struct Student Node;


void Linkfloat()
{
	float a=0,*b;			//To create link of float to some compiler ...
	b=&a;
	a=*b;

}

void Display(Node *head)
{

	Node *p;
	int i;

	if(head==NULL)
	{
		printf("

There is no records in database.

");

	}

	else
	{
		p=head;
		for(i=0;i<80;i++)
		{

			printf("-");

		}
		
		printf("

			Updated Student Database

");
		for(i=0;i<80;i++)
		{

			printf("-");

		}
		printf("
");
		printf("Roll No.	Name			Marks
");
		for(i=0;i<80;i++)
		{

			printf("-");

		}
		printf("
");
		while(p!=NULL)
		{

			printf("%d		%s			%0.2f",p->roll,p->name,p->marks);
			printf("

");
			for(i=0;i<80;i++)
			{

				printf("-");

			}	
			printf("
");

			flushall();
	
			
			p=p->next;				//Go to next node...
		}

	}

}

void DReverse(Node * head)
{
	Node *p;
	int i;
	if(head==NULL)
	{
		printf("

There is no records in database.

");

	}

	else
	{
		p=head;

		if(p->next!=NULL)
		{
		
			DReverse(p->next);		//Recursive call...

		}

		
		printf("%d		%s			%0.2f",p->roll,p->name,p->marks);
		printf("
");
		for(i=0;i<80;i++)
			{

				printf("-");

			}
		printf("
");

		flushall();

		printf("

");
	}
}

Node* Create(Node *head)
{
	int n,i;
	Node *nn,*p;

	printf("

How many Entries to Create Database???

");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		if(head==NULL)
		{

			nn=(Node*)malloc(sizeof(Node));	//Creating first node...
			printf("

Enter Roll No. , Name & Marks

");
			scanf("%d",&(nn->roll));
			flushall();

			gets(nn->name);

			scanf("%f",&(nn->marks));

			nn->next=NULL;	//Set next to NULL...

			head=nn;

		}
		else
		{
			p=nn=head;

			while(nn->next!=NULL)
			{
				nn=nn->next;
			}
			nn->next=(Node*)malloc(sizeof(Node));	//Creating further nodes...
			nn=nn->next;

			printf("

Enter Roll NO.,Name & Marks

");
			scanf("%d",&(nn->roll));
			flushall();

			gets(nn->name);
			scanf("%f",&(nn->marks));

			nn->next=NULL;     
			nn=p;
		}

	}

		return head;

}

Node* Insert(Node *head)
{
	int ch,r;
	char ans;
	Node *p,*nn,*q;
	do
	{

		printf("

Whwre do you want to enter new entry???

");

		printf("
			1.At the Begining
			2.At the middle
			3.At the end

");
		printf("
Enter your choice:
");
		scanf("%d",&ch);	
		switch(ch)
		{
		case 1:		 
			/* Insert at Begining */
			p=head;

			nn=(Node*)malloc(sizeof(Node));

			printf("

Enter Roll NO., Name & Marks

");
			scanf("%d",&(nn->roll));
			flushall();

			gets(nn->name);
			scanf("%f",&(nn->marks));

			nn->next=NULL;
		    nn->next=p;
		    head=nn;  //set first node as head...

			printf("
Entry is Created successfully.

");
			Display(head);

		    break;

			case 2:
				/* Insert at Middle */

				if(head==NULL)
				{
					
					printf("
Yet database is not created.");
					printf("
Database is empty.
");
					printf("

First Create Database.
");


				}

				else
				{

					printf("

After which Roll NO. You want to insert new Data???

");
					scanf("%d",&r);

					p=head;

					while(p->roll!=r && p->next!=NULL)
					{
						p=p->next;		//Go upto that roll no....

					}

					if(p->roll!=r)
					{
						printf("

There is no such entry.

");

					}

					else
					{

						nn=(Node*)malloc(sizeof(Node));

						printf("

Enter Roll NO.,Name & Marks

");
						scanf("%d",&(nn->roll));
						flushall();
						gets(nn->name);

						scanf("%f",&(nn->marks));
						nn->next=NULL;						
						q=p->next;
						p->next=nn;
						nn->next=q;

						printf("
Entry is Created successfully.

");
						Display(head);
					}
				}

			break;

			case 3:
		 	/*  Insert at end */
				if(head==NULL)
				{
					
					printf("
Yet database is not created.");
					printf("
Database is empty.
");
					printf("

First Create Database.
");


				}

				else
				{

					p=head;

					nn=(Node*)malloc(sizeof(Node));

					printf("

Enter Roll NO.,Name & Marks

");
					scanf("%d",&(nn->roll));
					flushall();
					gets(nn->name);
					scanf("%f",&(nn->marks));

					nn->next=NULL;
					while(p->next!=NULL)
					{
						p=p->next;		//Go upto last node...

					}

					p->next=nn;

					printf("
Entry is Created successfully.

");
					Display(head);
				}

			break;
		}
		printf("

Do you want to Insert more data(Y/N)???");
		flushall();
		scanf("%c",&ans);

	 }while(ans=='y' || ans=='Y');

	 return head;
}


Node* Delete(Node* head)
{
	Node *p,*q,*r;
	char ans;
	int ch,n;

	do{
		printf("

Which Entry you want to Delete???

");
		printf("
			1.First

			2.Middle

			3.End
");
		scanf("%d",&ch);

				if(head==NULL)
				{
					
					printf("
Yet database is not created.");
					printf("
Database is empty.
");
					printf("

First Create Database.
");


				}

				else
				{
					switch(ch)
					{
					case 1:

							/*Delete first node */
						p=head;

						head=head->next;	//Set second node as head...
						free(p);

						printf("

First entry is deleted.
");

						Display(head);

					break;

					case 2:
							/*Delete middle Node*/ 

						p=head;
						printf("
Enter roll no. which you want to delete:

");
						scanf("%d",&n);

						while((p->next)->roll!=n && p->next->next!=NULL)
						{
							p=p->next;		//Go upto -1 node which you want to delete...

						}

						if(p->next->next==NULL)
						{
							printf("

There is no such entry.

");

						}

						else
						{			
							q=p->next;
							r=q->next;
							p->next=r;
							free(q);			//Delete that node...

							printf("

Entry is deleted.
");
							Display(head);
						}
						break;

					case 3:
							/*	Delete last node */
						p=head;
						while(p->next->next!=NULL)
						{
							p=p->next;  //Go upto -1 node which you want to delete...

						}
							q=p->next;
							free(q);		//Delete last node...

							p->next=NULL;
							printf("

Last entry is deleted.
");
							Display(head);			

						break;

					}

				}

			printf("
Do you want to delete more data(Y/N)???
");
			flushall();
			scanf("%c",&ans);

		}while(ans=='y'|| ans=='Y');


	return head;

}

Search(Node *head)
{

	Node *p;
	int r,cnt=0;
	if(head==NULL)
	{
		printf("
Yet database is not created.");
		printf("
Database is empty.
");
		printf("

First Create Database.
");
	}

	else
	{
		p=head;
		printf("

Enter roll no. which you want to Search:

");
		scanf("%d",&r);

		while(p->roll!=r && p->next!=NULL)		//Search for roll no...
		{
			p=p->next;			
			cnt++;
		}

	if(p->roll!=r)
		printf("
There is no such entry.

");
	else
	{
		printf("
Roll NO. %d is at %d th Position.",r,(cnt+1));
		printf("

Roll No.	Name		Marks

");
		printf("%d		%s			%0.2f",p->roll,p->name,p->marks);
	}	
	}

}

Modify(Node * head)
{
	Node *p;
	int r;

	if(head==NULL)
	{
		printf("
Yet database is not created.");
		printf("
Database is empty.
");
		printf("

First Create Database.
");

	}
	else
	{
		p=head;
		printf("

Enter the Roll no. whose data you want to modify:

");
		scanf("%d",&r);

		while(p->roll!=r && p->next!=NULL)
		{
	
			p=p->next;
		
		}

		if(p->roll!=r)
		{
			printf("

Thre is no such record in Database.

");

		}
		else
		{
	
			printf("
Entered roll no's Data is:
");
			printf("Roll No.	Name	Marks
");			//Displaying Data who is going to modify....
			printf("%d		%s		%f",p->roll,p->name,p->marks);

			printf("
Enter New roll no ,New name & Marks for this entry:

");
			scanf("%d",&p->roll);
			flushall();
			gets(p->name);					//Enter new data... 

			scanf("%f",&(p->marks));

			printf("
Entered New Data is:
");
			printf("Roll No.	Name	Marks
");
			printf("%d		%s		%f",p->roll,p->name,p->marks);
			Display(head);

		}

	}

}

Count(Node *head)
{
	Node *p;
	int cnt=0;

	if(head==NULL)
	{
		printf("
Yet database is not created.");
		printf("
Database is empty.
");
		printf("

First Create Database.
");
		printf("
There are 0 records in Database.

");
	}

	else
	{

		p=head;
		while(p->next!=NULL)
		{
			p=p->next;
			cnt++;			//Counting records...

		}

		printf("

There are %d records in Database.

",(cnt+1));

	}

}


void main()
{
	int ch,i;
	char op;
	Node *head;
	head=NULL;
	printf("

			*----------Student Database-----------*

");
	do
	{
		printf("

				Menu

			1.Create Database

			2.Insert

			3.Delete

			4.Search

			5.Modify

			6.Display

			7.Display Reverse

			8.Count Records

			9.Exit

");

		printf("

Enter your choice

");
		scanf("%d",&ch);

		switch(ch)
		{
		case 1:
			head=Create(head);			//Call to Create...

		break;

		case 2:

			head=Insert(head);			//Call to Insert...

		break;

		case 3:

			head=Delete(head);			//Call to Delete...

		break;

		case 4:		

			Search(head);				//Call to Search...

		break;

		case 5:

			Modify(head);				//Call to Modify...
		
		break;

		case 6:
			Display(head);				//Call to Display...
		break;

		case 7:

			for(i=0;i<80;i++)
			{

				printf("-");

			}
			printf("

			Updated Student Database

");
			for(i=0;i<80;i++)
			{

				printf("-");

			}
			printf("
");

			printf("Roll No.	Name		Marks
");
			for(i=0;i<80;i++)
			{

				printf("-");

			}
			printf("
");
	
			DReverse(head);		//Call to displaying reversre...

		break;

		case 8:
			Count(head);		//Call to counting records...
		
		break;

		case 9:
			exit();				//Exit...

		default :
		printf("

You entered wrong choice.

");

		}

		printf("

Do you want to Exit(Y/N)???

");
		flushall();
		scanf("%c",&op);

	}while(op=='n' || op=='N');

}
			