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

bool isMirror(Node *LST, Node *RST)
{
    if (LST == NULL or RST == NULL)
        return LST == RST;
    if (LST->data != RST->data)
        return false;
    if (isMirror(LST->left, RST->right) and isMirror(LST->right, RST->left))
        return true;
    return false;
}
bool isSymmetric(Node *root)
{
    if (root == NULL)
        return true;
    return isMirror(root, root);
}
Node *levelOrderBuild()
{

    int d;
    cin >> d;
    Node *root = new Node(d);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();

        int c1, c2;
        cin >> c1 >> c2;
        if (c1 != -1)
        {
            f->left = new Node(c1);
            q.push(f->left);
        }
        if (c2 != -1)
        {
            f->right = new Node(c2);
            q.push(f->right);
        }
    }

    return root;
}

int main()
{
    Node *root = levelOrderBuild();
    if (isSymmetric(root))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}