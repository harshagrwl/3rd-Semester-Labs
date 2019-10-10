#include <iostream>
using namespace std;

class LinkedList
{
	private:

		struct Node
		{
			int data;
			Node* next;
		};

		int count;

	public:

		Node* head;

		LinkedList();

		void add(int);

		void print();

		void sort();
};

LinkedList::LinkedList()
{
	head = NULL;
	count = 0;
}

void LinkedList::add(int data)
{
	if (data < 0 || data > 2)
	{
		return;
	}

	Node* temp = head;

	if (count == 0)
	{
		head = new Node;
		head->next = NULL;
		head->data = data;
		count++;
		return;
	}

	while(temp->next)
	{
		temp = temp->next;
	}

	temp->next = new Node;
	temp = temp->next;
	temp->next = NULL;
	temp->data = data;
	count++;
}

void LinkedList::print()
{
	Node* temp = head;

	while (temp)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
}

void LinkedList::sort()                                                                                                                          
{
	if (count < 2)
	{
		return;
	}

	Node* temp0 = head;

	
	while (temp0 && temp0->data == 0)
	{
		temp0 = temp0->next;
	}

	if (temp0 == NULL)
	{
		return;
	}

	Node* temp = temp0->next;

	while(temp)
	{
		if (temp->data == 0)
		{
			int t = temp0->data;
			temp0->data = temp->data;
			temp->data = t;         
		}

		temp = temp->next;
	}

	while (temp0 && temp0->data == 1)
	{
		temp0 = temp0->next;
	}

	if (temp0 == NULL)
	{
		return;
	}

	temp = temp0->next;
	
	while(temp)
	{
		if (temp->data == 1)
		{
			int t = temp0->data;
			temp0->data = temp->data;
			temp->data = t;
			temp0 = temp0->next;
		}

		temp = temp->next;
	}
}

int main()
{
	int n, temp;
	cin >> n;
	LinkedList ll;

	for (int a = 0; a < n; a++)
	{
		cin >> temp;
		ll.add(temp);
	}

	ll.sort();

	cout << endl;
	ll.print();
}