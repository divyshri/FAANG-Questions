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

Node *buildTree()
{
    int d;
    cin >> d;
    if (d == -1)
        return NULL;
    Node *root = new Node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void printTree(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    printTree(root->left);

    printTree(root->right);
}

void greaterSum(Node *root, int &sum)
{
    if (root == NULL)
        return;
    greaterSum(root->right, sum);
    sum += root->data;
    root->data = sum;
    greaterSum(root->left, sum);
}

int main()
{
    Node *root = buildTree();
    int sum = 0;
    greaterSum(root, sum);
    printTree(root);
}