#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int key;
	struct node* left;
	struct node* right;
}Node;
Node *root1,*root2;

void display(Node** node)
{
	Node* temp=*node;
	while(temp!=NULL)
		{
			printf(" %d ",temp->key);
			temp=temp->right;
		}
}
void mergelist(Node** node1,Node** node2)
{
	Node *temp=*node1,*p=*node2;
	while(p)
	{
		sortedinsert(&root1,p->key);
		p=p->right;
	}
}
void deletebyvalue(Node** root,int x)
{
	int i=0;
	Node *temp=*root,*p;
	if(*root==NULL)
		printf("\n empty list\n");
	else
	{
		if(temp->key==x)
		{
			*root=temp->right;
			temp->right=NULL;
			free(temp);
		}
		else
		{
			while(temp->right!=NULL)
			{
				if(temp->right->key==x)
				{	
					i=1;
					break;
				}
				temp=temp->right;
			}
			if(i)
			{
				p=temp->right;
				temp->right=temp->right->right;
				p->left=temp;
				free(p);
			}
			else
				printf("\nelement not in list");				
		}
	}
}
void sortedinsert( Node** node,int x)
{
	 Node *temp=*node;
	 Node *p=(Node*)malloc(sizeof(Node));
	p->key=x;
	p->left=NULL;
	p->right=NULL;
	if(*node==NULL)
	{
		*node=p;
		p->left=*node;
	}
	else if(temp->key>x)
	{
		p->right=temp;
		temp->left=p;
		*node=p;
		p->left=*node;
		
	}
	else
	{
		while(temp->key<x&&temp->right!=NULL)
		{
			if(*node==NULL)
				printf("\nempty list");
			if(temp->right->key>x)
				break;
			temp=temp->right;
		}
		if(temp->right!=NULL)
		{
				p->right=temp->right;
				temp->right->left=p;
				temp->right=p;
				p->left=temp;
		}
		else 
		{
			p->left=temp;
			temp->right=p;
		}
	}
}

void build()
{
	int x,y,z,i;
	printf("\nenter the size of first doubly linked list=");
	scanf("%d",&x);
	for(i=0;i<x;i++)
	{
		scanf("%d",&z);
		sortedinsert(&root1,z);
	}
	display(&root1);
	printf("\nenter the size of second doubly linked list=");
	scanf("%d",&y);
	for(i=0;i<y;i++)
	{
		scanf("%d",&z);
		sortedinsert(&root2,z);
	}
	display(&root2);
	printf("\nafter merge and sorting");
	mergelist(&root1,&root2);
	display(&root1);
}
int main()
{	
	int x,y;
	build();
	printf("\n1.insert  2.delete 3.exit ");
	while(1)
	{
		printf("\nenter the choice");
		scanf("%d",&x);
		switch(x)
		{
			case 1:printf("\nenter the value");
					scanf("%d",&y);
					sortedinsert(&root1,y);
					display(&root1);
					break;
			case 2:printf("\nenter the value");
					scanf("%d",&y);
					deletebyvalue(&root1,y);
					display(&root1);
					break;
			case 3: exit(0);
		}
	}
}