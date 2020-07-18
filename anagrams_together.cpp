#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string temp;
    map<string, vector<string>> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        string t = temp;
        sort(t.begin(), t.end());
        mp[t].push_back(temp);
    }
    for (auto val : mp)
    {
        for (auto x : val.second)
            cout << x << " ";
        cout << endl;
    }
}