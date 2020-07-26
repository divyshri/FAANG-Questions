#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left;
	Node *right;

	Node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

Node *buildTree()
{
	int d;
	cin >> d;

	if (d == -1)
	{
		return NULL;
	}
	Node *root = new Node(d);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}
void printTree(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	cout << root->data << " ";
	printTree(root->left);
	printTree(root->right);
}
int main()
{
	Node *root = buildTree();
	printTree(root);
}