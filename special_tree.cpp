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

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node *constructTree(vector<int> &ar, int start, int end)
{
    if (start > end)
        return NULL;
    int indx = start;
    for (int i = start; i <= end; i++)
    {
        if (ar[i] > ar[indx])
            indx = i;
    }
    Node *root = new Node(ar[indx]);
    root->left = constructTree(ar, start, indx - 1);
    root->right = constructTree(ar, indx + 1, end);
    return root;
}

int main()
{
    int t, temp;
    cin >> t;
    vector<int> ar;
    for (int i = 0; i < t; i++)
    {
        cin >> temp;
        ar.push_back(temp);
    }

    Node *root = constructTree(ar, 0, ar.size() - 1);
    inorder(root);
}