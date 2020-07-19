//Leetcode - 138
/*
Node *copyRandomList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        Node *t = new Node(temp->val);
        t->next = temp->next;
        temp->next = t;
        temp = temp->next->next;
    }
    temp = head;
    while (temp != NULL)
    {
        if (temp->random != NULL)
        {
            temp->next->random = temp->random->next;
        }
        temp = temp->next->next;
    }
    temp = head;
    Node *new_head = NULL, *new_tail = NULL;
    while (temp != NULL)
    {
        Node *copy = temp->next;
        if (new_head == NULL)
        {
            new_head = copy;
            new_tail = copy;

            temp->next = copy->next;
            copy->next = NULL;
        }
        else
        {
            temp->next = copy->next;
            copy->next = NULL;
            new_tail->next = copy;
            new_tail = copy;
        }
        temp = temp->next;
    }
    return new_head;
}
*/

#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *random;
    Node(int val)
    {
        this->val = val;
        next = NULL;
        random = NULL;
    }
};
Node *createList(int num, unordered_map<Node *, int> &Random, int i, unordered_map<int, Node *> &node_number)
{
    if (num == 0)
    {
        node_number[-1] = NULL;
        return NULL;
    }
    int a, b;
    cin >> a >> b;
    Node *n = new Node(a);
    n->next = createList(num - 1, Random, i + 1, node_number);
    Random[n] = b;
    node_number[i] = n;
    return n;
}
void printList(Node *head)
{
    if (head == NULL)
        return;
    cout << "(" << head->val << ", ";
    if (head->random)
        cout << head->random->val;
    cout << ") ";
    printList(head->next);
    return;
}

//Definition of Node
// class Node{
//   public:
//    int val;
//    Node* next;
//    Node* random;
//    Node(int val){
//        this->val = val;
//        next = NULL;
//        random = NULL;
//    }
// };

Node *copyRandomList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        Node *n = new Node(temp->val);
        n->next = temp->next;
        temp->next = n;

        temp = temp->next->next;
    }
    temp = head;
    while (temp != NULL)
    {
        if (temp->random != NULL)
        {
            temp->next->random = temp->random->next;
        }
        temp = temp->next->next;
    }
    temp = head;
    Node *new_head = NULL, *new_tail = NULL;
    while (temp != NULL)
    {
        Node *copy = temp->next;
        if (new_head == NULL)
        {
            new_head = copy;
            new_tail = copy;

            temp->next = copy->next;
            copy->next = NULL;
        }
        else
        {
            temp->next = copy->next;
            copy->next = NULL;
            new_tail->next = copy;
            new_tail = copy;
        }
        temp = temp->next;
    }
    return new_head;
}

int main()
{
    int n;
    cin >> n;
    unordered_map<int, Node *> node_number;
    unordered_map<Node *, int> Random;
    Node *head = createList(n, Random, 0, node_number);
    Node *temp = head;
    while (temp)
    {
        temp->random = node_number[Random[temp]];
        temp = temp->next;
    }
    cout << "Old List: ";
    printList(head);
    cout << endl
         << "Copied List: ";
    Node *new_head = copyRandomList(head);
    printList(new_head);
    return 0;
}

// 5
// 6 4
// 4 0
// 8 4
// 9 1
// 6 2