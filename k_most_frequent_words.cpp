#include <bits/stdc++.h>
using namespace std;

vector<string> kMostFrequent(vector<string> ar, int k)
{
    vector<string> res;
    map<string, int> mp;
    multimap<int, string, greater<int>> map;
    for (auto val : ar)
    {
        mp[val]++;
    }
    for (auto val : mp)
    {
        map.insert(make_pair(val.second, val.first));
    }
    int i = 0;
    for (auto it = map.begin(); i < k; it++, i++)
    {
        res.push_back(it->second);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    string temp;
    vector<string> ar;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        ar.push_back(temp);
    }
    vector<string> ans = kMostFrequent(ar, k);
    for (auto val : ans)
        cout << val << " ";
}