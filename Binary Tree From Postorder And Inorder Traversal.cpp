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
int indx;

Node *helper(vector<int> &post, vector<int> &inorder, int start, int end)
{
    if (start > end)
        return NULL;
    int data = post[indx--];
    Node *root = new Node(data);
    //cout << data << endl;
    int k = -1;
    for (int i = 0; i < inorder.size(); i++)
    {
        if (data == inorder[i])
        {
            k = i;
            break;
        }
    }
    root->right = helper(post, inorder, k + 1, end);
    root->left = helper(post, inorder, start, k - 1);
    return root;
}

Node *createTree(vector<int> &post, vector<int> &inorder)
{
    indx = inorder.size() - 1;
    return helper(post, inorder, 0, inorder.size() - 1);
}
void printTree(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    printTree(root->left);

    printTree(root->right);
}

int main()
{
    int n, temp;
    cin >> n;
    vector<int> post, inorder;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        inorder.push_back(temp);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        post.push_back(temp);
    }
    Node *root = createTree(post, inorder);
    printTree(root);
}
