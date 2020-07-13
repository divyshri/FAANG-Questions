#include <bits/stdc++.h>
using namespace std;

int left_index(vector<int> &ar, int key)
{
    int start = 0;
    int end = ar.size() - 1;
    int ans = INT_MAX;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (ar[mid] == key)
        {
            ans = min(ans, mid);
            end = mid - 1;
        }
        else if (ar[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return (ans == INT_MAX) ? -1 : ans;
}

int right_index(vector<int> &ar, int key)
{
    int start = 0;
    int end = ar.size() - 1;
    int ans = INT_MIN;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (ar[mid] == key)
        {
            ans = max(ans, mid);
            start = mid + 1;
        }
        else if (ar[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return (ans == INT_MIN) ? -1 : ans;
}

vector<int> solution(vector<int> &ar, int key)
{
    int ans1 = left_index(ar, key);
    int ans2 = right_index(ar, key);
    vector<int> res;
    res.push_back(ans1);
    res.push_back(ans2);
    return res;
}

int main()
{
    int n, temp, key;
    cin >> n;
    cin >> key;
    vector<int> ar;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        ar.push_back(temp);
    }
    vector<int> res = solution(ar, key);
    for (auto val : res)
        cout << val << " ";
}