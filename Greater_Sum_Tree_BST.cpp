#include <bits/stdc++.h>
using namespace std;
int sum = 0;
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
    Node *root = new Node(d);
    queue<Node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        Node *temp = Q.front();
        Q.pop();
        int c1, c2;
        cin >> c1 >> c2;
        if (c1 != -1)
        {
            Node *t = new Node(c1);
            temp->left = t;
            Q.push(temp->left);
        }
        if (c2 != -1)
        {
            Node *t = new Node(c2);
            temp->right = t;
            Q.push(temp->right);
        }
    }
    return root;
}
/*
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
}*/
void printTree(Node *root)
{
    if (root == NULL)
        return;
    (root->left == NULL) ? cout << "." : cout << root->left->data;
    cout << "<--" << root->data << "-->";
    (root->right == NULL) ? cout << "." : cout << root->right->data;
    cout << endl;
    printTree(root->left);

    printTree(root->right);
}

void greaterSum(Node *root)
{
    if (root == NULL)
        return;
    greaterSum(root->right);
    sum += root->data;
    root->data = sum;
    greaterSum(root->left);
}
int main()
{
    Node *root = buildTree();
    //printTree(root);
    //cout<<endl;
    greaterSum(root);
    printTree(root);
}