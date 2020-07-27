#include <bits/stdc++.h>
using namespace std;
int cnt;
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
vector<vector<int>> res;
    
    void pathSumHelper(TreeNode* root,int sum,vector<int> list){
        if(root == NULL)
            return;
        list.push_back(root->val);
        sum -= root->val;
        if(root->left == NULL and root->right == NULL and sum == 0){
            res.push_back(list);
        }
        pathSumHelper(root->left,sum,list);
        pathSumHelper(root->right,sum,list);
        list.pop_back();
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> temp;
        pathSumHelper(root,sum,temp);
        return res;
    }
*/

bool existPathSum(Node *root, int sum)
{
    if (root == NULL)
        return true;
    if (sum == 0 and root->left == NULL and root->right == NULL)
    {
        cnt += 1;
        return true;
    }

    if (sum < 0)
        return false;
    return existPathSum(root->left, sum - root->data) || existPathSum(root->right, sum - root->data);
}

int main()
{
    Node *root = buildTree();
    cnt = 0;
    int key;
    cin >> key;
    if (existPathSum(root, key))
        cout << cnt << endl;
}

/*
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

*/