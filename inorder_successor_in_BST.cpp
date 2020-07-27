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
void printTree(Node *root)
{
    if (root == NULL)
        return;
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}
bool check = false;
Node *inorderSuccessor(Node *root, int key)
{
    if (root == NULL)
        return NULL;
    Node *tempLeft = inorderSuccessor(root->left, key);
    if (tempLeft != NULL)
        return tempLeft;
    if (check == true)
    {
        check = false;
        return root;
    }
    if (root->data == key)
    {
        check = true;
    }
    Node *tempRight = inorderSuccessor(root->right, key);
    if (tempRight != NULL)
        return tempRight;
    return NULL;
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
    int k;
    cin >> k;
    //printTree(root);
    Node *t = inorderSuccessor(root, k);
    cout << t->data << " ";
}