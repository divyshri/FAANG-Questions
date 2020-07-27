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

vector<int> levelOrderMaximum(Node *root)
{
    map<int, vector<int>> mp;
    queue<pair<Node *, int>> Q;
    Q.push({root, 0});
    while (!Q.empty())
    {
        pair<Node *, int> temp = Q.front();
        Q.pop();
        mp[temp.second].push_back(temp.first->data);
        if (temp.first->left)
            Q.push({temp.first->left, temp.second + 1});
        if (temp.first->right)
            Q.push({temp.first->right, temp.second + 1});
    }
    vector<int> res;
    for (auto val : mp)
    {
        int max_val = INT_MIN;
        for (auto x : val.second)
        {
            max_val = max(max_val, x);
        }
        res.push_back(max_val);
    }
    return res;
}

int main()
{
    Node *root = buildTree();
    vector<int> res = levelOrderMaximum(root);
    for (auto val : res)
        cout << val << " ";
}