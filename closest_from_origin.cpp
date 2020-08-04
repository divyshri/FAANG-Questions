#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> closestToOrigin(vector<vector<int>> ar, int k)
{
    int n = ar.size();
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        int d = ar[i][0] * ar[i][0] + ar[i][1] * ar[i][1];
        if (pq.size() < k or d < pq.top())
        {
            if (pq.size() == k)
            {
                pq.pop();
            }
            pq.push(d);
        }
    }
    int num = pq.top();
    int i = 0;
    int j = n - 1;
    while (i <= j)
    {
        int d = ar[i][0] * ar[i][0] + ar[i][1] * ar[i][1];
        if (d <= num)
        {
            i++;
        }
        else
        {
            swap(ar[i], ar[j]);
            j--;
        }
    }
    ar.erase(ar.begin() + k, ar.end());
    return ar;
}

int main()
{
    int n, a, b;
    cin >> n;
    vector<vector<int>> ar;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        cin >> a >> b;
        temp.push_back(a);
        temp.push_back(b);

        ar.push_back(temp);
    }
    int k;
    cin >> k;
    vector<vector<int>> res = closestToOrigin(ar, k);
    for (auto val : res)
    {
        cout << val[0] << " " << val[1] << endl;
    }
}