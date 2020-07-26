#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    string data;
    node *left;
    node *right;
    node(string d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
node *buildtree()
{
    string str;
    cin >> str;
    if (str == "false")
    {
        return NULL;
    }
    if (str == "true")
    {
        string d;
        cin >> d;
        node *root = new node(d);
        root->left = buildtree();
        root->right = buildtree();
        return root;
    }
    node *root = new node(str);
    root->left = buildtree();
    root->right = buildtree();
    return root;
}

bool existPathSum(node *root, int sum)
{
    if (root == NULL)
        return true;
    if (sum == 0 and root->left == NULL and root->right == NULL)
        return true;
    if (sum < 0)
        return false;
    return existPathSum(root->left, sum - stoi(root->data)) || existPathSum(root->right, sum - stoi(root->data));
}

int main()
{
    node *root = buildtree();
    int k;
    cin >> k;
    //cout<<k<<endl;
    if (existPathSum(root, k))
        cout << "true";
    else
        cout << "false";
}
