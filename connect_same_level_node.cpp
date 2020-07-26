#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node *next;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

Node *levelOrderBuild()
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
            temp->left = new Node(c1);
            Q.push(temp->left);
        }
        if (c2 != -1)
        {
            temp->right = new Node(c2);
            Q.push(temp->right);
        }
    }
    return root;
}

Node *connectLevel(Node *root)
{
    if (root == NULL)
        return NULL;
    queue<Node *> Q;
    Q.push(root);
    Q.push(NULL);
    while (!Q.empty())
    {
        Node *temp = Q.front();
        Q.pop();
        if (temp != NULL)
        {
            if (temp->left != NULL)
                Q.push(temp->left);
            if (temp->right != NULL)
                Q.push(temp->right);
            temp->next = Q.front();
            //Q.pop();
        }
        else
        {
            if (!Q.empty())
                Q.push(NULL);
        }
    }
    return root;
}
void printNextRight(Node *root)
{
    queue<Node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        Node *temp = Q.front();
        Q.pop();
        (temp->next != NULL) ? cout << temp->next->data << " " : cout << "-1 ";
        if (temp->left)
            Q.push(temp->left);
        if (temp->right)
            Q.push(temp->right);
    }
}

int main()
{
    Node *root = levelOrderBuild();
    root = connectLevel(root);
    printNextRight(root);
}
