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
int max_sum = INT_MIN;
int maxPathSum(Node *root)
{
    if (root == NULL)
        return INT_MIN;
    int left_sum = maxPathSum(root->left);
    int right_sum = maxPathSum(root->right);

    int res = root->data;
    if (left_sum > 0)
        res += left_sum;
    if (right_sum > 0)
        res += right_sum;
    max_sum = max(max_sum, res);
    return root->data + max(0, max(left_sum, right_sum));
}

int main()
{
    Node *root = buildTree();
    maxPathSum(root);
    cout << max_sum << endl;
}