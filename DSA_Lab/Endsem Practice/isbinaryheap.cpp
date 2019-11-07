#include<bits/stdc++.h>
using namespace std;

void swap(int *x, int *y)
{
        int temp = *x;
        *x = *y;
        *y = temp;
}

struct Node{
	int data;
	Node* left;
	Node* right;
}