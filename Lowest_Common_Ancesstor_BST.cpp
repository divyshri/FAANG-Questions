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
        left = right = NULL;
    }
};

Node *insertInBST(Node *root, int data)
{
    if (root == NULL)
        return new Node(data);
    if (data > root->data)
        root->right = insertInBST(root->right, data);
    else
        root->left = insertInBST(root->left, data);
    return root;
}

int LCS_BST(Node *root, int a, int b)
{
    if (root->data < a and root->data < b)
        return LCS_BST(root->right, a, b);
    if (root->data > a and root->data > b)
        return LCS_BST(root->left, a, b);
    return root->data;
}

void printNode(Node *root)
{
    if (root == NULL)
        return;
    printNode(root->left);
    cout << root->data << " ";
    printNode(root->right);
}

int main()
{
    int n, temp;
    cin >> n;
    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        root = insertInBST(root, temp);
    }
    int a, b;
    cin >> a >> b;
    //printNode(root);
    cout << LCS_BST(root, a, b) << endl;
}