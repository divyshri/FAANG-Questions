#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> ar)
{
    unordered_map<int, bool> mp;
    for (int i = 0; i < ar.size(); i++)
    {
        if (mp.find(ar[i]) == mp.end())
            mp[ar[i]] = true;
        else
            return true;
    }
    return false;
}

int main()
{
    int n, temp;
    cin >> n;
    vector<int> ar;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        ar.push_back(temp);
    }
    if (check(ar))
        cout << "true";
    else
        cout << "false";
}
