#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int, int> &p1, const pair<int, int> &p2)
{
    return p1.second > p2.second;
}

vector<int> topKFrequent(vector<int> &nums, int k)
{
    map<int, int> mp;
    for (auto val : nums)
        mp[val]++;
    vector<int> res;
    vector<pair<int, int>> temp;
    for (auto val : mp)
        temp.push_back(make_pair(val.first, val.second));
    sort(temp.begin(), temp.end(), cmp);
    int cnt = 0;
    for (auto val : temp)
    {
        if (cnt < k)
        {
            res.push_back(val.first);
            cnt++;
        }
        else
            break;
    }
    //cout<<val.first<<"  "<<val.second<<endl;
    return res.empty() ? nums : res;
}

int main()
{
    int n, k, temp;
    cin >> n >> k;
    vector<int> ar;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        ar.push_back(temp);
    }
    vector<int> ans = topKFrequent(ar, k);
    for (auto val : ans)
        cout << val << " ";
}