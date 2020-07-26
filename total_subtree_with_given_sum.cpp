#include <bits/stdc++.h>
using namespace std;

char ar[1000];
vector<int> vec;

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

void stringToInt()
{
    char *ans = strtok(ar, " ");
    while (ans != NULL)
    {
        vec.push_back(stoi(ans));
        ans = strtok(NULL, " ");
    }
}

Node *buildTree()
{
    if (strlen(ar) == 0 or vec.size() == 0)
        return NULL;
    Node *root = new Node(vec[0]);
    queue<Node *> Q;
    Q.push(root);
    int i = 1;
    while (!Q.empty() and i < vec.size())
    {
        Node *temp = Q.front();
        Q.pop();
        temp->left = new Node(vec[i++]);
        Q.push(temp->left);
        if (i >= vec.size())
            break;
        temp->right = new Node(vec[i++]);
        Q.push(temp->right);
        if (i >= vec.size())
            break;
    }
    return root;
}

int Sum(Node *root)
{
    if (root == NULL)
        return 0;
    return root->data + Sum(root->left) + Sum(root->right);
}

int countSubtree(Node *root, int x)
{
    if (root == NULL)
        return 0;
    int ans = 0;
    if (Sum(root) == x)
        ans++;
    return ans + countSubtree(root->left, x) + countSubtree(root->right, x);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin.ignore();
        cin.getline(ar, 1000);
        stringToInt();
        Node *root = buildTree();
        int k;
        cin >> k;
        cout << countSubtree(root, k) << endl;
    }
}