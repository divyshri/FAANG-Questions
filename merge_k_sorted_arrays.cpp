#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, temp;
    cin >> n >> k;
    priority_queue<int> pq;
    for (int i = 0; i < n * k; i++)
    {
        cin >> temp;
        pq.push(temp);
    }
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}