#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> ar, int key)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto val : ar)
        pq.push(val);
    int ans = pq.top();
    pq.pop();
    int i = 1;
    while (!pq.empty() and i < k)
    {
        ans = pq.top();
        pq.pop();
        i++;
    }
    return ans;
}

int main()
{
    int n, key, temp;
    cin >> n >> key;
    vector<int> ar;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        ar.push_back(temp);
    }
    cout << solution(ar, key) << endl;
}