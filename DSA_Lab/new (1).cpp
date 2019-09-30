#include <bits/stdc++.h>
using namespace std;

struct Node
{
	char val;
	bool op;
	Node* left;
	Node* right;
};

void func(char str[], int n, vector<Node*> &arr)
{
	int open = -1, close = -1;
	for (int a = 0; a < n; a++)
	{
		if (str[a] == ')')
		{
			close = a;
			break;
		}

		else if (str[a] == '(')
		{
			open = a;
		}
	}

	Node* opt;
	for (int a = open+1; a < close; a++)
	{
		if (arr[a])
		{
			if (arr[a]->op)
			{
				opt = arr[a];
				break;
			}
		}
	}

	for (int a = open+1; a < close; a++)
	{
		if (arr[a])
		{
			if (!arr[a]->op)
			{
				opt->left = arr[a];
				arr[a] = NULL;
				break;
			}
		}
	}

	for (int a = open+1; a < close; a++)
	{
		if (arr[a])
		{
			if (!arr[a]->op)
			{
				opt->right = arr[a];
				arr[a] = NULL;
				break;
			}
		}
	}

	opt->op = false;

	str[close] = ' ';
	str[close-1] = ' ';
	str[close-3] = ' ';
	str[close-4] = ' ';
}

int main()
{
	char str[100];
	cin >> str;
	int n = strlen(str);

	vector<Node*> arr;
	for (int a = 0; a < n; a++)
	{
		if (str[a] == '(' || str[a] == ')')
		{
			arr.push_back(NULL);
		}

		else if (str[a] >= '0' && str[a] <= '9')
		{
			Node* temp = new Node;
			temp->val = str[a];
			temp->op = false;
			temp->left = NULL;
			temp->right = NULL;
			arr.push_back(temp);
		}

		else
		{
			Node* temp = new Node;
			temp->val = str[a];
			temp->op = true;
			temp->left = NULL;
			temp->right = NULL;
			arr.push_back(temp);
		}
	}

	func(str, n, arr);
	for (int a = 0; a < n; a++)
	{
		cout << str[a];
	}
	cout << endl;

	for (int a = 0; a < arr.size(); a++)
	{
		if (arr[a])
		{
			cout << arr[a]->val;
		}

		else
		{
			cout << '-';
		}
	}
	cout << endl;
}