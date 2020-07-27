#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    string data;
    Node *left;
    Node *right;
    Node(string d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
Node *buildtree()
{
    string str;
    cin >> str;
    if (str == "false" or str == "flase")
    {
        return NULL;
    }
    if (str == "true")
    {
        string d;
        cin >> d;
        Node *root = new Node(d);
        root->left = buildtree();
        root->right = buildtree();
        return root;
    }
    Node *root = new Node(str);
    root->left = buildtree();
    root->right = buildtree();
    return root;
}

void addRow(Node *root, int val, int depth, int curDepth)
{
    if (root == NULL)
        return;
    if (curDepth == depth - 1)
    {

        Node *oldLeft = root->left;
        Node *oldRight = root->right;
        Node *newLeft = new Node(to_string(val));
        Node *newRight = new Node(to_string(val));
        newLeft->left = oldLeft;
        newRight->right = oldRight;
        root->left = newLeft;
        root->right = newRight;
        //return root;
    }
    addRow(root->left, val, depth, curDepth + 1);
    addRow(root->right, val, depth, curDepth + 1);
}

void displayTree(Node *root)
{
    if (root == NULL)
        return;
    (root->left != NULL) ? cout << root->left->data << " " : cout << " ";
    cout << "<- " << root->data << " -> ";
    (root->right != NULL) ? cout << root->right->data << " " : cout << " ";
    cout << endl;
    displayTree(root->left);
    displayTree(root->right);
}

int main()
{
    Node *root = buildtree();
    int val, depth;
    cin >> val >> depth;
    //cout << val << "  " << depth << endl;
    addRow(root, val, depth, 1);
    displayTree(root);
}
