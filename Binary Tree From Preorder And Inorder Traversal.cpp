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

Node *helper(vector<int> &preorder, vector<int> &inorder, int start, int end)
{
    if (start > end)
        return NULL;
    int data = preorder[indx++];
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
    root->left = helper(preorder, inorder, start, k - 1);
    root->right = helper(preorder, inorder, k + 1, end);
    return root;
}

Node *createTree(vector<int> &preorder, vector<int> &inorder)
{
    indx = 0;
    return helper(preorder, inorder, 0, inorder.size() - 1);
}

void modifiedprintTree(Node *root)
{
    if (root == NULL)
        return;
    //cout << root->data << " ";
    if (root->left != NULL)
        cout << root->left->data << " => ";
    else
        cout << "END => ";
    cout << root->data << " ";
    if (root->right != NULL)
        cout << "<= " << root->right->data;
    else
        cout << "<= END";
    cout << endl;
    modifiedprintTree(root->left);
    modifiedprintTree(root->right);
}

int main()
{
    int n, temp;
    cin >> n;
    vector<int> preorder, inorder;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        preorder.push_back(temp);
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        inorder.push_back(temp);
    }
    Node *root = createTree(preorder, inorder);
    modifiedprintTree(root);
}
